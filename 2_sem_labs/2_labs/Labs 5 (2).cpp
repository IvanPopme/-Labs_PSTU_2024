#include <iostream>
using namespace std;
int main()
{
    setlocale(LC_ALL, "RU");
    const int STR = 3; // Количество строк
    const int STOLB = 3; // Количество столбцов
    // Пример матрицы
    int arr[STR][STOLB] =
    {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    // Поиск седловых точек
    for (int i = 0; i < STR; ++i)
    {
        // Находим минимальный элемент в строке
        int minInSTR = arr[i][0];
        int stolbIndex = 0;
        for (int j = 1; j < STOLB; ++j)
        {
            if (arr[i][j] < minInSTR)
            {
                minInSTR = arr[i][j];
                stolbIndex = j;
            }
        }

        // Проверяем, является ли этот элемент максимальным в своём столбце
        bool isSedlToch = true;
        for (int k = 0; k < STR; ++k)
        {
            if (arr[k][stolbIndex] > minInSTR)
            {
                isSedlToch = false;
                break;
            }
        }

        // Если это седловая точка, выводим её
        if (isSedlToch)
        {
            cout << "Седловая точка: " << minInSTR << " на позиции (" << i << ", " << stolbIndex << ")" << endl;
        }

        // Находим максимальный элемент в строке
        int maxInSTR = arr[i][0];
        stolbIndex = 0;
        for (int j = 1; j < STOLB; ++j)
        {
            if (arr[i][j] > maxInSTR)
            {
                maxInSTR = arr[i][j];
                stolbIndex = j;
            }
        }

        // Проверяем, является ли этот элемент минимальным в своём столбце
        bool isSaddle = true;
        for (int k = 0; k < STR; ++k)
        {
            if (arr[k][stolbIndex] < maxInSTR)
            {
                isSaddle = false;
                break;
            }
        }

        // Если это седловая точка, выводим её
        if (isSaddle)
        {
            cout << "Седловая точка: " << maxInSTR << " на позиции (" << i << ", " << stolbIndex << ")" << endl;
        }
    }

    return 0;
}