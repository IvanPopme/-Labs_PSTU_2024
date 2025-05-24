#include "Money.h"


Money::Money() : rubles(0), kopecks(0) {}

Money::Money(long rubles, int kopecks) : rubles(rubles), kopecks(kopecks) {
    normalize();
}

Money::Money(const Money& other) : rubles(other.rubles), kopecks(other.kopecks) {}

Money& Money::operator=(const Money& other) {
    if (this != &other) {
        rubles = other.rubles;
        kopecks = other.kopecks;
    }
    return *this;
}

Money Money::operator+(const Money& other) const {
    long totalRubles = rubles + other.rubles;
    int totalKopecks = kopecks + other.kopecks;
    Money result(totalRubles, totalKopecks);
    result.normalize();
    return result;
}

void Money::normalize() {
    if (kopecks >= 100 || kopecks <= -100) {
        rubles += kopecks / 100;
        kopecks %= 100;
    }
    if (kopecks < 0 && rubles > 0) {
        rubles--;
        kopecks += 100;
    }
}

ostream& operator<<(ostream& out, const Money& money) {
    out << money.rubles << ",";
    if (money.kopecks < 10) out << "0";
    out << abs(money.kopecks);
    return out;
}

istream& operator>>(istream& in, Money& money) {
    char separator;
    in >> money.rubles >> separator >> money.kopecks;
    money.normalize();
    return in;
}
