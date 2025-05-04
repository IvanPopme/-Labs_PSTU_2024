#pragma once
#include "PAIR.h"

class LONG : public PAIR {
public:
    LONG();
    LONG(int high, int low);
    LONG(const LONG& l);

    LONG operator+(const LONG& l) const;
    LONG operator-(const LONG& l) const;
    LONG operator*(const LONG& l) const;
};
