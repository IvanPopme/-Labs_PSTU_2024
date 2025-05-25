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
    
    void insert(const T& value) {
        s.insert(value);
    }
    
    void print() const {
        for (const auto& item : s) {
            cout << item << " ";
        }
        cout << endl;
    }
    
    void add_max_to_begin() {
        if (s.empty()) return;
        T max_val = *max_element(s.begin(), s.end());
        s.insert(max_val); // В set элементы уникальны, просто добавим максимальный
    }
    
    void remove_min() {
        if (s.empty()) return;
        s.erase(*min_element(s.begin(), s.end()));
    }
    
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
  setlocale (LC_ALL,"RU");
    try {
        MySet<double> s;
        int n;
        cout << "Введите количество элементов:";
        cin >> n;
        
        for (int i = 0; i < n; i++) {
            double val = (rand() % 1000) / 10.0;
            s.insert(val);
        }
        
        cout << "Оригинальный набор: ";
        s.print();
        
        s.add_max_to_begin();
        cout << "После добавления максимального: ";
        s.print();
        
        s.remove_min();
        cout << "После удаления мин: ";
        s.print();
        
        s.add_average_to_each();
        cout << "После добавления среднего значения к каждому: ";
        s.print();
    }
    catch (...) {
        cout << "Произошла ошибка!" << endl;
    }
    return 0;
}
