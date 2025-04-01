#include <iostream>
using namespace std;

struct Node
{
    int key;
    Node* next;
};

// Добавляет элемент в начало списка
void addFirst(Node*& head, int key) 
{
    Node* newNode = new Node{ key, head };
    head = newNode;
}

// Удаляет элемент по позиции (начиная с 0)
void removeAt(Node*& head, int pos) 
{
    if (!head)
    {
        return;
    }

    if (pos == 0)
    {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }

    Node* current = head;
    for (int i = 0; current && i < pos - 1; i++) 
    {
        current = current->next;
    }

    if (!current || !current->next)
    {
        return;
    }

    Node* temp = current->next;
    current->next = temp->next;
    delete temp;
}

// Выводит список
void printList(Node* head) 
{
    while (head)
    {
        cout << head->key << " ";
        head = head->next;
    }
    cout << "\n";
}

// Освобождает память
void clearList(Node*& head)
{
    while (head) 
    {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

int main() 
{
    setlocale(LC_ALL, "RU");
    Node* list = nullptr;

    // Создаем список: 1 2 3
    addFirst(list, 20);
    addFirst(list, 10);
    addFirst(list, 15);

    cout << "Список: ";
    printList(list);

    // Удаляем первый элемент (позиция 0)
    removeAt(list, 0);
    cout << "После удаления: ";
    printList(list);

    // Добавляем новый элемент в начало
    addFirst(list, 0);
    cout << "После добавления: ";
    printList(list);

    clearList(list);
    return 0;
}
