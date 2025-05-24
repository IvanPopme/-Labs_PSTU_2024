#include "Set.h"
#include <iostream>
using namespace std;

int main() {
    setlocale(LC_ALL, "RU");
    try {
        Set a(3);
        cin >> a;
        cout << "Установить: a: " << a << endl;

        Set b(2);
        cin >> b;
        cout << "Установить б: " << b << endl;

        Set c = a + b;
        cout << "Объединение a + b: " << c << endl;

        cout << "Добавление элемента а: ";
        ++a;
        cout << "Установить а: " << a << endl;

        cout << "Элемент с индексом 1: " << a[1] << endl;
        cout << "Размер а: " << a() << endl;

    }
    catch (SetError& e) {
        e.what();
    }
    catch (...) {
        cout << "Произошла неизвестная ошибка" << endl;
    }

    return 0;
}
