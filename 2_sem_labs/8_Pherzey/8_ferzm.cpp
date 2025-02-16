#include <iostream>
using namespace std;

const int N = 8; // ������ ��������� �����
// ������� ��� ��������, ��������� �� ���������� ����� �� �����
bool isSafe(int board[N][N], int row, int col)
{
    // �������� ������ �����
    for (int i = 0; i < col; i++)
    {

        if (board[row][i])
        {
            return false;
        }
    }
    // �������� ������� ��������� �����
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
    {
        if (board[i][j])
        {
            return false;
        }
    }

    // �������� ������ ��������� �����
    for (int i = row, j = col; j >= 0 && i < N; i++, j--)
    {
        if (board[i][j])
        {
            return false;
        }
    }
    return true;


}

// ����������� ������� ��� ���������� ������
bool solveNQUtil(int board[N][N], int col)
{
    // ���� ��� ����� ���������, ���������� true
    if (col >= N)
    {
        return true;
    }
    // ������� ���������� ����� � ������ ������ �������� �������
    for (int i = 0; i < N; i++)
    {
        if (isSafe(board, i, col))
        {
            // ��������� �����
            board[i][col] = 1;

            // ���������� ��������� ��������� ������
            if (solveNQUtil(board, col + 1))
            {
                return true;
            }
            // ���� ���������� �� �������� � �������, �������� ���
            board[i][col] = 0;
        }
    }

    // ���� ����� �� ����� ���� �������� � ���� �������, ���������� false
    return false;
}

// ������� ��� ������ �����
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

// �������� �������
int main()
{
    setlocale(LC_ALL, "RU");
    int board[N][N] = { 0 }; // ������������� �����

    if (solveNQUtil(board, 0))
    {
        cout << "������� �������:" << endl;
        printBoard(board);
    }
    else
    {
        cout << "������� �� �������." << endl;
    }

    return 0;
}