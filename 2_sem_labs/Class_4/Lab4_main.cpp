#include <iostream>
#include "PAIR.h"
#include "LONG.h"

int main() {
    setlocale(LC_ALL, "RU");
    // Тестирование базового класса
    PAIR p1(1, 2), p2(3, 4);
    PAIR p3 = p1 + p2;
    std::cout << "Сумма пар: " << p3 << std::endl;

    // Тестирование производного класса
    LONG l1(5, 75), l2(3, 50);

    LONG l3 = l1 + l2;
    LONG l4 = l1 - l2;
    LONG l5 = l1 * l2;

    std::cout << "Сумма длинных чисел: " << l3 << std::endl;
    std::cout << "Разность длинных чисел: " << l4 << std::endl;
    std::cout << "Произведение длинных чисел: " << l5 << std::endl;

    return 0;
}
