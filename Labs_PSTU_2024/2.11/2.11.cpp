#include <iostream>
using namespace std;
int main()
{
    setlocale(LC_ALL, "RU");
    int n, tmp;
    bool positive = false; // flag 1
    bool negative = false; //flag 2
    cout << "������� ����� ������������������:" << endl;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> tmp;
        if (!positive && !negative)
        {
            if (tmp > 0) 
            { 
                positive = true;
            }
            else if (tmp < 0) 
            { 
                negative = true; 
            }
        }
    }
    if (positive)
    {
        cout << "������� ����� ������������� �����";
    }
    else if (negative)
    {
        cout << "������� ����� ������������� �����";
    }
    else
    {
        cout << "��� �������� ���� ��������";
    }
    cout << endl;
    return 0;
}