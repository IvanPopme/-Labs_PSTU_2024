#include "Person.h"
#include <iostream>

Person::Person(void) {
    name = "";
    age = 0;
}

Person::~Person(void) {}

Person::Person(string n, int a) {
    name = n;
    age = a;
}

Person::Person(const Person& p) {
    name = p.name;
    age = p.age;
}

void Person::Show() {
    cout << "\nNAME: " << name;
    cout << "\nAGE: " << age;
    cout << "\n";
}

void Person::Input() {
    cout << "\nName: "; cin >> name;
    cout << "Age: "; cin >> age;
}

void Person::Set_name(string n) {
    name = n;
}

void Person::Set_age(int a) {
    age = a;
}

Person& Person::operator=(const Person& p) {
    if (&p == this) return *this;
    name = p.name;
    age = p.age;
    return *this;
}

void Person::HandleEvent(const TEvent& e) {
    if (e.what == evMessage) {
        switch (e.command) {
            case cmShowOne:
                cout << "Name: " << Get_name() << endl;
                break;
        }
    }
}
