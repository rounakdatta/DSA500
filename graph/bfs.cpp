// breadth-first search
#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <iterator>
#include <queue>
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

        void visitLevelwise(int currNode, bool *visited, queue <int> &tube) {
            visited[currNode] = true;
            tube.push(currNode);

            while (!tube.empty()) {

                currNode = tube.front();
                tube.pop();
                cout << currNode << " ";

                for (int &p: connections[currNode]) {
                    if (!visited[p]) {
                        visited[p] = true;
                        tube.push(p);
                    }
                }
                cout << endl;
            }

        }

        void BFS(int startNode) {
            bool *visited = new bool[n];

            // none are visited initially
            for (int i = 0; i < n; i++) {
                visited[i] = false;
            }

            queue <int> tube;

            visitLevelwise(startNode, visited, tube);
        }
};

int main() {
    
    Graph simple(5);
    simple.addEdge(0, 3);
    simple.addEdge(0, 1);
    simple.addEdge(1, 2);
    simple.addEdge(1, 3);
    simple.addEdge(1, 1);
    simple.addEdge(2, 0);
    simple.addEdge(2, 3);
    simple.addEdge(3, 1);
    simple.addEdge(3, 3);
    simple.addEdge(2, 4);

    simple.BFS(0);

    return 0;

}