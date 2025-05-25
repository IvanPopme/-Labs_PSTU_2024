#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

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
        kopecks %= 100;
        if (kopecks < 0) {
            rubles--;
            kopecks += 100;
        }
    }

    // Перегрузка операторов
    Money operator+(const Money& other) const {
        return Money(rubles + other.rubles, kopecks + other.kopecks);
    }

    Money operator/(int divisor) const {
        long total = rubles * 100 + kopecks;
        total /= divisor;
        return Money(total / 100, total % 100);
    }

    bool operator>(const Money& other) const {
        if (rubles != other.rubles) return rubles > other.rubles;
        return kopecks > other.kopecks;
    }

    bool operator<(const Money& other) const {
        if (rubles != other.rubles) return rubles < other.rubles;
        return kopecks < other.kopecks;
    }

    friend ostream& operator<<(ostream& os, const Money& m);
    friend istream& operator>>(istream& is, Money& m);
};

ostream& operator<<(ostream& os, const Money& m) {
    os << m.rubles << "," << (m.kopecks < 10 ? "0" : "") << m.kopecks;
    return os;
}

istream& operator>>(istream& is, Money& m) {
    char dot;
    is >> m.rubles >> dot >> m.kopecks;
    m.normalize();
    return is;
}

// Функции для работы с вектором Money аналогичны функциям для double,но используют перегруженные операторы класса Money

vector<Money> make_money_vector(int n) {
    vector<Money> v;
    for (int i = 0; i < n; i++) {
        long r = rand() % 100;
        int k = rand() % 100;
        v.emplace_back(r, k);
    }
    return v;
}

void print_money_vector(const vector<Money>& v) {
    for (const auto& item : v) {
        cout << item << " ";
    }
    cout << endl;
}

void add_max_to_begin(vector<Money>& v) {
    if (v.empty()) return;
    Money max_val = *max_element(v.begin(), v.end());
    v.insert(v.begin(), max_val);
}

void remove_min(vector<Money>& v) {
    if (v.empty()) return;
    auto min_it = min_element(v.begin(), v.end());
    v.erase(min_it);
}

void add_average_to_each(vector<Money>& v) {
    if (v.empty()) return;
    Money sum;
    for (const auto& item : v) {
        sum = sum + item;
    }
    Money avg = sum / v.size();
    for (auto& item : v) {
        item = item + avg;
    }
}

int main() {
    setlocale(LC_ALL, "RU");
    try {
        vector<Money> v;
        int n;
        cout << "Введите размер вектора: ";
        cin >> n;

        v = make_money_vector(n);
        cout << "Оригинальный вектор: ";
        print_money_vector(v);

        add_max_to_begin(v);
        cout << "После добавления max для начала: ";
        print_money_vector(v);

        remove_min(v);
        cout << "После удаления мин: ";
        print_money_vector(v);

        add_average_to_each(v);
        cout << "После добавления среднего значения к каждому: ";
        print_money_vector(v);
    }
    catch (...) {
        cout << "Произошла ошибка!" << endl;
    }
    return 0;
}
