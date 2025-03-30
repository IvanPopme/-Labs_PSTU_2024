#include <iostream>
using namespace std;

// Функция min с переменным числом аргументов
int min(int first, ...)
{
    int* ptr = &first; // Указатель на первый аргумент
    int min_val = first;

    while (*(++ptr))   // Пока не встретим 0 (завершающий ноль)
    {
        if (*ptr < min_val)
        {
            min_val = *ptr;
        }
    }
    return min_val;
}

int main()
{
  // Вызовы функции min (последний аргумент всегда 0!)
    setlocale(LC_ALL, "RU");
    cout << "Минимальное из 5 чисел: " << min(10, 3, 7, 2, 8, 0) << endl;
    cout << "Минимальное из 10 чисел: " << min(15, 4, 9, 12, 6, 8, 1, 5, 11, 7, 0) << endl;
    cout << "Минимальное из 12 чисел: " << min(20, 14, 9, 18, 3, 16, 5, 12, 8, 10, 7, 15, 0) << endl;

    return 0;
}
