#include <iostream>
#include <set>
#include <algorithm>
#include <numeric>
using namespace std;

template<typename T>
class MySet {
private:
    set<T> s;
public:
    MySet() = default;

    // Вставка элемента в множество
    void insert(const T& value) {
        s.insert(value);
    }

    // Вывод элементов множества
    void print() const {
        for (const auto& item : s) {
            cout << item << " ";
        }
        cout << endl;
    }

    // Добавление максимального элемента в начало (в set порядок определяется автоматически)
    void add_max_to_begin() {
        if (s.empty()) return;
        T max_val = *max_element(s.begin(), s.end());
        s.insert(max_val); // В set элементы уникальны, просто добавим максимальный
    }

    // Удаление минимального элемента
    void remove_min() {
        if (s.empty()) return;
        s.erase(*min_element(s.begin(), s.end()));
    }

    // Добавление среднего значения к каждому элементу
    void add_average_to_each() {
        if (s.empty()) return;
        T sum = accumulate(s.begin(), s.end(), T());
        T avg = sum / s.size();

        set<T> new_set;
        for (const auto& item : s) {
            new_set.insert(item + avg);
        }
        s = new_set;
    }
};

int main() {
    
    setlocale(LC_ALL, "RU");
   

    try {
        MySet<double> s;
        int n;
        cout << "Введите количество элементов: ";
        cin >> n;

        // Заполнение множества случайными значениями
        for (int i = 0; i < n; i++) {
            double val = (rand() % 1000) / 10.0;
            s.insert(val);
        }

        cout << "Исходное множество: ";
        s.print();

        s.add_max_to_begin();
        cout << "После добавления максимального элемента: ";
        s.print();

        s.remove_min();
        cout << "После удаления минимального элемента: ";
        s.print();

        s.add_average_to_each();
        cout << "После добавления среднего значения к каждому элементу: ";
        s.print();
    }
    catch (...) {
        cout << "Произошла ошибка!" << endl;
    }
    return 0;
}
