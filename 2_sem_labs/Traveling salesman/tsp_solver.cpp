#include "tsp_solver.h"
#include <algorithm>
using namespace std;

TSPSolver::TSPSolver(const vector<vector<int>>& costMatrix)  : cost(costMatrix), n(costMatrix.size()), bestCost(numeric_limits<int>::max()) {}

int TSPSolver::solve(vector<int>& bestPath) {
    vector<int> path;
    vector<bool> visited(n, false);
    path.push_back(0); // начинаем с города 0
    visited[0] = true;
    branchAndBound(path, visited, 0, 1);
    bestPath = bestRoute;
    return bestCost;
}

void TSPSolver::branchAndBound(vector<int>& path, vector<bool>& visited, int currentCost, int level) {
    if (level == n) {
        int lastToFirst = cost[path.back()][path[0]];
        if (lastToFirst == -1) return; // нет пути обратно
        int totalCost = currentCost + lastToFirst;
        if (totalCost < bestCost) {
            bestCost = totalCost;
            bestRoute = path;
            bestRoute.push_back(path[0]);
        }
        return;
    }

    for (int i = 0; i < n; ++i) {
        if (!visited[i] && cost[path.back()][i] != -1) {
            visited[i] = true;
            path.push_back(i);
            branchAndBound(path, visited, currentCost + cost[path[path.size() - 2]][i], level + 1);
            path.pop_back();
            visited[i] = false;
        }
    }
}
