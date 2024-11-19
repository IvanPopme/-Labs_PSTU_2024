#include <iostream>
using namespace std;
int main()
{
    int N;
    int i = 0;
    int sum = 0;
    cin >> N;
    while (i <= N)
    {
        sum += i;
        i++;
    }
    cout << sum << endl;
    return 0;
}