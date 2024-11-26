#include <iostream>
using namespace std;
int main() {
    int n, fac = 1;
    int* ptr = &fac;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        *ptr *= i;
    }
    cout << fac << endl;
    return 0;
}
