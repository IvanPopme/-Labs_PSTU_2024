#include <iostream>
#include <map>
#include <numeric>
using namespace std;

typedef multimap<int, double> TMultiMap;
typedef TMultiMap::iterator it;

// Функция для формирования multimap
TMultiMap make_multimap(int n) {
    TMultiMap m;
    double a;
    for (int i = 0; i < n; i++) {
        cout << "?";
        cin >> a;
        m.insert(make_pair(i, a));
    }
    return m;
}

// Функция для печати multimap
void print_multimap(TMultiMap m) {
    for (auto& el : m) {
        cout << el.first << " : " << el.second << endl;
    }
}

// Нахождение максимального элемента
pair<int, double> find_max(TMultiMap m) {
    auto max_it = max_element(m.begin(), m.end(), 
        [](const pair<int, double>& a, const pair<int, double>& b) {
            return a.second < b.second;
        });
    return *max_it;
}

// Нахождение минимального элемента
pair<int, double> find_min(TMultiMap m) {
    auto min_it = min_element(m.begin(), m.end(), 
        [](const pair<int, double>& a, const pair<int, double>& b) {
            return a.second < b.second;
        });
    return *min_it;
}

// Вычисление среднего арифметического
double calculate_average(TMultiMap m) {
    double sum = 0;
    for (auto& el : m) {
        sum += el.second;
    }
    return sum / m.size();
}

int main() {
  setlocale (LC_ALL,"RU");
    int n;
    cout << "N? "; cin >> n;
    
    // 1. Создание и заполнение контейнера
    TMultiMap m = make_multimap(n);
    print_multimap(m);
    
    // 2. Найти максимальный элемент и добавить его в начало
    auto max_el = find_max(m);
    m.insert(make_pair(-1, max_el.second));
    cout << "После добавления max для начала:" << endl;
    print_multimap(m);
    
    // 3. Удалить минимальный элемент
    auto min_el = find_min(m);
    for (auto it = m.begin(); it != m.end(); ) {
        if (it->second == min_el.second) {
            it = m.erase(it);
            break;
        } else {
            ++it;
        }
    }
    cout << "После удаления min:" << endl;
    print_multimap(m);
    
    // 4. Добавить к каждому элементу среднее арифметическое
    double avg = calculate_average(m);
    TMultiMap new_map;
    for (auto& el : m) {
        new_map.insert(make_pair(el.first, el.second + avg));
    }
    m = new_map;
    cout << "После добавления среднего значения к каждому элементу:" << endl;
    print_multimap(m);
    
    return 0;
}
