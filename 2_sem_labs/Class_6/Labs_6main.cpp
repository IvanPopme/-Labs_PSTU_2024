#include <iostream>
#include "Set.h"
int main() {
    setlocale(LC_ALL, "RU");
    Set a(5); // Создали множество из 5 элементов, заполненное нулями
    cout << "Введите 5 элементов множества a: ";
    cin >> a;
    cout << "Множество a: " << a << endl;

    a[2] = 100; // Присвоили новое значение элементу
    cout << "Множество a после изменения: " << a << endl;

    Set b(3); // Создали множество b из 3 элементов, заполненное нулями
    cout << "Введите 3 элемента множества b: ";
    cin >> b;
    cout << "Множество b: " << b << endl;

    Set c = a + b; // Объединили множества a и b
    cout << "Объединение a и b: " << c << endl;

    cout << "Размер множества a: " << a() << endl;

    // Тестирование итератора
    SetIterator it = a.first();
   cout << "Первый элемент a: " << *it << endl;
    ++it;
    cout << "Второй элемент a: " << *it << endl;

    cout << "Все элементы a с помощью итератора: ";
    for (it = a.first(); it != a.last(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    return 0;
}
