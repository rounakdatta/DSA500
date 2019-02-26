// depth-first search
#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <iterator>
using namespace std;

class Graph {
    int n;
    vector <int> *connections;

    public:

        Graph(int nodeCount) {
            this->n = nodeCount;
            connections = new vector <int>[nodeCount];
        }

        void addEdge(int startNode, int endNode) {
            connections[startNode].push_back(endNode);
        }

        void printAdjacencyMatrix() {         
            for (int i = 0; i < n; i++) {
                cout << i << " -> ";
                for (int &j: connections[i]) {
                    cout << j << " ";
                }
                cout << endl;
            }
        }

        void visitThemRecursively(int startNode, bool *visited) {
            visited[startNode] = true;
            cout << startNode << " ";

            for (int &p: connections[startNode]) {
                if (!visited[p]) {
                    visitThemRecursively(p, visited);
                }
            }
        }

        void DFS(int startNode) {
            bool *visited = new bool[n];

            // none are visited initially
            for (int i = 0; i < n; i++) {
                visited[i] = false;
            }

            visitThemRecursively(startNode, visited);
        }
};

int main() {
    
    Graph simple(4);
    simple.addEdge(0, 3);
    simple.addEdge(0, 1);
    simple.addEdge(1, 2);
    simple.addEdge(1, 3);
    simple.addEdge(1, 1);
    simple.addEdge(2, 0);
    simple.addEdge(2, 3);
    simple.addEdge(3, 1);
    simple.addEdge(3, 3);

    simple.printAdjacencyMatrix();
    simple.DFS(1);

    return 0;

}