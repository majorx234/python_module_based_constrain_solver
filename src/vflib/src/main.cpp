#include <fstream>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
// #include <unistd.h>
#include "argedit.hpp"
#include "argloader.hpp"
#include "argraph.hpp"
#include "match.hpp"
#include "nodeclassifier.hpp"
#include "nodesorter.hpp"
#include "probability_strategy.hpp"
#include <time.h>

#include "vf3.hpp"

#define TIME_LIMIT 1

#define PRINT_SORTING 0
#define PRINT_SOLUTION 0
#define PRINT_NUM_STATES 0

int main(int argc, char **argv) {

  char *pattern, *target;

  visitor_data_t vis_data;
  // state_counter = 0;
  int n = 0;
  // int sols = 0;
  int rep = 0;
  double timeAll = 0;
  double timeFirst = 0;
  // unsigned long firstSolTicks = 0;
  // unsigned long endTicks = 0;
  unsigned long ticks = 0;
  unsigned long ticksFirst = 0;
  float limit = TIME_LIMIT;

  if (argc < 3) {
    std::cout << "Usage: vf3 [pattern] [target] [minimim execution time] \n";
    return -1;
  }

  pattern = argv[1];
  target = argv[2];

  if (argc == 4) {
    limit = atof(argv[3]);
  }

  std::ifstream graphInPat(pattern);
  std::ifstream graphInTarg(target);

  StreamARGLoader<data_t, Empty> pattloader(graphInPat);
  StreamARGLoader<data_t, Empty> targloader(graphInTarg);

  ARGraph<data_t, Empty> patt_graph(&pattloader);
  ARGraph<data_t, Empty> targ_graph(&targloader);

  int nodes1, nodes2;
  nodes1 = patt_graph.NodeCount();
  nodes2 = targ_graph.NodeCount();
  node_id *n1, *n2;
  n1 = new node_id[nodes1];
  n2 = new node_id[nodes2];

  NodeClassifier<data_t, Empty> classifier(&targ_graph);
  NodeClassifier<data_t, Empty> classifier2(&patt_graph, classifier);
  std::vector<int> class_patt = classifier2.GetClasses();
  std::vector<int> class_targ = classifier.GetClasses();

  ticks = clock();
  do {
    rep++;
    vis_data.solutions = 0;
    vis_data.first_solution_time = 0;
    ticksFirst = clock();
    VF3NodeSorter<data_t, Empty, SubIsoNodeProbability<data_t, Empty>> sorter(
        &targ_graph);
    std::vector<node_id> sorted = sorter.SortNodes(&patt_graph);
#if (defined PRINT_SORTING) && PRINT_SORTING
    if (rep == 1) {
      std::cout << sorted.size() << "\n";
      for (unsigned int i = 0; i < sorted.size(); i++) {
        std::cout << sorted[i] << " ";
      }
    }
#endif

    SUBSTATE_CLASS<data_t, data_t, Empty, Empty> s0(
        &patt_graph, &targ_graph, class_patt.data(), class_targ.data(),
        classifier.CountClasses(), sorted.data() PARAMETER_K_IF_NEEDED);
    match<SUBSTATE_CLASS<data_t, data_t, Empty, Empty>>(s0, &n, n1, n2, visitor,
                                                        &vis_data);
    timeFirst =
        ((double)(vis_data.first_solution_time - ticksFirst) / CLOCKS_PER_SEC);
  } while (clock() - ticks < CLOCKS_PER_SEC * limit);
  timeAll = ((double)(clock() - ticks) / CLOCKS_PER_SEC / rep);
  if (vis_data.solutions <= 0) {
    timeFirst = timeAll;
  } else {
    timeFirst /= rep;
  }
  // Print number of solutions, time for all solutions, time for first solution.
  std::cout << vis_data.solutions << " " << timeAll << " " << timeFirst
            << std::endl;

  return 0;
}
