#include <iostream>
#include <string>
using namespace std;

int main()
{
    setlocale(LC_ALL, "RU");
    string input;
    cout << "Введите строку: ";
    getline(cin, input);

    string alphabet;
    string number;

    // Разделяем символы на буквы и цифры
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

    // Соединяем буквы и цифры
    string result = alphabet + number;

    cout << "Результат: " << result << endl;

    return 0;
}