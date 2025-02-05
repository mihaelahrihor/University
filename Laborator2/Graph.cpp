#include "Graph.h"
#include <fstream>
#include <iostream>

using namespace std;

Graph::Graph(){

    // deschidem fisierul data.in
    ifstream f;
    f.open("data.in");
    // citim nr de linii respectiv coloane
    f >> n;
    f >> m;
    // citim fiecare pereche de noduri din fisier
    int x,y;
    for(int i=0; i<m; i++){
        f>>x>>y;    // nodurile care definesc o muchie in graf
        addEdge(x,y);   // se aplica metoda addEdge pt a adauga muchia in graf
    }

}

void Graph::addEdge(int x, int y){
    matrix[x][y] = 1;
    matrix[y][x] = 1;
}

bool Graph::isEdge(int x, int y){
    return matrix[x][y] == 1;
}

void Graph::printGraph(){
    for (int i=0; i<n; i++){    // n - nr de noduri (matrice patratica)
        for(int j=0; j<n; j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
}

int Graph::max_and_min() {
    int max, min, final_max = 0, final_min = n;
    for (int i=0; i<n; i++){
        max = 0;
        min = n;
        for (int j=0; j<n; j++){
            if (matrix[i][j] == 1){
                max ++;
            }
            if (matrix[i][j] == 0){
                min --;
            }
        }
        if (final_max <= max){
            final_max = max;
        }
        if (final_min >= min){
            final_min = min;
        }
    }
    std::cout << "Grad maxim: " << final_max << std::endl;
    std::cout << "Grad minim: " << final_min << std::endl;
}

std::vector<std::vector<int>> Graph::Adjlist()  {
    std::vector<std::vector<int>> adjacencyList(n);
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if (matrix[i][j] == 1){
                adjacencyList[i].push_back(j);
            }
        }
    }
    return adjacencyList;
}