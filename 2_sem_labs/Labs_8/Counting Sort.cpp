#include <iostream>
using namespace std;

int* countingSort(int arr[], int size)
{
    if (size == 0)
    {
        return arr;
    }

    // Находим максимальный элемент
    int max = arr[0];
    for (int i = 1; i < size; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }

    // Создаем массив для подсчета и инициализируем нулями
    int* count = new int[max + 1]();

    // Подсчитываем количество каждого элемента
    for (int i = 0; i < size; i++)
    {
        count[arr[i]]++;
    }

    // Вычисляем префиксные суммы (начинаем с 1)
    for (int i = 1; i <= max; i++)
    {
        count[i] += count[i - 1];
    }

    // Создаем временный массив для результата
    int* output = new int[size];

    // Заполняем выходной массив в обратном порядке 
    for (int i = size - 1; i >= 0; i--)
    {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    // Копируем отсортированные данные в исходный массив
    for (int i = 0; i < size; i++)
    {
        arr[i] = output[i];
    }

    // Освобождаем память
    delete[] count;
    delete[] output;

    return arr;
}

int main()
{
    setlocale(LC_ALL, "RU");
    int arr[] = { 4, 2, 2, 8, 3, 3, 1 };
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "Исходный массив: ";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    countingSort(arr, size);

    cout << "Отсортированный массив: ";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
