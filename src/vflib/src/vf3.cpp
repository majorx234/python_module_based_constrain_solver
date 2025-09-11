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

#define TIME_LIMIT 1

#ifndef VF3BIO
typedef int data_t;
#else
typedef std::string data_t;
#endif

#include "vf3_sub_state.hpp"
#define SUBSTATE_CLASS VF3SubState
#define PARAMETER_K_IF_NEEDED

#include "vf3.hpp"

#define PRINT_SORTING 0
#define PRINT_SOLUTION 0
#define PRINT_NUM_STATES 0

void error(std::string msg, ...) {
  va_list ap;
  va_start(ap, msg);
  fprintf(stderr, "ERROR: ");
  vfprintf(stderr, (char *)msg.data(), ap);
  fprintf(stderr, "\n");
  va_end(ap);
  exit(1);
}

template <>
long long SUBSTATE_CLASS<data_t, data_t, Empty, Empty>::instance_count = 0;
// static long long state_counter = 0;

bool visitor(int n, node_id n1[], node_id n2[], void *state, void *usr_data) {
#if (defined PRINT_NUM_STATES) && PRINT_NUM_STATES
  // Print number of traversed states for this solution
  AbstractVFState<int, int, Empty, Empty> *s =
      static_cast<AbstractVFState<int, int, Empty, Empty> *>(state);
  while (s) {
    if (!s->IsUsed()) {
      s->SetUsed();
      state_counter++;
    }
    s = s->GetParent();
  }
#endif

#if (defined PRINT_SOLUTION) && PRINT_SOLUTION
  // Print found solution
  std::cout << "Solution Found:\n";
  for (int k = 0; k < n; k++) {
    if (n1[k] != NULL_NODE)
      std::cout << n2[n1[k]] << "," << n1[k] << ":";
  }
std:
  cout << "\n";
#endif

  // Count solutions and take time of first solution
  visitor_data_t *data = (visitor_data_t *)usr_data;
  data->solutions++;
  if (data->solutions == 1) {
    data->first_solution_time = clock();
  }

  return false;
}
