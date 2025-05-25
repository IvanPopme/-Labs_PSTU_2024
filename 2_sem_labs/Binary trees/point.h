#ifndef POINT_H
#define POINT_H

#include <iostream>
using namespace std;
struct point {
    int data;      // информационное поле
    point* left;   // адрес левого поддерева
    point* right;  // адрес правого поддерева
};

// Создание идеально сбалансированного бинарного дерева
point* createBalancedTree(int n);

// Печать дерева (обход слева направо)
void printTreeLeftToRight(point* p, int level = 0);

// Преобразование в дерево поиска
void treeToSearchTree(point* root);

// Вспомогательная функция для преобразования в дерево поиска
void storeNodes(point* root, point** nodes, int* index);

// Вспомогательная функция для преобразования в дерево поиска
point* buildSearchTree(point** nodes, int start, int end);

// Подсчет количества узлов
int countNodes(point* root);

// Вычисление суммы значений узлов
int sumNodes(point* root);

// Удаление дерева
void deleteTree(point* root);

#endif
