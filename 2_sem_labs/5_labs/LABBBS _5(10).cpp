#include <iostream>
using namespace std;
int main()
{
    setlocale(LC_ALL, "RU");
    // ���� ������� �������
    int rows, cols;
    cout << "������� ���������� �����: ";
    cin >> rows;
    cout << "������� ���������� ��������: ";
    cin >> cols;
    // �������� ����������� �������
    int** arr = new int* [rows];
    for (int i = 0; i < rows; i++)
    {
        arr[i] = new int[cols];
    }
    // ���������� ������� ���������� �������
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            arr[i][j] = rand() % 100;
        }
    }
    // ����� ��������� �������
    cout << " �������� ������: " << endl;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << arr[i][j] << "\t";
        }
        cout << endl;
    }
    // ���� ������ ������ ��� ��������  � �� ��������
    int rowtoDelete;
    cout << "������� ����� ������ ��� �������� ( �� 0 �� " << rows - 1 << "): ";
    cin >> rowtoDelete;
    if (rowtoDelete < 0 || rowtoDelete >= rows)
    {
        cout << " ������������ ����� ������! " << endl;
        return 1;
    }

    // �������� ������� � ��������� �������
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

    //����� �������-���������� 

    cout << "������ ����� �������� ������ " << rowtoDelete << ":" << endl;
    for (int i = 0; i < rows - 1; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << newArr[i][j] << "\t";
        }
        cout << endl;
    }

    // �������� ������� �������

    for (int i = 0; i < rows; i++)
    {
        delete[] arr[i];
    }
    delete[] arr;
    return 0;
}