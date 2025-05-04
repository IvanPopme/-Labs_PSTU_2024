#include "PAIR.h"

PAIR::PAIR() : first(0), second(0) {}

PAIR::PAIR(int f, int s) : first(f), second(s) {}

PAIR::PAIR(const PAIR& p) : first(p.first), second(p.second) {}

int PAIR::GetFirst() const { return first; }
int PAIR::GetSecond() const { return second; }

void PAIR::SetFirst(int f) { first = f; }
void PAIR::SetSecond(int s) { second = s; }

PAIR PAIR::operator+(const PAIR& p) const {
    return PAIR(first + p.first, second + p.second);
}

istream& operator>>(istream& in, PAIR& p) {
    std::cout << "Введите первое число: ";
    in >> p.first;
    std::cout << "Введите второе число: ";
    in >> p.second;
    return in;
}

ostream& operator<<(ostream& out, const PAIR& p) {
    out << "(" << p.first << ", " << p.second << ")";
    return out;
}
