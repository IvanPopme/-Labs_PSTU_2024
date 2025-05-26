#include "Money.h"
#include <set>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

typedef vector<Money> TVector;

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

// Функция для вывода multiset
void print_multiset(const multiset<Money>& mset) {
    cout << "\nСодержимое множества:" << endl;
    for (const auto& m : mset) {
        cout << m << endl;
    }
}

int main() {
    setlocale(LC_ALL, "RU");

    int n;
    cout << "Введите количество элементов: ";
    cin >> n;

    // Создаем и заполняем вектор
    TVector v = make_vector(n);
    
    // 1. Создаем multiset на основе вектора
    multiset<Money> moneyMultiset(v.begin(), v.end());
    
    cout << "\nИсходное множество с дубликатами:" << endl;
    print_multiset(moneyMultiset);

    // 2. Находим максимальный элемент
    if (!moneyMultiset.empty()) {
        Money max_val = *moneyMultiset.rbegin();
        cout << "\nМаксимальный элемент: " << max_val << endl;

        // 3. Добавляем максимальный элемент в начало (для multiset это не имеет смысла, 
        // так как элементы упорядочены, поэтому просто добавляем)
        moneyMultiset.insert(max_val);
        cout << "\nМножество после добавления максимального элемента:" << endl;
        print_multiset(moneyMultiset);

        // 4. Удаляем минимальный элемент
        Money min_val = *moneyMultiset.begin();
        cout << "\nМинимальный элемент: " << min_val << endl;
        moneyMultiset.erase(min_val);
        
        cout << "\nМножество после удаления минимального элемента:" << endl;
        print_multiset(moneyMultiset);

        // 5. Добавляем среднее арифметическое к каждому элементу
        Money sum;
        for (const auto& m : moneyMultiset) {
            sum = sum + m;
        }
        Money average = sum / moneyMultiset.size();
        cout << "\nСреднее арифметическое: " << average << endl;

        // Создаем новое множество с измененными значениями
        multiset<Money> newMultiset;
        for (const auto& m : moneyMultiset) {
            newMultiset.insert(m + average);
        }
        moneyMultiset = newMultiset;
        
        cout << "\nМножество после добавления среднего арифметического:" << endl;
        print_multiset(moneyMultiset);
    }

    return 0;
}
