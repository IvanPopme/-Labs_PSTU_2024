#include "Object.h"
#include "Pair.h"
#include "Long.h"
#include "Vector.h"
#include <iostream>
using namespace std;

int main()
{
  Setlocale (LC_ALL, "RU");
    Vector v(5);
    
    Pair a;
    cout << "Enter pair numbers:\n";
    cin >> a;
    
    Long b;
    cout << "Enter long number (senior and junior parts):\n";
    cin >> b;
    
    Long c(5, 75);
    Long d(3, 50);
    
    Object* p = &a;
    v.Add(p);
    
    p = &b;
    v.Add(p);
    
    cout << "\nVector contents:\n";
    cout << v;
    
    cout << "\nOperations with Long numbers:\n";
    Long sum = b + c;
    cout << "Sum: " << sum;
    
    Long diff = b - d;
    cout << "Difference: " << diff;
    
    Long prod = c * d;
    cout << "Product: " << prod;
    
    return 0;
}
