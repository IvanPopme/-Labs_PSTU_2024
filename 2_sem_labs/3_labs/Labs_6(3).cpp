#include <iostream>
#include <string>
using namespace std;

int main()
{
    setlocale(LC_ALL, "RU");
    string input;
    cout << "������� ������: ";
    getline(cin, input);

    string alphabet;
    string number;

    // ��������� ������� �� ����� � �����
    for (char chik : input)
    {
        if (isalpha(chik))
        {
            alphabet += chik;
        }
        else if (isdigit(chik))
        {
            number += chik;
        }
    }

    // ��������� ����� � �����
    string result = alphabet + number;

    cout << "���������: " << result << endl;

    return 0;
}