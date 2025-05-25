#include "dijkstra.h"

using namespace std;

int main() {
  setlocale (LC_ALL,"RU");
    Graph g(6);

    // Внимание: индексация с 0!
    g.addEdge(0, 2, 3);   // 1 -> 3 (3)
    g.addEdge(0, 5, 11);  // 1 -> 6 (11)
    g.addEdge(1, 0, 8);   // 2 -> 1 (8)
    g.addEdge(1, 3, 13);  // 2 -> 4 (13)
    g.addEdge(2, 1, 7);   // 3 -> 2 (7)
    g.addEdge(2, 5, 18);  // 3 -> 6 (18)
    g.addEdge(3, 4, 33);  // 4 -> 5 (33)
    g.addEdge(4, 5, 5);   // 5 -> 6 (5)
    g.addEdge(5, 3, 14);  // 6 -> 4 (14)

    g.dijkstra(5); // Начинаем с вершины 6 (индекс 5)

    return 0;
}
