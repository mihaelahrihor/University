#include "Graph.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <limits>

Graph::Graph(const std::string& filename) {
    readGraphFromFile(filename);
}

void Graph::readGraphFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error: Unable to open file." << std::endl;
        return;
    }

    file >> numNodes;
    adjMatrix.resize(numNodes, std::vector<int>(numNodes, 0));

    int numEdges;
    file >> numEdges;

    for (int i = 0; i < numEdges; ++i) {
        int node1, node2, weight;
        file >> node1 >> node2 >> weight;
        addEdge(node1, node2, weight);
    }

    file.close();
}

void Graph::addEdge(int node1, int node2, int weight) {
    adjMatrix[node1 - 1][node2 - 1] = weight;
    adjMatrix[node2 - 1][node1 - 1] = weight; // for undirected graph
}


void Graph::bruteForceHamiltonianCycles() {
    std::vector<int> nodes(numNodes); //vector in case se salveaza nodurile
    for (int i = 0; i < numNodes; ++i) {
        nodes[i] = i + 1;
    }

    std::vector<std::vector<int>> allPermutations; //vector in care se salveaza permutarile
    do {
        if (isHamiltonianCycle(nodes)) {
            allPermutations.push_back(nodes);
        }
    } while (std::next_permutation(nodes.begin(), nodes.end()));

    if (allPermutations.empty()) {
        std::cout << "Kein Hamiltonkreis gefunden." << std::endl;
        return;
    }


    std::cout << "Alle moglichen Hamiltonkreise und deren Kosten:" << std::endl;
    for (const auto& permutation : allPermutations) {
        int cost = calculateCycleCost(permutation);
        for (int i = 0; i < permutation.size(); ++i) {
            std::cout << permutation[i];
            if (i < permutation.size() - 1) {
                std::cout << " -> ";
            }
        }
        std::cout << " (Cost: " << cost << ")" << std::endl;
    }
}

bool Graph::isHamiltonianCycle(const std::vector<int>& nodes) const {

    if (nodes.size() != numNodes) {
        return false;
    }

    for (int i = 0; i < nodes.size() - 1; ++i) {
        if (adjMatrix[nodes[i] - 1][nodes[i + 1] - 1] == 0) {
            return false; // nu exista muchie
        }
    }


    if (adjMatrix[nodes.back() - 1][nodes.front() - 1] == 0) {
        return false;
    }

    return true;
}

int Graph::calculateCycleCost(const std::vector<int>& nodes) const {

    int cost = 0;
    for (int i = 0; i < nodes.size() - 1; ++i) {
        cost += adjMatrix[nodes[i] - 1][nodes[i + 1] - 1];
    }
    cost += adjMatrix[nodes.back() - 1][nodes.front() - 1];
    return cost;
}

void Graph::nearestNeighborHeuristic() {
    //
}