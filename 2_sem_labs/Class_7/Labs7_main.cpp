#include <iostream>

#include "Set.h"
#include "Money.h"

int main() {
    setlocale(LC_ALL, "RU");

    // Тестирование класса Money
    Money m1(10, 50);
    Money m2(5, 75);
    Money m3 = m1 + m2;
    cout << "Сумма m1: " << m1 << endl;
    cout << "Сумма m2: " << m2 << endl;
    cout << "Сумма (m1 + m2): " << m3 << endl;

    // Тестирование класса Set с int
    Set<int> intSet(3);
    cout << "Введите 3 целых числа для intSet: ";
    cin >> intSet;
    cout << "intSet: " << intSet << endl;

    // Тестирование класса Set с Money
    Set<Money> moneySet(2);
    cout << "Введите 2 денежные суммы (формат: рубли,копейки): ";
    cin >> moneySet;
    cout << "moneySet: " << moneySet << endl;

    // Объединение множеств
    Set<int> intSet2(2, 5);
    Set<int> intSet3 = intSet + intSet2;
    cout << "Объединение intSet и intSet2: " << intSet3 << endl;

    return 0;
}
