// Stanley Fung
// Used to deal with vertices and their properties, which include edge weights, identifying the vertex and helping determine the shortest path. 
#ifndef vertices_h
#define vertices_h

#include <queue>
#include <vector>
#include <limits>

//Vertex class use to keep track of vertices and their information
struct Vertex{
    int ID;
    float distance;
    bool visited;
    Vertex* path;
    //Paramterized constructor for the vertex class
    Vertex(const int id, const float length=std::numeric_limits<float>::max(), const bool known = false)
    {
        ID = id;
        distance = length;
        visited = known;
        path = this;
    }
    //nested class used to compare the distance between two vertices.
    struct ComparingVertices{
        bool operator()(const Vertex *lhs, const Vertex *rhs) const{
            return lhs->distance >= rhs->distance;
        }
    };
    std::priority_queue<Vertex*, std::vector<Vertex*>, ComparingVertices> adjacent_vertices_;
};

#endif /* vertices_h */
