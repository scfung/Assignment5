//
//  vertices.h
//  Assignment5
//
//  Created by Stanley Fung on 12/7/22.
//

#ifndef vertices_h
#define vertices_h

#include <queue>
#include <vector>
#include <limits>

struct Vertex{
    int ID;
    float distance;
    bool visited;
    Vertex* path;
    
    Vertex(const int id, const float length=std::numeric_limits<float>::max(), const bool known = false)
    {
        ID = id;
        distance = length;
        visited = known;
        path = this;
    }
    struct ComparingVertices{
        bool operator()(const Vertex *lhs, const Vertex *rhs) const{
            return lhs->distance >= rhs->distance;
        }
    };
    std::priority_queue<Vertex*, std::vector<Vertex*>, ComparingVertices> adjacent_vertices_;
};

#endif /* vertices_h */
