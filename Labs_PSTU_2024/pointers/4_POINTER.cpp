#include <iostream>
using namespace std;
int main()
{
    int n, tmp, * ptr = &tmp, max, min;
    cin >> n;
    cin >> *ptr;
    max = *ptr;
    min = *ptr;
    for (int i = 1; i <= n; i++)
    {
        cin >> *ptr;
        if (*ptr > max)
        {
            max = *ptr;
        }
        else if (*ptr < min)
        {
            min = *ptr;
        }
        cout << "Min: " << min << endl;
        cout << "Max: " << max << endl;
    }
    return 0;
}