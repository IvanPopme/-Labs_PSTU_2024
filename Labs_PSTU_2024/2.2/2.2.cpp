#include <iostream>
using namespace std;
int main()
{
    int N;
    int i = 1;
    int mu = 1;
    cin >> N;
    while (i <= N)
    {
        mu *= i;
        i++;
    }
    cout << mu << endl;
    return 0;
}