#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

template<class T>
class MySet {
private:
    set<T> s;
public:
    MySet() {}
    MySet(int n) {
        T a;
        for (int i = 0; i < n; i++) {
            cin >> a;
            s.insert(a);
        }
    }
    
    void print() {
        for (auto& el : s) {
            cout << el << " ";
        }
        cout << endl;
    }
    
    T find_max() {
        return *max_element(s.begin(), s.end());
    }
    
    T find_min() {
        return *min_element(s.begin(), s.end());
    }
    
    T calculate_average() {
        T sum = T();
        for (auto& el : s) {
            sum = sum + el;
        }
        return sum / s.size();
    }
    
    void add_to_begin(const T& value) {
        s.insert(value);
    }
    
    void remove_min() {
        s.erase(find_min());
    }
    
    void add_average_to_all() {
        T avg = calculate_average();
        set<T> new_set;
        for (auto& el : s) {
            new_set.insert(el + avg);
        }
        s = new_set;
    }
};

int main() {
  setlocale (LC_ALL,"RU");
    int n;
    cout << "N? "; cin >> n;
    
    MySet<double> s(n);
    s.print();
    
    double max_el = s.find_max();
    s.add_to_begin(max_el);
    cout << "После добавления max для начала:" << endl;
    s.print();
    
    s.remove_min();
    cout << "После удаления мин:" << endl;
    s.print();
    
    s.add_average_to_all();
    cout << "После добавления среднего значения к каждому элементу:" << endl;
    s.print();
    
    return 0;
}
