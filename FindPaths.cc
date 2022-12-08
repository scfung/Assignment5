//Stanley Fung
//Program tests if the functions that uses Dijkstra’s Algorithm to find the shortest path from a starting vertex to all vertices, is implemented correctly.

#include <iostream>
#include <vector>
#include <string>

#include "graph.h"

using namespace std;

//Driver for finding shortest path via Dijkstra's algorithm.
int pathfindDriver(int argc, char **argv) {
    
    // Begin your code here. Feel free to add any helper functions or classes you need,
    // as long as we only have to call this function to run the specified assignment.
    Graph new_graph;
    std::string graph_file = argv[1];
    std::string vertex_input = argv[2];
    float starting_vertexID = stoi(vertex_input);
    
    new_graph.ParseVertices(graph_file);
    new_graph.ShortestPath(starting_vertexID);
    
    return 0;
}

int main(int argc, char **argv) {
    if (argc != 3) {
        cout << "Usage: " << argv[0] << " <GRAPH_FILE>" << "<STARTING_VERTEX>" << endl;
        return 0;
    }

    pathfindDriver(argc, argv);

    return 0;
}
