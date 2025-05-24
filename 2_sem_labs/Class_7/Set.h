#include <iostream>

using namespace std;

template <class T>
class Set {
public:
    Set(int size, T defaultValue = T());
    Set(const Set<T>& other);
    ~Set();
    Set<T>& operator=(const Set<T>& other);
    T& operator[](int index);
    int operator()();
    Set<T> operator+(const Set<T>& other);
    friend ostream& operator<< <>(ostream& out, const Set<T>& s);
    friend istream& operator>> <>(istream& in, Set<T>& s);

private:
    int size;
    T* data;
};

template <class T>
Set<T>::Set(int size, T defaultValue) : size(size) {
    data = new T[size];
    for (int i = 0; i < size; ++i) {
        data[i] = defaultValue;
    }
}

template <class T>
Set<T>::Set(const Set<T>& other) : size(other.size) {
    data = new T[size];
    for (int i = 0; i < size; ++i) {
        data[i] = other.data[i];
    }
}

template <class T>
Set<T>::~Set() {
    delete[] data;
    data = nullptr;
}

template <class T>
Set<T>& Set<T>::operator=(const Set<T>& other) {
    if (this != &other) {
        delete[] data;
        size = other.size;
        data = new T[size];
        for (int i = 0; i < size; ++i) {
            data[i] = other.data[i];
        }
    }
    return *this;
}

template <class T>
T& Set<T>::operator[](int index) {
    if (index < size) return data[index];
    else {
        cout << "\nОшибка! Индекс >= размеру";
        exit(1);
    }
}

template <class T>
int Set<T>::operator()() {
    return size;
}

template <class T>
Set<T> Set<T>::operator+(const Set<T>& other) {
    int newSize = size + other.size;
    Set<T> temp(newSize);
    for (int i = 0; i < size; ++i) {
        temp.data[i] = data[i];
    }
    for (int i = 0; i < other.size; ++i) {
        temp.data[size + i] = other.data[i];
    }
    return temp;
}

template <class T>
ostream& operator<<(ostream& out, const Set<T>& s) {
    for (int i = 0; i < s.size; ++i) {
        out << s.data[i] << " ";
    }
    return out;
}

template <class T>
istream& operator>>(istream& in, Set<T>& s) {
    for (int i = 0; i < s.size; ++i) {
        in >> s.data[i];
    }
    return in;
}
