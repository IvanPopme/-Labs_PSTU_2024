#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#include <vector>
#include <utility>

class Graph {
public:
    Graph(int vertices);
    void addEdge(int from, int to, int weight);
    void dijkstra(int start);
private:
    int vertices;
    std::vector<std::vector<std::pair<int, int>>> adjList;
};

#endif // DIJKSTRA_H
