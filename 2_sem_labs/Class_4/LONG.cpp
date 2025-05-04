#include "LONG.h"

LONG::LONG() : PAIR() {}
LONG::LONG(int high, int low) : PAIR(high, low) {}
LONG::LONG(const LONG& l) : PAIR(l) {}

LONG LONG::operator+(const LONG& l) const {
    int new_high = first + l.first;
    int new_low = second + l.second;
    if (new_low >= 100) {
        new_high += new_low / 100;
        new_low %= 100;
    }
    return LONG(new_high, new_low);
}

LONG LONG::operator-(const LONG& l) const {
    int new_high = first - l.first;
    int new_low = second - l.second;
    if (new_low < 0) {
        new_high -= 1;
        new_low += 100;
    }
    return LONG(new_high, new_low);
}

LONG LONG::operator*(const LONG& l) const {
    int total = (first * 100 + second) * (l.first * 100 + l.second);
    return LONG(total / 10000, (total / 100) % 100);
}
