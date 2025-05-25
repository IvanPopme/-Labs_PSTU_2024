#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

// Функция для создания вектора
vector<double> make_vector(int n) {
    vector<double> v;
    for (int i = 0; i < n; i++) {
        double a = (rand() % 1000) / 10.0; // Генерация случайных чисел от 0.0 до 99.9
        v.push_back(a);
    }
    return v;
}

// Функция для печати вектора
void print_vector(const vector<double>& v) {
    for (const auto& item : v) {
        cout << item << " ";
    }
    cout << endl;
}

// Функция для добавления максимального элемента в начало
void add_max_to_begin(vector<double>& v) {
    if (v.empty()) return;
    double max_val = *max_element(v.begin(), v.end());
    v.insert(v.begin(), max_val);
}

// Функция для удаления минимального элемента
void remove_min(vector<double>& v) {
    if (v.empty()) return;
    auto min_it = min_element(v.begin(), v.end());
    v.erase(min_it);
}

// Функция для добавления среднего арифметического к каждому элементу
void add_average_to_each(vector<double>& v) {
    if (v.empty()) return;
    double avg = accumulate(v.begin(), v.end(), 0.0) / v.size();
    for (auto& item : v) {
        item += avg;
    }
}

int main() {
    setlocale(LC_ALL, "RU");
    try {
        vector<double> v;
        int n;
        cout << "Введите размер вектора: ";
        cin >> n;

        v = make_vector(n);
        cout << "Оригинальный вектор: ";
        print_vector(v);

        // Задание 3: Добавить максимальный элемент в начало
        add_max_to_begin(v);
        cout << "После добавления макс для начала: ";
        print_vector(v);

        // Задание 4: Удалить минимальный элемент
        remove_min(v);
        cout << "После удаления мин: ";
        print_vector(v);

        // Задание 5: Добавить среднее к каждому элементу
        add_average_to_each(v);
        cout << "После добавления среднего значения к каждому: ";
        print_vector(v);
    }
    catch (...) {
        cout << "Произошла ошибка!" << endl;
    }
    return 0;
}
