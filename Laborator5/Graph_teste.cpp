
#include "Graph.h"
#include <iostream>
#include <fstream>

int main() {
    // Testen der Konstruktor- und Leseoperationen
    Graph graph("graph_data.txt");

    // Testen der Brute-Force-Methode für Hamiltonkreise
    std::cout << "Teste Brute-Force-Methode fur Hamiltonkreise:" << std::endl;
    graph.bruteForceHamiltonianCycles();

    // Testen der nächstgelegenen Nachbarn Heuristik
    std::cout << "Teste nachstgelegene Nachbarn Heuristik:" << std::endl;
    graph.nearestNeighborHeuristic();

   return 0;
}