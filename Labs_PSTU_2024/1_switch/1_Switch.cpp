#include <iostream>
using namespace std;
int main()
{
    float a,b;
    int s;
    cin >> a >> b;
    cin >> s;
    switch (s)
    {
    case 1:
    {
        cout << a + b << endl;
        break;
    }
    case 2:
    {
        cout << a - b << endl;
        break;
    }
    case 3:
    {
        cout << a * b << endl;
        break;
    }
    case 4:
    {
        cout << a / b << endl;
        break;
    }
    default: cout << "error \n";
    }
    return 0;
}