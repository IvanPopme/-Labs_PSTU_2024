#pragma once
#include <iostream>
using namespace std;

class Money
{
    long rubles;
    int kopecks;
public:
    Money() { rubles = 0; kopecks = 0; }
    Money(long r, int k) { rubles = r; kopecks = k; normalize(); }
    Money(const Money& m) { rubles = m.rubles; kopecks = m.kopecks; }
    ~Money() {};

    long get_rubles() { return rubles; }
    int get_kopecks() { return kopecks; }
    void set_rubles(long r) { rubles = r; }
    void set_kopecks(int k) { kopecks = k; normalize(); }

    // Нормализация копеек (если больше 99)
    void normalize() 
    {
        rubles += kopecks / 100;
        kopecks = kopecks % 100;
        if (kopecks < 0) 
        {
            rubles--;
            kopecks += 100;
        }
    }

    // Перегруженные операции
    Money& operator=(const Money&);
    Money operator+(const Money&);
    Money operator-(const Money&);

    // Глобальные функции ввода-вывода
    friend istream& operator>>(istream& in, Money& m);
    friend ostream& operator<<(ostream& out, const Money& m);
};
