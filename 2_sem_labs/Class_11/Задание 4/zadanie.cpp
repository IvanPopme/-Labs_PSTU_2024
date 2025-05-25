#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

// Функция для вывода элементов стека
template<typename T>
void print_stack(stack<T> s) {
    vector<T> v;
    // Переносим элементы из стека в вектор для печати
    while (!s.empty()) {
        v.push_back(s.top());
        s.pop();
    }
    // Переворачиваем вектор, так как стек выдает элементы в обратном порядке
    reverse(v.begin(), v.end());
    for (const auto& item : v) {
        cout << item << " ";
    }
    cout << endl;
}

// Добавление максимального элемента в начало стека
template<typename T>
void add_max_to_begin(stack<T>& s) {
    if (s.empty()) return;

    vector<T> v;
    // Переносим элементы в вектор
    while (!s.empty()) {
        v.push_back(s.top());
        s.pop();
    }

    // Находим максимальный элемент
    T max_val = *max_element(v.begin(), v.end());
    // Вставляем его в начало вектора
    v.insert(v.begin(), max_val);

    // Возвращаем элементы обратно в стек
    for (auto it = v.rbegin(); it != v.rend(); ++it) {
        s.push(*it);
    }
}

// Удаление минимального элемента из стека
template<typename T>
void remove_min(stack<T>& s) {
    if (s.empty()) return;

    vector<T> v;
    // Переносим элементы в вектор
    while (!s.empty()) {
        v.push_back(s.top());
        s.pop();
    }

    // Находим и удаляем минимальный элемент
    auto min_it = min_element(v.begin(), v.end());
    v.erase(min_it);

    // Возвращаем элементы обратно в стек
    for (auto it = v.rbegin(); it != v.rend(); ++it) {
        s.push(*it);
    }
}

// Добавление среднего значения ко всем элементам стека
template<typename T>
void add_average_to_each(stack<T>& s) {
    if (s.empty()) return;

    vector<T> v;
    // Переносим элементы в вектор
    while (!s.empty()) {
        v.push_back(s.top());
        s.pop();
    }

    // Вычисляем среднее значение
    T sum = accumulate(v.begin(), v.end(), T());
    T avg = sum / v.size();

    // Добавляем среднее значение к каждому элементу
    for (auto& item : v) {
        item = item + avg;
    }

    // Возвращаем элементы обратно в стек
    for (auto it = v.rbegin(); it != v.rend(); ++it) {
        s.push(*it);
    }
}

int main() {
    setlocale(LC_ALL, "RU");
 

    try {
        stack<double> s;
        int n;
        cout << "Введите количество элементов: ";
        cin >> n;

        // Заполнение стека случайными значениями
        for (int i = 0; i < n; i++) {
            double val = (rand() % 1000) / 10.0;
            s.push(val);
        }

        cout << "Исходный стек: ";
        print_stack(s);

        add_max_to_begin(s);
        cout << "После добавления максимума в начало: ";
        print_stack(s);

        remove_min(s);
        cout << "После удаления минимального элемента: ";
        print_stack(s);

        add_average_to_each(s);
        cout << "После добавления среднего к каждому элементу: ";
        print_stack(s);
    }
    catch (...) {
        cout << "Произошла ошибка!" << endl;
    }
    return 0;
}
