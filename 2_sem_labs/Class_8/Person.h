#pragma once
#include "Object.h"

class Person : public Object {
protected:
    string name;
    int age;
public:
    Person();
    virtual ~Person() {}
    virtual void Show();
    virtual void Input();
    Person(string, int);
    Person(const Person&);
    void SetName(string);
    void SetAge(int);
    string GetName();
    int GetAge();
};
