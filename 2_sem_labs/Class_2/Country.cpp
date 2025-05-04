#include "Contry.h"
#include <iostream>
#include <string>
using namespace std;

// Конструктор без параметров
Country::Country()
{
    capital = "";
    population = 0;
    area = 0;
    cout << "Constructor bez parametrov dlia objecta " << this << endl;
}

// Конструктор с параметрами
Country::Country(string C, int P, double A)
{
    capital = C;
    population = P;
    area = A;
    cout << "Constructor s parametrami dlia objecta " << this << endl;
}

// Конструктор копирования
Country::Country(const Country& c)
{
    capital = c.capital;
    population = c.population;
    area = c.area;
    cout << "Constructor copirovania dlia objecta " << this << endl;
}

// Деструктор
Country::~Country()
{
    cout << "Destructor dlia objecta " << this << endl;
}

// Селекторы
string Country::get_capital()
{
    return capital;
}

int Country::get_population()
{
    return population;
}

double Country::get_area()
{
    return area;
}

// Модификаторы
void Country::set_capital(string C)
{
    capital = C;
}

void Country::set_population(int P)
{
    population = P;
}

void Country::set_area(double A)
{
    area = A;
}

// Метод для просмотра атрибутов
void Country::show()
{
    cout << "Stolitsa: " << capital << endl;
    cout << "Kolichestvo zhitelei: " << population << endl;
    cout << "Ploshchad: " << area << endl;
}
