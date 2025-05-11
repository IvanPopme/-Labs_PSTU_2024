#pragma once
#include "Pair.h"

class Long : public Pair
{
public:
    Long(void);
    Long(int, int);
    Long(const Long&);
    ~Long(void);
    
    void Show() override;
    
    Long operator+(const Long&);
    Long operator-(const Long&);
    Long operator*(const Long&);
    friend istream& operator>>(istream& in, Long& l);
    friend ostream& operator<<(ostream& out, const Long& l);
};
