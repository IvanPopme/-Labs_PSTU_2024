#include "point.h"
#include <iostream>

int main() {
    setlocale(LC_ALL, "RU");
    srand(time(0)); // Инициализация генератора случайных чисел

    int n;
    cout << "Введите количество узлов в дереве: ";
    cin >> n;

    // 1. Создание идеально сбалансированного дерева
    point* root = createBalancedTree(n);

    // 2. Печать дерева
    cout << "\nИдеально сбалансированное дерево:\n";
    printTreeLeftToRight(root);

    // 3. Вычисление среднего арифметического
    int count = countNodes(root);
    int sum = sumNodes(root);
    double average = static_cast<double>(sum) / count;
   cout << "\nСреднее арифметическое элементов дерева: " << average << endl;

    // 4. Преобразование в дерево поиска
    treeToSearchTree(root);

    // 5. Печать дерева поиска
    cout << "\nДерево поиска:\n";
    printTreeLeftToRight(root);

    // Освобождение памяти
    deleteTree(root);

    return 0;
}
