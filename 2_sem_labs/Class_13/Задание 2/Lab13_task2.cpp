#include "Money.h"
#include <stack>
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

// Функция для вывода стека
void print_stack(stack<Money> stk) {
    cout << "\nСодержимое стека (сверху вниз):" << endl;
    while (!stk.empty()) {
        cout << stk.top() << endl;
        stk.pop();
    }
}

int main() {
    setlocale(LC_ALL, "RU");

    int n;
    cout << "Введите количество элементов: ";
    cin >> n;

    // Создаем вектор и заполняем его
    TVector v = make_vector(n);
    
    // 1. Создаем стек на основе вектора
    stack<Money, TVector> moneyStack(v);
    
    cout << "\nИсходный стек:" << endl;
    print_stack(moneyStack);

    // 2. Находим максимальный элемент в векторе 
    auto max_it = max_element(v.begin(), v.end());
    Money max_val = *max_it;
    cout << "\nМаксимальный элемент: " << max_val << endl;

    // 3. Добавляем максимальный элемент в начало стека
    // Для стека "начало" - это дно, но мы можем только добавлять в верх
    // Поэтому создадим новый стек с добавленным элементом
    stack<Money, TVector> newStack;
    newStack.push(max_val);  // Добавляем максимальный элемент первым
    
    // Переносим все элементы из исходного стека в новый
    while (!moneyStack.empty()) {
        newStack.push(moneyStack.top());
        moneyStack.pop();
    }
    
    cout << "\nСтек после добавления максимального элемента в начало:" << endl;
    print_stack(newStack);

    // 4. Находим и удаляем минимальный элемент
    auto min_it = min_element(v.begin(), v.end());
    Money min_val = *min_it;
    cout << "\nМинимальный элемент: " << min_val << endl;
    
    // Создаем временный стек для хранения элементов
    stack<Money, TVector> tempStack;
    
    // Переносим элементы, пропуская минимальный
    while (!newStack.empty()) {
        Money current = newStack.top();
        newStack.pop();
        if (!(current == min_val)) {
            tempStack.push(current);
        }
    }
    
    // Возвращаем элементы обратно в исходный порядок
    while (!tempStack.empty()) {
        newStack.push(tempStack.top());
        tempStack.pop();
    }
    
    cout << "\nСтек после удаления минимального элемента:" << endl;
    print_stack(newStack);

    // 5. Добавляем среднее арифметическое к каждому элементу
    Money sum;
    size_t count = 0;
    
    // Сначала вычисляем сумму
    tempStack = newStack;
    while (!tempStack.empty()) {
        sum = sum + tempStack.top();
        tempStack.pop();
        count++;
    }
    
    Money average = sum / count;
    cout << "\nСреднее арифметическое: " << average << endl;
    
    // Создаем новый стек с измененными значениями
    stack<Money, TVector> resultStack;
    while (!newStack.empty()) {
        Money current = newStack.top();
        newStack.pop();
        resultStack.push(current + average);
    }
    
    // Переворачиваем стек, чтобы сохранить порядок
    while (!resultStack.empty()) {
        newStack.push(resultStack.top());
        resultStack.pop();
    }
    
    cout << "\nСтек после добавления среднего арифметического:" << endl;
    print_stack(newStack);

    return 0;
}
