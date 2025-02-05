#include "Graph.h"
#include <fstream>
#include <iostream>
#include <limits>

Graph::Graph(const std::string& filename) {
    std::ifstream inputFile("data.in");
    if (!inputFile) {
        std::cerr << "Error: Unable to open file " << filename << std::endl;
        return;
    }

    int source, destination, weight;
    while (inputFile >> source >> destination >> weight) {
        Edge newEdge = {source, destination, weight};//se creeaza obictul edge
        edgeList.push_back(newEdge);
        numKnoten = std::max(std::max(numKnoten, source), destination)+1;//se actualizeaza nr maxim de noduri
    }

    inputFile.close();
}

void Graph::shortestPath(int knoten1, int knoten2) {
    std::vector<int> dist(numKnoten, std::numeric_limits<int>::max());//initializarea distantelor de la nodul sursa catre restul
    std::vector<int> prev(numKnoten, -1);//initializare predecesori

    dist[knoten1] = 0;

    for (int i = 0; i < numKnoten - 1; ++i) {
        for (const auto& edge : edgeList) {
            int u = edge.source;
            int v = edge.destination;
            int weight = edge.weight;
            if (dist[u] != std::numeric_limits<int>::max() && dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                prev[v] = u;
            }
        }
    }


    for (const auto& edge : edgeList) {
        int u = edge.source;
        int v = edge.destination;
        int weight = edge.weight;
        if (dist[u] != std::numeric_limits<int>::max() && dist[u] + weight < dist[v]) {
            std::cout << "Der Graph enthält einen negativen Zyklus." << std::endl;
            return;
        }
    }


    std::cout << "Kurzester Weg von Knoten " << knoten1 << " zu Knoten " << knoten2 << ": ";
    if (dist[knoten2] == std::numeric_limits<int>::max()) {
        std::cout << "Kein Weg gefunden." << std::endl;
        return;
    }

    int currentVertex = knoten2;
    std::vector<int> path;//nodurile care formeaza cel mai scurt drum
    while (currentVertex != -1) {
        path.push_back(currentVertex);
        currentVertex = prev[currentVertex];
    }

    std::cout << "Distanta: " << dist[knoten2] << ", Drum: ";
    for (size_t i = path.size(); i > 0; --i) {
        std::cout << path[i - 1];
        if (i > 1) {
            std::cout <<"->";
        }
    }
    std::cout << std::endl;
}