#include <iostream>
#include <map>
#include <string>
using namespace std;

class Money {
private:
    long rubles;
    int kopecks;
public:
    Money() : rubles(0), kopecks(0) {}
    Money(long r, int k) : rubles(r), kopecks(k) {
        normalize();
    }
    
    void normalize() {
        rubles += kopecks / 100;
        kopecks = kopecks % 100;
        if (kopecks < 0) {
            rubles--;
            kopecks += 100;
        }
    }
    
    // Перегрузка операторов
    Money operator+(const Money& other) const {
        return Money(rubles + other.rubles, kopecks + other.kopecks);
    }
    
    Money operator-(const Money& other) const {
        return Money(rubles - other.rubles, kopecks - other.kopecks);
    }
    
    Money operator/(int n) const {
        long total = rubles * 100 + kopecks;
        total /= n;
        return Money(total / 100, total % 100);
    }
    
    bool operator<(const Money& other) const {
        if (rubles != other.rubles) 
            return rubles < other.rubles;
        return kopecks < other.kopecks;
    }
    
    bool operator>(const Money& other) const {
        return other < *this;
    }
    
    friend ostream& operator<<(ostream& os, const Money& m) {
        os << m.rubles << "," << (m.kopecks < 10 ? "0" : "") << m.kopecks;
        return os;
    }
    
    friend istream& operator>>(istream& is, Money& m) {
        char sep;
        is >> m.rubles >> sep >> m.kopecks;
        m.normalize();
        return is;
    }
};

typedef map<int, Money> TMoneyMap;
typedef TMoneyMap::iterator it;

// Функции аналогичны задаче 1, но работают с Money
TMoneyMap make_map(int n) {
    TMoneyMap m;
    Money a;
    for (int i = 0; i < n; i++) {
        cout << "?";
        cin >> a;
        m.insert(make_pair(i, a));
    }
    return m;
}

void print_map(TMoneyMap m) {
    for (auto& el : m) {
        cout << el.first << " : " << el.second << endl;
    }
}

pair<int, Money> find_max(TMoneyMap m) {
    auto max_it = max_element(m.begin(), m.end(), 
        [](const pair<int, Money>& a, const pair<int, Money>& b) {
            return a.second < b.second;
        });
    return *max_it;
}

pair<int, Money> find_min(TMoneyMap m) {
    auto min_it = min_element(m.begin(), m.end(), 
        [](const pair<int, Money>& a, const pair<int, Money>& b) {
            return a.second < b.second;
        });
    return *min_it;
}

Money calculate_average(TMoneyMap m) {
    Money sum;
    for (auto& el : m) {
        sum = sum + el.second;
    }
    return sum / m.size();
}

int main() {
  setlocale (LC_ALL,"RU");
    int n;
    cout << "N? "; cin >> n;
    
    TMoneyMap m = make_map(n);
    print_map(m);
    
    auto max_el = find_max(m);
    m.insert(make_pair(-1, max_el.second));
    cout << "После добавления max для начала:" << endl;
    print_map(m);
    
    auto min_el = find_min(m);
    m.erase(min_el.first);
    cout << "После удаления мин:" << endl;
    print_map(m);
    
    Money avg = calculate_average(m);
    TMoneyMap new_map;
    for (auto& el : m) {
        new_map.insert(make_pair(el.first, el.second + avg));
    }
    m = new_map;
    cout << "После добавления среднего значения к каждому элементу:" << endl;
    print_map(m);
    
    return 0;
}
