# Documentation
## Steps of a computation approach
- Question: When some parts are moving, how are others in the mechanism affected?
![Screenshot](images/mechanism_with_moving_joints.png "")
- maybe the part in the blue dotted cicle is moving, what happens hat the end of the chain?
![Screenshot](images/plain_mechanism.png "")
- there are technical drawing for mechanism
![Screenshot](images/mechanism_as_labeled_graph.png "")
- these can be seen as labeled graph
- there already exist some computation equations for modules (see references)
![Screenshot](images/find_fitting_modules_in_labeled_graph.png "")
- these modules can be found in the graph
![Screenshot](images/find_fitting_modules_in_labeled_graph_ambiguous.png "")
- maybe there are different modules which fitting for same areas so the calculations isn ambiguous
![Screenshot](images/find_fitting_modules_in_labeled_graph_with_backtracking.png "")
- with backtracking the problem can solved by tryout.
- similar to a mace, the algorithm tries to come as far as possible
