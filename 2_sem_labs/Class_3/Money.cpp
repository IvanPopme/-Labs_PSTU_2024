#include "Money.h"
#include <iostream>
using namespace std;

Money& Money::operator=(const Money& m)
{
    if (&m == this) return *this;
    rubles = m.rubles;
    kopecks = m.kopecks;
    return *this;
}

Money Money::operator+(const Money& m)
{
    Money result;
    result.rubles = rubles + m.rubles;
    result.kopecks = kopecks + m.kopecks;
    result.normalize();
    return result;
}

Money Money::operator-(const Money& m)
{
    Money result;
    result.rubles = rubles - m.rubles;
    result.kopecks = kopecks - m.kopecks;
    result.normalize();
    return result;
}

istream& operator>>(istream& in, Money& m)
{
    cout << "Rubles: "; in >> m.rubles;
    cout << "Kopecks: "; in >> m.kopecks;
    m.normalize();
    return in;
}

ostream& operator<<(ostream& out, const Money& m)
{
    return (out << m.rubles << "," << (m.kopecks < 10 ? "0" : "") << m.kopecks);
}
