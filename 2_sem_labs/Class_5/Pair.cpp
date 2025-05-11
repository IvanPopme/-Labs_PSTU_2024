#include "Pair.h"

Pair::Pair(void)
{
    first = 0;
    second = 0;
}

Pair::Pair(int f, int s)
{
    first = f;
    second = s;
}

Pair::Pair(const Pair& p)
{
    first = p.first;
    second = p.second;
}

Pair::~Pair(void) {}

void Pair::Show()
{
    cout << "\nFirst: " << first;
    cout << "\nSecond: " << second << endl;
}

Pair Pair::operator+(const Pair& p)
{
    return Pair(first + p.first, second + p.second);
}

istream& operator>>(istream& in, Pair& p)
{
    cout << "\nFirst: "; in >> p.first;
    cout << "Second: "; in >> p.second;
    return in;
}

ostream& operator<<(ostream& out, const Pair& p)
{
    out << "\nFirst: " << p.first;
    out << "\nSecond: " << p.second << endl;
    return out;
}
