#pragma once
#include "Person.h"

class Student : public Person {
public:
    Student(void);
    ~Student(void);
    void Show();
    void Input();
    void HandleEvent(const TEvent& e);
    
    Student(string name, int age, float rating);
    Student(const Student& s);
    
    float Get_rating() { return rating; }
    void Set_rating(float);
    
    Student& operator=(const Student&);
    
protected:
    float rating;
};
