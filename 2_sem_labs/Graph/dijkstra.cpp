#include "dijkstra.h"
#include <iostream>
#include <queue>
#include <vector>
#include <limits>

using namespace std;

Graph::Graph(int vertices) : vertices(vertices) {
    adjList.resize(vertices);
}

void Graph::addEdge(int from, int to, int weight) {
    adjList[from].push_back({to, weight});
}

void Graph::dijkstra(int start) {
    vector<int> dist(vertices, numeric_limits<int>::max());
    vector<int> prev(vertices, -1);
    dist[start] = 0;

    using pii = pair<int, int>;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, start});

    while (!pq.empty()) {
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (d > dist[u]) continue;

        for (auto &edge : adjList[u]) {
            int v = edge.first;
            int weight = edge.second;
            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                prev[v] = u;
                pq.push({dist[v], v});
            }
        }
    }

    cout << "Кратчайшие расстояния от вершины " << start + 1 << ":\n";
    for (int i = 0; i < vertices; ++i) {
        cout << "До вершины " << i + 1 << ": ";
        if (dist[i] == numeric_limits<int>::max())
            cout << "нет пути\n";
        else
            cout << dist[i] << "\n";
    }
}
