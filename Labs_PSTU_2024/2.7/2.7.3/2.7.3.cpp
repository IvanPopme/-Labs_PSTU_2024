#include <iostream>
using namespace std;
int main()
{
    int N;
    cin >> N;
    if (N <= 2)
    {
        cout << "number > 2\n";
    }
    for (int j = 0; j <= N; j++)
    {
        cout << "* ";
    }
    cout << endl;
    for (int i = 0; i <= N - 2; i++)
    {
        cout << "* ";
        for (int j = 0; j <= N - 2; j++)
        {
            cout << "  ";
        }
        cout << "* ";
        cout << endl;
    }
    for (int j = 0; j <= N; j++)
    {
        cout << "* ";
    }
    cout << endl;
    return 0;
}

