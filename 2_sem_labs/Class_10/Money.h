#pragma once
#include <iostream>
#include <fstream>
using namespace std;

class Money {
private:
    long rubles;
    int kopecks;

    void normalize() {
        if (kopecks >= 100) {
            rubles += kopecks / 100;
            kopecks %= 100;
        }
        else if (kopecks < 0) {
            rubles -= (-kopecks / 100) + 1;
            kopecks = 100 - (-kopecks % 100);
        }
    }

public:
    Money() : rubles(0), kopecks(0) {}
    Money(long r, int k) : rubles(r), kopecks(k) { normalize(); }

    // Операции сложения и вычитания
    Money operator+(const Money& other) const {
        return Money(rubles + other.rubles, kopecks + other.kopecks);
    }

    Money operator-(const Money& other) const {
        return Money(rubles - other.rubles, kopecks - other.kopecks);
    }

    // Операции сравнения
    bool operator==(const Money& other) const {
        return rubles == other.rubles && kopecks == other.kopecks;
    }

    bool operator!=(const Money& other) const {
        return !(*this == other);
    }

    // Увеличение на 1 рубль 50 копеек
    Money& increase() {
        rubles += 1;
        kopecks += 50;
        normalize();
        return *this;
    }

    // Ввод/вывод
    friend ostream& operator<<(ostream& os, const Money& m);
    friend istream& operator>>(istream& is, Money& m);

    // Для работы с файлами
    friend fstream& operator<<(fstream& ofs, const Money& m);
    friend fstream& operator>>(fstream& ifs, Money& m);
};
