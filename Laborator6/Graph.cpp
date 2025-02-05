#include "graph.h"

Graph::Graph(const std::string& filename) {
    std::ifstream inputFile(filename);
    if (!inputFile) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return;
    }

    inputFile >> numNodes;
    int numEdges;
    inputFile >> numEdges;

    for (int i = 0; i < numEdges; ++i) {
        int node1, node2;
        inputFile >> node1 >> node2;
        edges.emplace_back(node1, node2);
    }

    inputFile.close();
}

void Graph::printGraph() {
    std::cout << "Number of nodes: " << numNodes << std::endl;
    std::cout << "Edges:" << std::endl;
    for (int i = 0; i < edges.size(); ++i) {
        std::cout << edges[i].node1 << " " << edges[i].node2 << std::endl;
    }
}

void Graph::kantenzug() {
    if (!isCircuit()) {
        std::cout << "Kein Eulerkreis vorhanden!" << std::endl;
        return;
    }

    std::vector<bool> visited(edges.size(), false);
    std::stack<int> circuit;

    // Start DFS from node 0
    DFS(0, visited, circuit);


    while (!circuit.empty()) {
        std::cout << circuit.top() << " ";
        circuit.pop();
    }
    std::cout << std::endl;
}

bool Graph::isCircuit() {
    std::vector<int> visited(numNodes, 0);
    for (int i = 0; i < edges.size(); ++i) {
        visited[edges[i].node1]++;
        visited[edges[i].node2]++;
    }

    for (int i = 0; i < numNodes; ++i) {
        if (visited[i] % 2 != 0)
            return false;
    }

    return true;
}

void Graph::DFS(int startNode, std::vector<bool>& visited, std::stack<int>& circuit) {
    std::stack<int> s;
    s.push(startNode);

    while (!s.empty()) {
        int currentNode = s.top();
        bool found = false;

        for (int i = 0; i < edges.size(); ++i) {
            if (edges[i].node1 == currentNode && !visited[i]) {
                visited[i] = true;
                s.push(edges[i].node2);
                found = true;
                break;
            } else if (edges[i].node2 == currentNode && !visited[i]) {
                visited[i] = true;
                s.push(edges[i].node1);
                found = true;
                break;
            }
        }

        if (!found) {
            circuit.push(currentNode);
            s.pop();
        }
    }
}
