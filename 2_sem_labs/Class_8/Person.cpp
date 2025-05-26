#include "Person.h"

Person::Person() {
    name = "";
    age = 0;
}

Person::Person(string n, int a) {
    name = n;
    age = a;
}

Person::Person(const Person& p) {
    name = p.name;
    age = p.age;
}

void Person::Input() {
    cout << "Введите имя: ";
    cin >> name;
    cout << "Введите возраст: ";
    cin >> age;
}

void Person::Show() {
    cout << "Имя: " << name << ", Возраст: " << age << endl;
}

void Person::SetName(string n) { name = n; }
void Person::SetAge(int a) { age = a; }
string Person::GetName() { return name; }
int Person::GetAge() 
{
  return age;
}
