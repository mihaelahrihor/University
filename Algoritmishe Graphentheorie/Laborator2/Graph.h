#include <vector>
#include <iostream>

class Graph {
private:

    int n;  // nr linii

    int m;  // nr coloane

    int matrix[100][100];   // matricea de adiacenta a grafului

public:

    Graph();    // metoda constructor

    void addEdge(int x, int y);     // metoda adauga muchie intre x si y

    bool isEdge(int x, int y);      // metoda verifica daca exista muchie intre x si y

    void printGraph();  // metoda afiseaza matricea de adiacenta a grafului

    int max_and_min();

    // metoda toAdjacencyList returneaza o lista de adiacenta sub forma de vector de vectori inttegi
    std::vector<std::vector<int>> Adjlist();

};