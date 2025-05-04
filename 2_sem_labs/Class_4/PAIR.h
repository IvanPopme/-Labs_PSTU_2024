#pragma once
#include <iostream>
using namespace std;

class PAIR {
protected:
    int first;
    int second;

public:
    PAIR();
    PAIR(int f, int s);
    PAIR(const PAIR& p);

    int GetFirst() const;
    int GetSecond() const;
    void SetFirst(int f);
    void SetSecond(int s);

    PAIR operator+(const PAIR& p) const;

    friend std::istream& operator>>(std::istream& in, PAIR& p);
    friend std::ostream& operator<<(std::ostream& out, const PAIR& p);
};

