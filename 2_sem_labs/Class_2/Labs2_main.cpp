#include "Contry.h"
#include <iostream>
#include <string>
using namespace std;

// Функция для возврата объекта как результата
Country make_country()
{
    string s;
    int i;
    double d;
    cout << "Vvedite stolitsu: ";
    cin >> s;
    cout << "Vvedite kolichestvo zhitelei: ";
    cin >> i;
    cout << "Vvedite ploshchad: ";
    cin >> d;
    Country c(s, i, d);
    return c;
}

// Функция для передачи объекта как параметра
void print_country(Country c)
{
    c.show();
}

int main()
{
    // Конструктор без параметров
    Country c1;
    c1.show();

    // Конструктор с параметрами
    Country c2("Moscow", 12000000, 2561.5);
    c2.show();

    // Конструктор копирования
    Country c3 = c2;
    c3.set_capital("London");
    c3.set_population(8900000);
    c3.set_area(1572.0);

    // Конструктор копирования
    print_country(c3);

    // Конструктор копирования
    c1 = make_country();
    c1.show();

    return 0;
}
