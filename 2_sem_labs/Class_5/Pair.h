#pragma once
#include "Object.h"
#include <iostream>
using namespace std;

class Pair : public Object
{
protected:
    int first;
    int second;
public:
    Pair(void);
    Pair(int, int);
    Pair(const Pair&);
    virtual ~Pair(void);
    
    void Show() override;
    
    int GetFirst() { return first; }
    int GetSecond() { return second; }
    void SetFirst(int f) { first = f; }
    void SetSecond(int s) { second = s; }
    
    Pair operator+(const Pair&);
    friend istream& operator>>(istream& in, Pair& p);
    friend ostream& operator<<(ostream& out, const Pair& p);
};
