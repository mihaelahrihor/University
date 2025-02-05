#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <fstream>
#include <vector>
#include <stack>
#include <algorithm>

struct Edge {
    int node1;
    int node2;
    Edge(int n1, int n2) : node1(n1), node2(n2) {}
};

class Graph {
private:
    int numNodes;
    std::vector<Edge> edges;

public:
    Graph(const std::string& filename);
    void printGraph();
    void kantenzug();
    bool isCircuit();
    void DFS(int node, std::vector<bool>& visited, std::stack<int>& circuit);
};

#endif // GRAPH_H
