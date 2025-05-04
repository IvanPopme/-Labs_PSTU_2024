#include "Money.h"
#include <iostream>
using namespace std;

int main()
{
    Money a;  // конструктор без параметров
    Money b;  // конструктор без параметров
    Money c;  // конструктор без параметров

    cin >> a;  // ввод первой суммы
    cin >> b;  // ввод второй суммы

    c = a + b;  // сложение сумм
    cout << "Sum: " << c << endl;

    c = a - b;  // вычитание сумм
    cout << "Difference: " << c << endl;

    return 0;
}
