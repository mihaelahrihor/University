#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <string>

struct Edge {
    int source;
    int destination;
    int weight;
};

class Graph {
private:
    std::vector<Edge> edgeList;
    int numKnoten;

public:

    Graph(const std::string& filename);

    void shortestPath(int knoten1, int knoten2);
};

#endif