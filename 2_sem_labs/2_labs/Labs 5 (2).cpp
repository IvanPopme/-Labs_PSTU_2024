#include <iostream>
using namespace std;
int main()
{
    setlocale(LC_ALL, "RU");
    const int STR = 3; // ���������� �����
    const int STOLB = 3; // ���������� ��������
    // ������ �������
    int arr[STR][STOLB] =
    {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    // ����� �������� �����
    for (int i = 0; i < STR; ++i)
    {
        // ������� ����������� ������� � ������
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

        // ���������, �������� �� ���� ������� ������������ � ���� �������
        bool isSedlToch = true;
        for (int k = 0; k < STR; ++k)
        {
            if (arr[k][stolbIndex] > minInSTR)
            {
                isSedlToch = false;
                break;
            }
        }

        // ���� ��� �������� �����, ������� �
        if (isSedlToch)
        {
            cout << "�������� �����: " << minInSTR << " �� ������� (" << i << ", " << stolbIndex << ")" << endl;
        }

        // ������� ������������ ������� � ������
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

        // ���������, �������� �� ���� ������� ����������� � ���� �������
        bool isSaddle = true;
        for (int k = 0; k < STR; ++k)
        {
            if (arr[k][stolbIndex] < maxInSTR)
            {
                isSaddle = false;
                break;
            }
        }

        // ���� ��� �������� �����, ������� �
        if (isSaddle)
        {
            cout << "�������� �����: " << maxInSTR << " �� ������� (" << i << ", " << stolbIndex << ")" << endl;
        }
    }

    return 0;
}