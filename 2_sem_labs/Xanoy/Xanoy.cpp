#include <iostream>
using namespace std;

// Функция для отображения текущего состояния стержней
void displayTowers(int** towers, int n)
{
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            if (towers[i][j] == 0)
            {
                cout << " | ";
            }
            else
            {
                cout << " " << towers[i][j] << " ";
            }
        }
        cout << endl;
    }
    cout << "---------" << endl;

}

// Функция для поиска верхнего диска на стержне
int findTopDisk(int** towers, int n, int tower)
{
    for (int i = 0; i < n; ++i)
    {
        if (towers[i][tower] != 0)
        {
            return i; // Возвращаем индекс верхнего диска
        }
    }
    return n; // Если стержень пуст
}

void moveDisk(int** towers, int n, int from, int to)
{
    // Находим индекс верхнего диска на исходном стержне
    int fromTop = findTopDisk(towers, n, from);

    // Находим индекс верхнего диска на целевом стержне
    int toTop = findTopDisk(towers, n, to);

    // Перемещаем диск с исходного стержня на целевой
    towers[toTop - 1][to] = towers[fromTop][from];

    // Очищаем место на исходном стержне
    towers[fromTop][from] = 0;
}

// Рекурсивная функция для решения Ханойской башни
void hanoi(int n, int** towers, int from, int to, int aux, int diskCount)
{
    // Базовый случай: если дисков нет, завершаем рекурсию
    if (n == 0)
    {
        return;
    }

    // Шаг 1: Перемещаем (n-1) дисков с исходного стержня на вспомогательный
    hanoi(n - 1, towers, from, aux, to, diskCount);

    // Шаг 2: Перемещаем оставшийся диск с исходного стержня на целевой
    moveDisk(towers, diskCount, from, to);

    // Выводим информацию о перемещении и текущее состояние башен
    cout << "Move disk " << n << " from Tower " << from + 1 << " to Tower " << to + 1 << endl;

    displayTowers(towers, diskCount);

    // Шаг 3: Перемещаем (n-1) дисков с вспомогательного стержня на целевой
    hanoi(n - 1, towers, aux, to, from, diskCount);
}

int main() 
{
    setlocale(LC_ALL, "RU");
    int n;
    cout << "Введите Количество Дисков: ";
    cin >> n;

    // Выделение памяти и инициализация
    int** towers = new int* [n];
    for (int i = 0; i < n; ++i)
    {
        towers[i] = new int[3]();
    }

    // Заполнение первого стержня
    for (int i = 0; i < n; ++i)
    {
        towers[i][0] = n - i;
    }
    cout << "Initial state:" << endl;
    displayTowers(towers, n);

    // Решение
    hanoi(n, towers, 0, 2, 1, n);
    return 0;
}



