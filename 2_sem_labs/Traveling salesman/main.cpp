#include <iostream>
#include "tsp_solver.h"
using namespace std;

int main() {
  setlocale (LC_ALL,"RU");
    vector<vector<int>> matrix = {
        { -1,  5, 11,  9 },
        { 10, -1,  8,  7 },
        {  7, 14, -1,  8 },
        { 12,  6, 15, -1 }
    };

    TSPSolver solver(matrix);
    vector<int> bestPath;
    int minCost = solver.solve(bestPath);

    cout << "Минимальный путь: ";
    for (int city : bestPath) {
        cout << city + 1 << " ";
    }
    cout << "\nСтоимость: " << minCost << endl;

    return 0;
}
