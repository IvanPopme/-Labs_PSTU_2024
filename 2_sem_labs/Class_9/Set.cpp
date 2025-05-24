#include "Set.h"

Set::Set() : size(0), elements(nullptr) {}

Set::Set(int s, int val) {
    if (s > MAX_SIZE) throw MaxSizeError();
    size = s;
    elements = new int[size];
    for (int i = 0; i < size; i++) {
        elements[i] = val;
    }
}

Set::Set(const Set& s) {
    size = s.size;
    elements = new int[size];
    for (int i = 0; i < size; i++) {
        elements[i] = s.elements[i];
    }
}

Set::~Set() {
    delete[] elements;
}

int Set::operator[](int index) const {
    if (index < 0 || index >= size) throw IndexError();
    return elements[index];
}

int Set::operator()() const {
    return size;
}

Set Set::operator+(const Set& other) const {
    int newSize = size + other.size;
    if (newSize > MAX_SIZE) throw MaxSizeError();

    Set result(newSize);
    int pos = 0;

    for (int i = 0; i < size; i++) {
        result.elements[pos++] = elements[i];
    }

    for (int i = 0; i < other.size; i++) {
        if (!contains(other.elements[i])) {
            result.elements[pos++] = other.elements[i];
        }
    }

    result.size = pos;
    return result;
}

Set& Set::operator++() {
    if (size >= MAX_SIZE) throw MaxSizeError();

    int newElement;
    cout << "Введите новый элемент: ";
    cin >> newElement;

    if (contains(newElement)) throw ElementExistsError();

    int* newElements = new int[size + 1];
    for (int i = 0; i < size; i++) {
        newElements[i] = elements[i];
    }
    newElements[size] = newElement;

    delete[] elements;
    elements = newElements;
    size++;

    return *this;
}

Set Set::operator++(int) {
    Set temp = *this;
    ++(*this);
    return temp;
}

ostream& operator<<(ostream& out, const Set& s) {
    if (s.size == 0) {
        out << "Набор пуст";
    }
    else {
        out << "{ ";
        for (int i = 0; i < s.size; i++) {
            out << s.elements[i] << " ";
        }
        out << "}";
    }
    return out;
}

istream& operator>>(istream& in, Set& s) {
    cout << "Enter " << s.size << " elements: ";
    for (int i = 0; i < s.size; i++) {
        in >> s.elements[i];
    }
    return in;
}

bool Set::contains(int elem) const {
    for (int i = 0; i < size; i++) {
        if (elements[i] == elem) {
            return true;
        }
    }
    return false;
}
