#include <iostream>
using namespace std;

struct Node 
{
    int data;
    Node* prev;
    Node* next;
};

// Добавление в начало
void pushFront(Node** head, Node** tail, int value)
{
    Node* newNode = new Node{ value, nullptr, *head };

    if (*head)
   {
        (*head)->prev = newNode;
    }
    else 
    {
        *tail = newNode;
    }

    *head = newNode;
}

// Удаление по позиции
void deleteAt(Node** head, Node** tail, int pos) 
{
    if (!*head) 
    {
        return;
    }

    Node* current = *head;
    for (int i = 0; current && i < pos; i++) 
    {
        current = current->next;
    }

    if (!current) 
    {
        return;
    }

    if (current->prev)
    {
        current->prev->next = current->next;
    }
    else
    {
        *head = current->next;
    }

    if (current->next)
    {
        current->next->prev = current->prev;
    }
    else 
    {
        *tail = current->prev;
    }

    delete current;
}

// Вывод списка
void printList(Node* head)
{
    while (head)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << "\n";
}

// Очистка памяти
void clearList(Node* head)
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
    Node* head = nullptr;
    Node* tail = nullptr;

    // Создаем список 1->2->3
    pushFront(&head, &tail, 3);
    pushFront(&head, &tail, 2);
    pushFront(&head, &tail, 1);

    cout << "Исходный список: ";
    printList(head);

    // Удаляем второго элемент (позиция 1)
    deleteAt(&head, &tail, 1);
    cout << "После удаления: ";
    printList(head);

    // Добавляем в начало
    pushFront(&head, &tail, 5);
    cout << "После добавления: ";
    printList(head);

    clearList(head);
    return 0;
}
