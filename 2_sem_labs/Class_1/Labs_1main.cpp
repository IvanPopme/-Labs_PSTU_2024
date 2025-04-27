#include <iostream>
#include "LinearEquation.h"
using namespace std;

LinearEquation make_equation(double a, double b)
{
    LinearEquation eq;
    eq.Init(a, b);
    return eq;
}

int main() 
{
    LinearEquation eq1;
    eq1.Init(2.0, -4.0);
    eq1.Show();
    cout << "Root: x = " << eq1.root() << endl;

    LinearEquation eq2;
    eq2.Read();
    eq2.Show();
    double root = eq2.root();
    if (!isnan(root)) 
    {
        cout << "Root: x = " << root << endl;
    }

    LinearEquation* pEq = new LinearEquation;
    pEq->Init(3.0, 6.0);
    pEq->Show();
    cout << "Root: x = " << pEq->root() << endl;
    delete pEq;

    LinearEquation equations[2];
    for (int i = 0; i < 2; i++)
    {
        equations[i].Read();
    }
    for (int i = 0; i < 2; i++) 
    {
        equations[i].Show();
        cout << "Root: x = " << equations[i].root() << endl;
    }

    return 0;
}
