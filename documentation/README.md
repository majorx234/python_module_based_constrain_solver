# Documentation
## Steps of a computation approach
- Question: When some parts are moving, how are others in the mechanism affected?
- ![Screenshot](images/mechanism_with_moving_joints.png "")
- maybe the part in the blue dotted circle is moving, what happens hat the end of the chain on the right side?
- there are technical drawing for mechanism
- ![Screenshot](images/plain_mechanism.png "")
- these can be seen as labeled graph
- ![Screenshot](images/mechanism_as_labeled_graph.png "")
- there already exist some equations for computation for modules (see references)
- ![Screenshot](images/find_fitting_modules_in_labeled_graph.png "")
- these modules can be found in the graph
- the pink stars show the possibility for a module
- ![Screenshot](images/find_fitting_modules_in_labeled_graph_ambiguous.png "")
- maybe there are different modules which fitting for same areas so the calculations is ambiguous
- these pink star module with its calculation result can lead to starting point of the next module (cyan star)
- ![Screenshot](images/find_fitting_modules_in_labeled_graph_with_backtracking.png "")
- with backtracking the problem can solved by systematic tryout.
- similar to a mace, the algorithm tries to come as far as possible
