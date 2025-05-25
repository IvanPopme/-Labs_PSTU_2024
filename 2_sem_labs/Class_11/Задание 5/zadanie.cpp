#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

template<typename T>
class MyStack {
private:
    stack<T> s;
public:
    void push(const T& value) {
        s.push(value);
    }

    void print() const {
        stack<T> temp = s;
        vector<T> v;
        while (!temp.empty()) {
            v.push_back(temp.top());
            temp.pop();
        }
        reverse(v.begin(), v.end());
        for (const auto& item : v) {
            cout << item << " ";
        }
        cout << endl;
    }

    void add_max_to_begin() {
        if (s.empty()) return;

        vector<T> v;
        while (!s.empty()) {
            v.push_back(s.top());
            s.pop();
        }

        T max_val = *max_element(v.begin(), v.end());
        v.insert(v.begin(), max_val);

        for (auto it = v.rbegin(); it != v.rend(); ++it) {
            s.push(*it);
        }
    }

    void remove_min() {
        if (s.empty()) return;

        vector<T> v;
        while (!s.empty()) {
            v.push_back(s.top());
            s.pop();
        }

        auto min_it = min_element(v.begin(), v.end());
        v.erase(min_it);

        for (auto it = v.rbegin(); it != v.rend(); ++it) {
            s.push(*it);
        }
    }

    void add_average_to_each() {
        if (s.empty()) return;

        vector<T> v;
        while (!s.empty()) {
            v.push_back(s.top());
            s.pop();
        }

        T sum = accumulate(v.begin(), v.end(), T());
        T avg = sum / v.size();

        for (auto& item : v) {
            item = item + avg;
        }

        for (auto it = v.rbegin(); it != v.rend(); ++it) {
            s.push(*it);
        }
    }
};

int main() {
    setlocale(LC_ALL, "RU"); 

    try {
        MyStack<double> s;
        int n;
        cout << "Введите количество элементов: ";
        cin >> n;

        for (int i = 0; i < n; i++) {
            double val = (rand() % 1000) / 10.0;
            s.push(val);
        }

        cout << "Исходный стек: ";
        s.print();

        s.add_max_to_begin();
        cout << "После добавления максимума в начало: ";
        s.print();

        s.remove_min();
        cout << "После удаления минимума: ";
        s.print();

        s.add_average_to_each();
        cout << "После добавления среднего к каждому элементу: ";
        s.print();
    }
    catch (...) {
        cout << "Произошла ошибка!" << endl;
    }
    return 0;
}
