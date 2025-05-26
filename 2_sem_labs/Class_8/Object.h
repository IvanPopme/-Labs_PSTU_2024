#pragma once
#include <iostream>
using namespace std;

class Object {
public:
    Object() {}
    virtual ~Object() {}
    virtual void Show() = 0;
    virtual void Input() = 0;
    virtual void HandleEvent(const struct TEvent& e) = 0;
};
