#include "Long.h"

Long::Long(void) : Pair() {}

Long::Long(int f, int s) : Pair(f, s) {}

Long::Long(const Long& l) : Pair(l.first, l.second) {}

Long::~Long(void) {}

void Long::Show()
{
    cout << "\nSenior part: " << first;
    cout << "\nJunior part: " << second << endl;
}

Long Long::operator+(const Long& l)
{
    int newFirst = first + l.first;
    int newSecond = second + l.second;
    
    // Handle overflow
    if (newSecond >= 100)
    {
        newFirst += newSecond / 100;
        newSecond %= 100;
    }
    
    return Long(newFirst, newSecond);
}

Long Long::operator-(const Long& l)
{
    int newFirst = first - l.first;
    int newSecond = second - l.second;
    
    // Handle underflow
    if (newSecond < 0)
    {
        newFirst -= 1;
        newSecond += 100;
    }
    
    return Long(newFirst, newSecond);
}

Long Long::operator*(const Long& l)
{
    // Convert to single number for multiplication
    long total1 = first * 100 + second;
    long total2 = l.first * 100 + l.second;
    long result = total1 * total2;
    
    return Long(result / 100, result % 100);
}

istream& operator>>(istream& in, Long& l)
{
    cout << "\nSenior part: "; in >> l.first;
    cout << "Junior part: "; in >> l.second;
    return in;
}

ostream& operator<<(ostream& out, const Long& l)
{
    out << "\nSenior part: " << l.first;
    out << "\nJunior part: " << l.second << endl;
    return out;
}
