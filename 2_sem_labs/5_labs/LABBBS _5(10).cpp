#include <iostream>
using namespace std;
int main()
{
    setlocale(LC_ALL, "RU");
    // ввод размера массива
    int rows, cols;
    cout << "Введите количество строк: ";
    cin >> rows;
    cout << "Введите количество столбцов: ";
    cin >> cols;
    // Создание двухмерного массива
    int** arr = new int* [rows];
    for (int i = 0; i < rows; i++)
    {
        arr[i] = new int[cols];
    }
    // Заполнение массива случайными числами
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            arr[i][j] = rand() % 100;
        }
    }
    // вывод исходного массива
    cout << " Исходный массив: " << endl;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << arr[i][j] << "\t";
        }
        cout << endl;
    }
    // Ввод номера строки для удаления  и ее проверка
    int rowtoDelete;
    cout << "Введите номер строки для удаления ( от 0 до " << rows - 1 << "): ";
    cin >> rowtoDelete;
    if (rowtoDelete < 0 || rowtoDelete >= rows)
    {
        cout << " Некорректный номер строки! " << endl;
        return 1;
    }

    // создание массива с удаленной строкой
    int** newArr = new int* [rows - 1];
    for (int i = 0, c = 0; i < rows; i++)
    {
        if (i != rowtoDelete)
        {
            newArr[c] = new int[cols];
            for (int j = 0; j < cols; j++)
            {
                newArr[c][j] = arr[i][j];
            }
            ++c;
        }
    }

    //вывод массива-результата 

    cout << "Массив после удаления строки " << rowtoDelete << ":" << endl;
    for (int i = 0; i < rows - 1; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << newArr[i][j] << "\t";
        }
        cout << endl;
    }

    // Удаление старого массива

    for (int i = 0; i < rows; i++)
    {
        delete[] arr[i];
    }
    delete[] arr;
    return 0;
}