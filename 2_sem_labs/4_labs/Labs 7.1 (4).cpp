#include <iostream>
using namespace std;

// Перегруженная функция для вычитания вещественных чисел
double subtract(double a, double b)
{
    return a - b;
}

// Структура для представления комплексного числа
struct Complex
{
    double real;
    double imag;
};

// Перегруженная функция для вычитания комплексных чисел
Complex subtract(const Complex& a, const Complex& b)
{
    Complex result;
    result.real = a.real - b.real;
    result.imag = a.imag - b.imag;
    return result;
}

int main() 
{
    setlocale(LC_ALL, "RU");
    // Вычитание вещественных чисел
    double x = 10.5, y = 3.2;
    cout << "Результат вычитания вещественных чисел: " << subtract(x, y) << endl;

    // Вычитание комплексных чисел
    Complex number1 = { 5.0, 2.0 };
    Complex number2 = { 4.0, 1.0 };
    Complex result = subtract(number1, number2);
    cout << "Результат вычитания комплексных чисел: " << result.real << " + " << result.imag << "i" << endl;

    return 0;
}