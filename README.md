# Assignment-5-Code

**Functions**

**vertices.h**

-Vertex(const int id, const float length=std::numeric_limits<float>::max(), const bool known = false) - Parameterized constructor to initialize the Vertex values, Vertex used for the graph representation in graph.h

-bool operator()(const Vertex *lhs, const Vertex *rhs) const - function in nested class Comparing vertices to compare the distances

**graph.h**

-std::vector<Vertex*> ParseVertices (const std::string &graph_file) - Takes in a given text file and parse through the file to create vertices with their "ID" and edge weights.

-float TestingConnection (const int vertex1, const int vertex2) - Used to test if there is a connection between two vertices and returns distance. Used as a helper function for TestingQueries().

-void TestingQueries (std::string &query_file) - Tests if the graph implementation via adjacency list, works using Testing Connection and outputs if the vertices are connected and returns the weight of the connection between the two vertices if they are connected. 

-void ShortestPath (int starting_id) - Finds the shortest path from the given vertex to all the other vertices using Dijkstra's algorithm, returns the vertices in the shortest path and the cost of the given path. If there is no path possible, returns not_possible. 

-~Graph()- Destructor to clear dynamically allocated memory used during the program. 

**CreateGraphAndTest.cc**

-int graphTestDriver(int argc, char **argv) - Test driver that contains the ParseVertices function and TestingQueries function to see if the graph was represented correctly in an adjacency list.

**FindPaths.cc**

-int pathfindDriver(int argc, char **argv) - Test driver that contains the ParseVertices function and TestingQueries function to find the shortest path from a starting vertex to all vertices with the cost, using Dijkstra's algorithm. 

**Bugs**

-ShortestPath function did not return the correct output, when the path to certain vertices is not possible.

-ShortestPath function did not return the correct output in the form of a float number, returned cost in an integer instead.  

-Vertices class did not properly work as nested class within graph.h file, used another file name vertices.h and included it into the graph.h file. 

To compile type:

 `make all`

To clean object files and executables type:

 `make clean`
 
To run the create and test graph routine, type:
`./CreateGraphAndTest <GRAPH_FILE> <ADJECENCY_QUERYFILE>`

where `<GRAPH_FILE>` is the file used to create the graph and
`<ADJECENCY_QUERYFILE>` is the file used to check if vertices
are adjacent

Example:
`./CreateGraphAndTest Graph1.txt AdjacencyQueries1.txt`

To run the find paths in graph routine, type:
`./FindPaths <GRAPH_FILE> <STARTING_VERTEX>`

where `<GRAPH_FILE>` is the file used to create the graph and 
`<STARTING_VERTEX>` is the vertex in the graph as the starting
point for the paths

Example:
`./FindPaths Graph2.txt 1`

