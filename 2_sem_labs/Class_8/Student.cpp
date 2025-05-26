#include "Student.h"
#include <iostream>

Student::Student(void) : Person() {
    rating = 0;
}

Student::~Student(void) {}

Student::Student(string n, int a, float r) : Person(n, a) {
    rating = r;
}

Student::Student(const Student& s) : Person(s) {
    rating = s.rating;
}

void Student::Show() {
    Person::Show();
    cout << "RATING: " << rating << "\n";
}

void Student::Input() {
    Person::Input();
    cout << "Rating: "; cin >> rating;
}

void Student::Set_rating(float r) {
    rating = r;
}

Student& Student::operator=(const Student& s) {
    if (&s == this) return *this;
    name = s.name;
    age = s.age;
    rating = s.rating;
    return *this;
}

void Student::HandleEvent(const TEvent& e) {
    Person::HandleEvent(e);
}
