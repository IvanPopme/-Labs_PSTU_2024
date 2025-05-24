#include "Set.h"

// Конструктор с параметром
Set::Set(int size) : size(size) {
    data = new int[size];
    for (int i = 0; i < size; ++i) {
        data[i] = 0;
    }
}

// Конструктор копирования
Set::Set(const Set& other) : size(other.size) {
    data = new int[size];
    for (int i = 0; i < size; ++i) {
        data[i] = other.data[i];
    }
}

// Деструктор
Set::~Set() {
    delete[] data;
    data = nullptr;
}

// Оператор присваивания
Set& Set::operator=(const Set& other) {
    if (this == &other) return *this;
    delete[] data;
    size = other.size;
    data = new int[size];
    for (int i = 0; i < size; ++i) {
        data[i] = other.data[i];
    }
    return *this;
}

// Операция доступа по индексу
int& Set::operator[](int index) {
    if (index < size) return data[index];
    else {
        cout << "\nError! Index >= size";
        exit(1);
    }
}

// Операция для определения размера множества
int Set::operator()() { return size;}

// Операция объединения множеств
Set Set::operator+(const Set& other) {
    int newSize = size + other.size;
    Set temp(newSize);
    for (int i = 0; i < size; ++i) {
        temp.data[i] = data[i];
    }
    for (int i = 0; i < other.size; ++i) {
        temp.data[size + i] = other.data[i];
    }
    return temp;
}

// Методы для работы с итератором
SetIterator Set::first() {
    return SetIterator(data);
}

SetIterator Set::last() {
    return SetIterator(data + size);
}

// Перегруженные операции ввода-вывода
ostream& operator<<(ostream& out, const Set& s) {
    for (int i = 0; i < s.size; ++i) {
        out << s.data[i] << " ";
    }
    return out;
}

istream& operator>>(istream& in, Set& s) {
    for (int i = 0; i < s.size; ++i) {
        in >> s.data[i];
    }
    return in;
}
