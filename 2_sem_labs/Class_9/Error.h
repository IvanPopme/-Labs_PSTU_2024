#include <iostream>
using namespace std;

class SetError {
public:
    virtual void what() = 0;
};

class IndexError : public SetError {
protected:
    string msg;
public:
    IndexError() { msg = "Ошибка индекса\n"; }
    void what() override { cout << msg; }
};

class SizeError : public SetError {
protected:
    string msg;
public:
    SizeError() { msg = "Ошибка в размере\n"; }
    void what() override { cout << msg; }
};

class MaxSizeError : public SizeError {
public:
    MaxSizeError() { msg += "Превышен максимальный размер\n"; }
};

class EmptySetError : public SizeError {
public:
    EmptySetError() { msg += "Набор пуст\n"; }
};

class ElementExistsError : public SetError {
public:
    void what() override { cout << "Элемент уже существует\n"; }
};
