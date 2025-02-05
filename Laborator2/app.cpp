#include "Graph.h"
#include<iostream>
#include<fstream>

using namespace std;

int main(){

    Graph g;    // se creeaza un obiect de tip Graph
    cout<<g.isEdge(0,1)<<endl;  // verificam daca exista muchie intre nodurile 0 si 1
    cout<<""<<endl;
    g.printGraph();
    cout<<""<<endl;
    std::vector<std::vector<int>> adjacencyList = g.Adjlist();
    for (int i = 0; i < adjacencyList.size(); i++){
        std::cout << "Node " << i << ": ";
        for (int j = 0; j < adjacencyList.size(); j++){
            std::cout << adjacencyList[i][j] << " ";
        }
        std::cout << std::endl;
    }

    cout<<""<<endl;
    std::cout << g.max_and_min() << std::endl;

    return 0;
}