#include "Student.h"
#include "Event.h"

Student::Student() : Person() {
    rating = 0.0;
}

Student::Student(string n, int a, float r) : Person(n, a) {
    rating = r;
}

Student::Student(const Student& s) {
    name = s.name;
    age = s.age;
    rating = s.rating;
}

void Student::Input() {
    Person::Input();
    cout << "Введите рейтинг: ";
    cin >> rating;
}

void Student::Show() {
    Person::Show();
    cout << "Рейтинг: " << rating << endl;
}

void Student::HandleEvent(const TEvent& e) {
    if (e.what == evMessage) {
        switch (e.command) {
            case cmGet:
                cout << "Имя студента: " << GetName() << endl;
                break;
        }
    }
}
