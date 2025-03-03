#include <iostream>
using namespace std;

// ������������� ������� ��� ��������� ������������ �����
double subtract(double a, double b)
{
    return a - b;
}

// ��������� ��� ������������� ������������ �����
struct Complex
{
    double real;
    double imag;
};

// ������������� ������� ��� ��������� ����������� �����
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
    // ��������� ������������ �����
    double x = 10.5, y = 3.2;
    cout << "��������� ��������� ������������ �����: " << subtract(x, y) << endl;

    // ��������� ����������� �����
    Complex number1 = { 5.0, 2.0 };
    Complex number2 = { 4.0, 1.0 };
    Complex result = subtract(number1, number2);
    cout << "��������� ��������� ����������� �����: " << result.real << " + " << result.imag << "i" << endl;

    return 0;
}