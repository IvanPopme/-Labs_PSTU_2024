#include <iostream>
using namespace std;

class SetIterator;

class Set {
public:
    // Конструктор с параметром: создает множество заданного размера, заполненное нулями
    Set(int size);
    // Конструктор копирования
    Set(const Set& other);
    // Деструктор
    ~Set();
    // Оператор присваивания
    Set& operator=(const Set& other);
    // Операция доступа по индексу
    int& operator[](int index);
    // Операция для определения размера множества
    int operator()();
    // Операция объединения множеств
    Set operator+(const Set& other);
    // Методы для работы с итератором
    SetIterator first();
    SetIterator last();
    // Перегруженные операции ввода-вывода
    friend ostream& operator<<(ostream& out, const Set& s);
    friend istream& operator>>(istream& in, Set& s);

private:
    int size;
    int* data;
};

class SetIterator {
    friend class Set;
public:
    SetIterator() : element(nullptr) {}
    // Перегруженные операции сравнения
    bool operator==(const SetIterator& other) { return element == other.element; }
    bool operator!=(const SetIterator& other) { return element != other.element; }
    // Перегруженная операция инкремента
    void operator++() { ++element; }
    // Перегруженная операция разыменования
    int& operator*() const { return *element; }

private:
    SetIterator(int* el) : element(el) {}
    int* element;
};
