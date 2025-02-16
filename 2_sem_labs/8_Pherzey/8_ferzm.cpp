#include <iostream>
using namespace std;

const int N = 8; // Размер шахматной доски
// Функция для проверки, безопасно ли разместить ферзя на доске
bool isSafe(int board[N][N], int row, int col)
{
    // Проверка строки слева
    for (int i = 0; i < col; i++)
    {

        if (board[row][i])
        {
            return false;
        }
    }
    // Проверка верхней диагонали слева
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
    {
        if (board[i][j])
        {
            return false;
        }
    }

    // Проверка нижней диагонали слева
    for (int i = row, j = col; j >= 0 && i < N; i++, j--)
    {
        if (board[i][j])
        {
            return false;
        }
    }
    return true;


}

// Рекурсивная функция для размещения ферзей
bool solveNQUtil(int board[N][N], int col)
{
    // Если все ферзи размещены, возвращаем true
    if (col >= N)
    {
        return true;
    }
    // Пробуем разместить ферзя в каждой строке текущего столбца
    for (int i = 0; i < N; i++)
    {
        if (isSafe(board, i, col))
        {
            // Размещаем ферзя
            board[i][col] = 1;

            // Рекурсивно размещаем остальных ферзей
            if (solveNQUtil(board, col + 1))
            {
                return true;
            }
            // Если размещение не приводит к решению, отменяем его
            board[i][col] = 0;
        }
    }

    // Если ферзь не может быть размещен в этом столбце, возвращаем false
    return false;
}

// Функция для вывода доски
void printBoard(int board[N][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << (board[i][j] ? "Q " : ". ");
        }
        cout << endl;
    }
}

// Основная функция
int main()
{
    setlocale(LC_ALL, "RU");
    int board[N][N] = { 0 }; // Инициализация доски

    if (solveNQUtil(board, 0))
    {
        cout << "Решение найдено:" << endl;
        printBoard(board);
    }
    else
    {
        cout << "Решение не найдено." << endl;
    }

    return 0;
}
