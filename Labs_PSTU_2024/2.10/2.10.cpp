#include <iostream>
using namespace std;
int main()
{
    setlocale(LC_ALL, "RU");
    int n, tmp, max;
    cout << "Введите длину последовательности:" << endl;
    cin >> n;
    cout << "Введите первое число" << endl;
    cin >> max;
    for (int i = 2; i <= n; i++)
    {
        cout << "Введите следующее число:" << endl;
        cin >> tmp;
        if (tmp > max)
        {
            max = tmp;
        }
    }
    cout << "Максимальное число" << max << endl;
    return 0;
}
