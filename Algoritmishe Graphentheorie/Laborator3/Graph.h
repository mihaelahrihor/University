#include <vector>
#include <string>


class GewichteterGraph {
private:

    int n; //Anzahl Knoten
    int m;  // Anzahl Kanten
    std::vector<std::vector<int>> kostenmatrix;

public:

    GewichteterGraph();

    GewichteterGraph(std::string filename);

    void addEdge(int x, int y, int c);

    bool isEdge(int x, int y);

    int gesamtkosten();

    GewichteterGraph minimalerSpannbaum();

    void BellmanFord(int src);

    void floydWarshall();

    void dijkstraAlgorithm(int startNode);
};