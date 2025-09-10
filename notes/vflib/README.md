# Info
- version 3 of subgraph matcher
- https://mivia.unisa.it/datasets/graph-database/vf3-library/
- https://mivia.unisa.it/datasets/graph-database/vf3-library/vf3-usage/
- problems with build see troubleshooting

## usage
- graph need to be in special format ~adjacency list in a file (`*.grf`)
- cli call via vf3-executable:
  - `./vf3 sub_graph.grf main_graph.grf maximal_time_in_seconds`

## idea to use in python constrain solver
- call via python subprocess run
- or build python binding

## problems
- API needs always time parameter
- someties in bigger graphs the pattern isn't found

## troubleshooting
- error `src/main.cpp:26:10: fatal error: vf3k_sub_state.hpp: No such file or directory`

