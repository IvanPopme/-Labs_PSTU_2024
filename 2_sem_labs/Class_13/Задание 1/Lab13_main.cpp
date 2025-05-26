#include "Money.h"
#include <vector>
#include <algorithm>
#include <iostream>
#include <stack>

using namespace std;

typedef vector<Money> TVector;
Money s; // Глобальная переменная для сравнения

// Формирование вектора
TVector make_vector(int n) {
    Money a;
    TVector v;
    for (int i = 0; i < n; i++) {
        cin >> a;
        v.push_back(a);
    }
    return v;
}

// Печать вектора
void print_vector(const TVector& v) {
    for (const auto& money : v) {
        cout << money << endl;
    }
    cout << endl;
}

// Вычисление среднего арифметического
Money srednee(const TVector& v) {
    Money sum = v[0];
    for (size_t i = 1; i < v.size(); i++) {
        sum = sum + v[i];
    }
    return sum / v.size();
}

// Предикат для сравнения с заданным значением
struct Greater_s {
    bool operator()(const Money& t) {
        return t > s;
    }
};

// Предикат для поиска заданного значения
struct Equal_s {
    bool operator()(const Money& t) {
        return t == s;
    }
};

// Функция для добавления среднего арифметического
void add_srednee(Money& t) {
    t = t + s;
}

int main() {
    setlocale(LC_ALL, "RU");

    int n;
    cout << "Введите количество элементов: ";
    cin >> n;

    // Задача 1: Вектор
    cout << "\n===== Задача 1: Вектор =====" << endl;
    TVector v = make_vector(n);
    cout << "\nИсходный вектор:" << endl;
    print_vector(v);

    // Задание 3: Найти максимальный элемент и добавить его в начало контейнера
    auto max_it = max_element(v.begin(), v.end());
    cout << "Максимальный элемент: " << *max_it << endl;
    v.insert(v.begin(), *max_it);
    cout << "\nПосле добавления максимального элемента в начало:" << endl;
    print_vector(v);

    // Задание 4: Найти минимальный элемент и удалить его из контейнера
    auto min_it = min_element(v.begin(), v.end());
    cout << "Минимальный элемент: " << *min_it << endl;
    v.erase(min_it);
    cout << "\nПосле удаления минимального элемента:" << endl;
    print_vector(v);

    // Задание 5: К каждому элементу добавить среднее арифметическое контейнера
    s = srednee(v);
    cout << "Среднее арифметическое: " << s << endl;
    for_each(v.begin(), v.end(), add_srednee);
    cout << "\nПосле добавления среднего арифметического к каждому элементу:" << endl;
    print_vector(v);

    // Задача 2: Стек (адаптер контейнера)
    cout << "\n===== Задача 2: Стек =====" << endl;
    stack<Money, TVector> stk(v);
    cout << "Содержимое стека:" << endl;
    while (!stk.empty()) {
        cout << stk.top() << endl;
        stk.pop();
    }

    // Задача 3: Множество с дубликатами (multiset)
    cout << "\n===== Задача 3: Множество с дубликатами =====" << endl;
    TVector v_copy = v;
    sort(v_copy.begin(), v_copy.end());
    cout << "Отсортированный вектор для множества:" << endl;
    print_vector(v_copy);

    return 0;
}
