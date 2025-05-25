#ifndef TSP_SOLVER_H
#define TSP_SOLVER_H

#include <vector>
#include <limits>
using namespace std;

class TSPSolver {
public:
    TSPSolver(const vector<vector<int>>& costMatrix);
    int solve(vector<int>& bestPath);

private:
    int n;
    vector<vector<int>> cost;
    int bestCost;
    vector<int> bestRoute;

    void branchAndBound(vector<int>& path, vector<bool>& visited, int currentCost, int level);
};

#endif // TSP_SOLVER_H
