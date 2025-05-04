#pragma once
// Описание класса

#include <iostream>  
#include <string>  
using namespace std;

class Country
{
    // Атрибуты  
    string capital;
    int population;
    double area;

public:
    Country(); // Конструктор без параметров  
    Country(string, int, double); // Конструктор с параметрами  
    Country(const Country&); // Конструктор копирования  
    ~Country(); // Деструктор  

    // Методы доступа (селекторы и модификаторы)  
    string get_capital();
    void set_capital(string);
    int get_population();
    void set_population(int);
    double get_area();
    void set_area(double);

    void show(); // Просмотр атрибутов  
};
