#include <iostream>
using namespace std;
int search(int arr[], int n, int x)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == x) return i;
    }
    return -1;
}
int main()
{
    setlocale(LC_ALL, "RU");
    int arr[10] = { 1,56,21,32,65,33,22,12,89,2 };
    int arrLength = sizeof(arr) / sizeof(arr[0]);
    int x = 21;
    int res = search(arr, arrLength, x);
    if (res == -1) cout << "Элемент " << x << " не найден" << endl;
    else cout << "Элемент " << x << " найден по индексу " << res <<
        endl;
    return 0;
}
