#include <iostream>
using namespace std;
int main()
{
    setlocale(LC_ALL, "RU");
    int range_min, range_max;
    int n;
    cin >> n;
    int a[n];
    range_min = 2;
    range_max = 280000;
    for (int i = 0; i < n; i++)
    {
        a[i] = ((double)rand() / RAND_MAX) * (range_max - range_min) + range_min;
        cout << a[i] << " ";
    }
    cout << endl;
    int chislo;
    cin >> chislo;
    for (int i = 0; i < n - 1; i++)
    {
        if (chislo - 1 <= i)
        {
            a[i] = a[i + 1];
        }
    }

    bool num = false;
    for (int i = 0; i < n; i++)
    {
        if (a[i] % 2 == 0)
        {
            num = true;
            for (int j = n; j > i + 1; j--)
            {
                a[j] = a[j - 1];
            }
            a[i + 1] = a[i] + 2;
            n++;
            break;
        }
        cout << a[i] << " ";
    }

    if (!num)
    {
        cout << "В массиве нет четных элементов!" << endl;
    }

    cout << "Итоговый массив: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;

    return 0;
}
