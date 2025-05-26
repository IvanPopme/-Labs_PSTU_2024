#pragma once
#include <iostream>
#include <string>

using namespace std;

class Money {
private:
    long rubles;
    int kopecks;

public:
    Money() : rubles(0), kopecks(0) {}
    Money(long r, int k) : rubles(r), kopecks(k) {
        normalize();
    }

    void normalize() {
        if (kopecks >= 100) {
            rubles += kopecks / 100;
            kopecks %= 100;
        }
        else if (kopecks < 0) {
            rubles -= (-kopecks) / 100 + 1;
            kopecks = 100 - (-kopecks) % 100;
        }
    }

    long getRubles() const { return rubles; }
    int getKopecks() const { return kopecks; }

    Money operator+(const Money& other) const {
        return Money(rubles + other.rubles, kopecks + other.kopecks);
    }

    Money operator-(const Money& other) const {
        return Money(rubles - other.rubles, kopecks - other.kopecks);
    }

    Money operator/(int divisor) const {
        long total = rubles * 100 + kopecks;
        total /= divisor;
        return Money(total / 100, total % 100);
    }

    Money operator*(int multiplier) const {
        long total = rubles * 100 + kopecks;
        total *= multiplier;
        return Money(total / 100, total % 100);
    }

    bool operator>(const Money& other) const {
        if (rubles != other.rubles) return rubles > other.rubles;
        return kopecks > other.kopecks;
    }

    bool operator<(const Money& other) const {
        if (rubles != other.rubles) return rubles < other.rubles;
        return kopecks < other.kopecks;
    }

    bool operator==(const Money& other) const {
        return rubles == other.rubles && kopecks == other.kopecks;
    }

    friend ostream& operator<<(ostream& os, const Money& money) {
        os << money.rubles << " руб. " << money.kopecks << " коп.";
        return os;
    }

    friend istream& operator>>(istream& is, Money& money) {
        cout << "Введите рубли: ";
        is >> money.rubles;
        cout << "Введите копейки: ";
        is >> money.kopecks;
        money.normalize();
        return is;
    }
};
