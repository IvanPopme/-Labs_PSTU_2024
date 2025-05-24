#pragma once
#include "Error.h"
#include <iostream>
using namespace std;

const int MAX_SIZE = 30;

class Set {
    int size;
    int* elements;
public:
    Set();
    Set(int s, int val = 0);
    Set(const Set& s);
    ~Set();

    int operator[](int index) const;
    int operator()() const;
    Set operator+(const Set& other) const;
    Set& operator++(); // Префиксный ++
    Set operator++(int); // Постфиксный ++

    friend ostream& operator<<(ostream& out, const Set& s);
    friend istream& operator>>(istream& in, Set& s);

private:
    bool contains(int elem) const;
};
