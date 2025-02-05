#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <string>

class Graph {
private:
    std::vector<std::vector<int>> adjMatrix;
    int numNodes;

public:
    Graph(const std::string& filename);

    void readGraphFromFile(const std::string& filename);

    void bruteForceHamiltonianCycles();

    int calculateCycleCost(const std::vector<int>& nodes) const;

    bool isHamiltonianCycle(const std::vector<int>& nodes) const;

    void addEdge(int node1, int node2, int weight);



    void nearestNeighborHeuristic();
};

#endif