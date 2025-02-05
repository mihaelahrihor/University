#include "Graph.h"
#include <iostream>

int main() {
    // Testfall 1: Gültiger Graph
    std::cout << "Testfall 1: Gültiger Graph" << std::endl;
    Graph graph1("graph_input.txt");
    graph1.shortestPath(0, 3); // Es gibt einen Weg von Knoten 0 zu Knoten 3
    graph1.shortestPath(1, 2); // Es gibt keinen Weg von Knoten 1 zu Knoten 2

    // Testfall 2: Graph mit negativem Zyklus
    std::cout << "\nTestfall 2: Graph mit negativem Zyklus" << std::endl;
    Graph graph2("graph_with_negative_cycle.txt");
    graph2.shortestPath(0, 3); // Der Graph enthält einen negativen Zyklus

    // Testfall 3: Graph ohne Weg zwischen den Knoten
    std::cout << "\nTestfall 3: Graph ohne Weg zwischen den Knoten" << std::endl;
    Graph graph3("graph_input.txt");
    graph3.shortestPath(0, 4); // Es gibt keinen Weg von Knoten 0 zu Knoten 4

    return 0;
}