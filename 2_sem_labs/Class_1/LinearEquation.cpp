#include <iostream>
#include "LinearEquation.h"
using namespace std;

    void LinearEquation::Init(double a, double b)
    {
        A = a;
        B = b;
    }

void LinearEquation::Read()
{
    cout << "\nEnter coefficient A: ";
    cin >> A;
    cout << "Enter coefficient B: ";
    cin >> B;
}

void LinearEquation::Show()
{
    cout << "\nLinear equation: y = " << A << "x + " << B << endl;
}

double LinearEquation::root()
{
    if (A == 0)
    {
        cout << "Error: Coefficient A cannot be zero!" << endl;
        return NAN; // возвращаем "не число" в случае ошибки
    }
    return -B / A;
}

