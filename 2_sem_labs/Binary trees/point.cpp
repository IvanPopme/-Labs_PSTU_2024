#include "point.h"
#include <cstdlib>
#include <ctime>

// Создание идеально сбалансированного бинарного дерева
point* createBalancedTree(int n) {
    if (n == 0) return nullptr;

    point* p = new point;
    p->data = rand() % 100;  // случайное число от 0 до 99

    int leftCount = n / 2;
    int rightCount = n - leftCount - 1;

    p->left = createBalancedTree(leftCount);
    p->right = createBalancedTree(rightCount);

    return p;
}

// Печать дерева (обход слева направо)
void printTreeLeftToRight(point* p, int level) {
    if (p) {
        printTreeLeftToRight(p->left, level + 1);
        for (int i = 0; i < level; i++) cout << "   ";
        cout << p->data << endl;
        printTreeLeftToRight(p->right, level + 1);
    }
}

// Вспомогательная функция для преобразования в дерево поиска
void storeNodes(point* root, point** nodes, int* index) {
    if (root == nullptr) return;

    storeNodes(root->left, nodes, index);
    nodes[(*index)++] = root;
    storeNodes(root->right, nodes, index);
}

// Вспомогательная функция для преобразования в дерево поиска
point* buildSearchTree(point** nodes, int start, int end) {
    if (start > end) return nullptr;

    int mid = (start + end) / 2;
    point* root = nodes[mid];

    root->left = buildSearchTree(nodes, start, mid - 1);
    root->right = buildSearchTree(nodes, mid + 1, end);

    return root;
}

// Преобразование в дерево поиска
void treeToSearchTree(point* root) {
    if (root == nullptr) return;

    int n = countNodes(root);
    point** nodes = new point * [n];
    int index = 0;

    storeNodes(root, nodes, &index);
    buildSearchTree(nodes, 0, n - 1);

    delete[] nodes;
}

// Подсчет количества узлов
int countNodes(point* root) {
    if (root == nullptr) return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

// Вычисление суммы значений узлов
int sumNodes(point* root) {
    if (root == nullptr) return 0;
    return root->data + sumNodes(root->left) + sumNodes(root->right);
}

// Удаление дерева
void deleteTree(point* root) {
    if (root) {
        deleteTree(root->left);
        deleteTree(root->right);
        delete root;
    }
}
