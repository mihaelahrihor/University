#include <iostream>
#include <fstream>

#include "Graph.h"



GewichteterGraph::GewichteterGraph() {}

GewichteterGraph::GewichteterGraph(std::string filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error: Unable to open file " << filename << std::endl;
        return;
    }

    file >> n >> m;
    kostenmatrix.resize(n, std::vector<int>(n, 0));

    int x, y, c;
    for (int i = 0; i < m; ++i) {
        file >> x >> y >> c;
        kostenmatrix[x][y] = kostenmatrix[x][y] = c;
    }
    file.close();
}

void GewichteterGraph::addEdge(int x, int y, int c) {
    if (x >= 0 && x < n && y >= 0 && y < n) {
        kostenmatrix[x][y] = kostenmatrix[y][x] = c;
        m++;
    } else {
        std::cerr << "Error: Invalid edge coordinates" << std::endl;
    }
}

bool GewichteterGraph::isEdge(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < n && kostenmatrix[x][y] != 0;
}

int GewichteterGraph::gesamtkosten() {
    int total_cost = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (kostenmatrix[i][j] != 0) {
                total_cost += kostenmatrix[i][j];
            }
        }
    }
    return total_cost;
}

//DISTANTA  MIN DE LA UN NOD LA CELELALTE NODURI

void GewichteterGraph::BellmanFord(int src) {
    // initializam distantele de la nodul sursa catre restul cu infinit
    std::vector<int> dist(n, INT_MAX);
    dist[src] = 0;
    // parcurgem toate muchiile de n-1 ori
    for (int i = 1; i <= n - 1; ++i) {
        for (int j = 0; j < m; ++j) {
            int u = kostenmatrix[j][0]; // nodul sursa - primul elem de pe linia j
            int v = kostenmatrix[j][1]; // nodul destinatie - al doilea elem
            int weight = kostenmatrix[j][2]; // greutatea muchiei - al treilea
            // daca gasim o distanta mai mica de la u la v o actualizam
            if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
            }
        }
    }
    // parcurgem muchiile si verificam daca exista ponderi negative
    for (int j = 0; j < m; ++j) {
        int u = kostenmatrix[j][0];
        int v = kostenmatrix[j][1];
        int weight = kostenmatrix[j][2];
        // daca dist a fost calc si adaugarea greutatii muchiei ar creea o dist mai mica
        if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
            std::cout << "graful contine un ciclu de ponderi negative" << std::endl;
            return;
        }
    }
    // afisam distantele minime
    std::cout << "Nod\tDist de la nodul sursa" << std::endl;
    for (int i = 0; i < n; ++i) {
        std::cout << i << "\t" << dist[i] << std::endl;
    }
}

void GewichteterGraph::floydWarshall() {
    // creem o copie a matricii unde vom retine distantele minime
    std::vector<std::vector<int>> dist = kostenmatrix;
    // calculam distantele minime folosind 'k' ca si nod intermediar
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (isEdge(i, k) && isEdge(k, j) && (dist[i][k] + dist[k][j] < dist[i][j] || !isEdge(i, j))) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
    // printam distantele minime
    std::cout << "Shortest distances between all pairs of vertices:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (isEdge(i, j))
                std::cout << "inf\t";
            else
                std::cout << dist[i][j] << "\t";
        }
        std::cout << std::endl;
    }
}

void GewichteterGraph::dijkstraAlgorithm(int startNode) {
    std::vector<int> dist(n, INT_MAX); // aici stocam distantele minime initiale
    std::vector<bool> visited(n, false); // cici marcam nodurile vizitate
    dist[startNode] = 0;
    // parcurgem fiecare nod si actualizam distantele minime
    for (int count = 0; count < n - 1; ++count) {
        int minDist = INT_MAX;
        int minNode = -1; // nodul spre care am gasit distanta minima
        // gasim nodul cu cea mai mica distanta minima nevizitat
        for (int v = 0; v < n; ++v) {
            if (!visited[v] && dist[v] < minDist) {
                minDist = dist[v];
                minNode = v;
            }
        }
        visited[minNode] = true;
        // actualizam distantele min catre nodurile adiacente
        for (int v = 0; v < n; ++v) {
            if (!visited[v] && isEdge(minNode, v) &&
                dist[minNode] != INT_MAX &&
                // dist[minNode] -> dist de la nodul de start la minNode
                // kostenmatrix[minNode][v] -> costul muchiei
                // dist[v] -> distanta curenta
                dist[minNode] + kostenmatrix[minNode][v] < dist[v]) {
                dist[v] = dist[minNode] + kostenmatrix[minNode][v];
            }
        }
    }
    // afisam distantele minime de la nodul de start la restul nodurilor
    std::cout << "Distanțe minime de la nodul " << startNode << " la toate celelalte noduri:\n";
    for (int i = 0; i < n; ++i) {
        std::cout << "Nod " << i << ": " << dist[i] << std::endl;
    }
}


