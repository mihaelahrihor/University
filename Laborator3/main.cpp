#include <iostream>
#include <fstream>

#include "Graph.h"


int main() {
    GewichteterGraph graph("graph.txt");
    graph.addEdge(0, 3, 5);
    std::cout << "Gesamtkosten: " << graph.gesamtkosten() << std::endl;

    if (graph.isEdge(0, 1)) {
        std::cout << "Kante zwischen Knoten 0 and 1 existiert" << std::endl;
    } else {
        std::cout << "Kante zwischen Knoten 0 and 1 existoert nicht" << std::endl;
    }

    return 0;
}