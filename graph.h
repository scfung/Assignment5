//Stanley Fung
//Program includes the functions to parse the given text files and to test if the graph is properly represented by an adjacency list. Program also contains a function to find the shortest path from starting vertex to all the vertices, along with a helper function.
#ifndef STUDENT_GRAPH
#define STUDENT_GRAPH

#include "binary_heap.h"
#include "vertices.h"
#include <queue>
#include <vector>
#include <iostream>
#include <list>
#include <map>
#include <fstream>
#include <sstream>
#include <stack>
#include <string>

// This file is for your graph implementation.
// Add everything you need in between the "ifndef and "endif" statements.
// Do not put anything outside those statements

class Graph {
public:
    //Stores the vertices that are encountered in the text file.
    std::vector<Vertex*> vertices_;
    // links vertexID's to the original vertex node that contains them
    std::map<float, Vertex*> vertex_map_;
    // Sorts the vertices based on their distance relative to a starting vertex
    std::priority_queue<Vertex*, std::vector<Vertex*>, Vertex::ComparingVertices> sorted_vertices_;
    // Connects the vertexID's to a list of adjacent vertices
    std::map<int, std::list<Vertex*>> adjacency_list_;
    
    // Takes in a filename and populates all graph class's containers by iterating throught the file.
    std::vector<Vertex*> ParseVertices (const std::string &graph_file) {
        std::ifstream graph_data;
        graph_data.open (graph_file.c_str());
        std::string data_line = "";
        bool skip = true;
        
        while (std::getline (graph_data, data_line)) {
            if (data_line == "" || skip == true)
            { skip = false; continue; }
            std::stringstream insert_data_line (data_line);
            std::vector<std::string> tokens;
            while (std::getline (insert_data_line, data_line, ' '))
                tokens.push_back (data_line);
            int vertexID = std::stoi (tokens[0]);
            Vertex * vertex = new Vertex {vertexID};
            vertices_.push_back (vertex);
            vertex_map_[vertexID] = vertex;
            std::list <Vertex*> adj_list;
            adjacency_list_[vertexID] = adj_list;
        }
        // Resets to allow the adding of the adjacent vertices//
        skip = true; graph_data.clear (); graph_data.seekg (0, graph_data.beg);
        while (getline (graph_data, data_line)) { // split by each line
            if (data_line == "" || skip == true)
            { skip = false; continue; }
            std::stringstream insert_data_line (data_line);
            std::vector<std::string> tokens;
            while (getline (insert_data_line, data_line, ' '))
                tokens.push_back(data_line);
            int id = std::stoi (tokens[0]);
            for (unsigned int i = 0; i < tokens.size(); i++) {
                if (i % 2 == 1) { // vertices fall on the odd indices
                    int adj_vertexID = std::stoi (tokens[i]);
                    float adj_weight = std::stof (tokens[i+1]);
                    Vertex * adj_vertex = new Vertex {adj_vertexID, adj_weight};
                    vertex_map_[id]->adjacent_vertices_.push(adj_vertex);
                    adjacency_list_[id].push_back (adj_vertex);
                }
            }
        }
        graph_data.close ();
        return vertices_;
    }
    
    // Tests if there is a connection between any two vertices, returns distance if there is a connection
    float TestingConnection (const int vertex1, const int vertex2) {
        for (auto vertex : vertices_) {
            if (vertex->ID == vertex1) {
                auto &list = adjacency_list_[vertex->ID];
                for (auto itr = list.begin (); itr != list.end (); itr++) {
                    Vertex *a = *itr;
                    if (a->ID == vertex2)
                        return a->distance;
                }
            }
        }
        return -1.0;
    }
    // Takes in a query filename and tests connections between the first vertex to the second vertex, using TestingConnection
    
    void TestingQueries (std::string &query_file) {
        std::string data_line = "";
        std::ifstream query_data;
        query_data.open (query_file.c_str());
        while (std::getline(query_data, data_line)) {
            std::stringstream insert_data_line (data_line);
            std::vector<std::string> tokens;
            while (std::getline(insert_data_line, data_line, ' '))
                tokens.push_back (data_line);
            int vertex1 = std::stoi (tokens[0]);
            int vertex2 = std::stoi (tokens[1]);
            std::cout << vertex1 << " " << vertex2 << ": ";
            float edge_weight = TestingConnection (vertex1, vertex2);
            if (edge_weight == -1.0)
                std::cout << "not_connected" << std::endl;
            else
                std::cout << "connected " << edge_weight << std::endl;
        }
        query_data.close ();
    }
    
    // Dijkstras algorithm, starting_id is the id of the vertex you are starting, function finds the shortest path to all other nodes from the starting vertex
    void ShortestPath (int starting_id) {
        vertex_map_[starting_id]->distance = 0.0;
        for (auto vertex : vertices_)
            sorted_vertices_.push (vertex);
        while (sorted_vertices_.empty () != true) {
            Vertex *vertex = sorted_vertices_.top ();
            while (vertex->adjacent_vertices_.empty () != true) {
                Vertex *other_vertex = vertex->adjacent_vertices_.top ();
                if (!other_vertex->visited) {
                    float cost = other_vertex->distance;
                    if (vertex_map_[vertex->ID]->distance + cost < vertex_map_[other_vertex->ID]->distance) {
                        vertex_map_[other_vertex->ID]->distance = vertex_map_[vertex->ID]->distance + cost;
                        vertex_map_[other_vertex->ID]->path = vertex;
                    }
                }
                vertex->adjacent_vertices_.pop ();
            }
            sorted_vertices_.pop ();
            vertex_map_[vertex->ID]->visited = true;
        }
        // Prints out path and distance of shortest
        for (auto vertex : vertices_) {
            float cost = vertex_map_[vertex->ID]->distance;
            std::vector<float> pathway;
            pathway.push_back (vertex->ID);
            std::cout << vertex->ID << ": ";
            while (vertex->ID != starting_id) {
                pathway.push_back (vertex->ID);
                vertex = vertex->path; 
            }
            pathway.push_back (starting_id);
            // outputs backwards since we recorded it backwards
                for (size_t i = pathway.size()-1; i > 0; i--)
                {
                    std::cout << pathway[i] << " ";
                }
            cost = cost * 1.0;
            std::cout << "cost: " << cost << std::endl;
        }
    }
    //Destructor to deallocate memory used by the functions. 
    ~Graph()
    {
        for(auto &vertex : vertices_)
            if(vertex != nullptr)
            {
                delete vertex;
                vertex = nullptr;
            }
    }
    
};

#endif
