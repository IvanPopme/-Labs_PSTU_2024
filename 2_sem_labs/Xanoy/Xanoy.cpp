#include <iostream>
using namespace std;

// ������� ��� ����������� �������� ��������� ��������
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

// ������� ��� ������ �������� ����� �� �������
int findTopDisk(int** towers, int n, int tower)
{
    for (int i = 0; i < n; ++i)
    {
        if (towers[i][tower] != 0)
        {
            return i; // ���������� ������ �������� �����
        }
    }
    return n; // ���� �������� ����
}

void moveDisk(int** towers, int n, int from, int to)
{
    // ������� ������ �������� ����� �� �������� �������
    int fromTop = findTopDisk(towers, n, from);

    // ������� ������ �������� ����� �� ������� �������
    int toTop = findTopDisk(towers, n, to);

    // ���������� ���� � ��������� ������� �� �������
    towers[toTop - 1][to] = towers[fromTop][from];

    // ������� ����� �� �������� �������
    towers[fromTop][from] = 0;
}

// ����������� ������� ��� ������� ��������� �����
void hanoi(int n, int** towers, int from, int to, int aux, int diskCount)
{
    // ������� ������: ���� ������ ���, ��������� ��������
    if (n == 0)
    {
        return;
    }

    // ��� 1: ���������� (n-1) ������ � ��������� ������� �� ���������������
    hanoi(n - 1, towers, from, aux, to, diskCount);

    // ��� 2: ���������� ���������� ���� � ��������� ������� �� �������
    moveDisk(towers, diskCount, from, to);

    // ������� ���������� � ����������� � ������� ��������� �����
    cout << "Move disk " << n << " from Tower " << from + 1 << " to Tower " << to + 1 << endl;

    displayTowers(towers, diskCount);

    // ��� 3: ���������� (n-1) ������ � ���������������� ������� �� �������
    hanoi(n - 1, towers, aux, to, from, diskCount);
}

int main() 
{
    setlocale(LC_ALL, "RU");
    int n;
    cout << "������� ���������� ������: ";
    cin >> n;

    // ��������� ������ � �������������
    int** towers = new int* [n];
    for (int i = 0; i < n; ++i)
    {
        towers[i] = new int[3]();
    }

    // ���������� ������� �������
    for (int i = 0; i < n; ++i)
    {
        towers[i][0] = n - i;
    }
    cout << "Initial state:" << endl;
    displayTowers(towers, n);

    // �������
    hanoi(n, towers, 0, 2, 1, n);
    return 0;
}



