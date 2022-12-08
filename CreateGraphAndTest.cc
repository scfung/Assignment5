#include <iostream>
#include <vector>
#include <string>

#include "graph.h"

using namespace std;

int graphTestDriver(int argc, char **argv) {
    
    // Begin your code here. Feel free to add any helper functions or classes you need,
    // as long as we only have to call this function to run the specified assignment.
    std::string graph_file = argv[1];
    std::string adjacent_queries_file = argv[2];
    
    Graph new_graph;
    new_graph.ParseVertices(graph_file);
    new_graph.TestingQueries(adjacent_queries_file);

    return 0;
}


int main(int argc, char **argv) {
    if (argc != 3) {
        cout << "Usage: " << argv[0] << " <GRAPH_File>" << "<ADJACENCY_QUERYFILE>" << endl;
        return 0;
    }

    graphTestDriver(argc, argv);

    return 0;
}
