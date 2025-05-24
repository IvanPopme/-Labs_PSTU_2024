#include <iostream>

using namespace std;

class Money {
public:
    Money();
    Money(long rubles, int kopecks);
    Money(const Money& other);
    ~Money() {}
    Money& operator=(const Money& other);
    Money operator+(const Money& other) const;
    friend ostream& operator<<(ostream& out, const Money& money);
    friend istream& operator>>(istream& in, Money& money);

private:
    long rubles;
    int kopecks;
    void normalize();
};
