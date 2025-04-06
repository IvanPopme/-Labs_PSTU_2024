#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* prev;
    Node* next;
};

struct Stack
{
    Node* head = nullptr;
    Node* tail = nullptr;

    // Добавление в начало (верх стека)
    void push(int value)
    {
        Node* newNode = new Node{ value, nullptr, head };
        if (head)
            head->prev = newNode;
        else
            tail = newNode; // Если стек был пуст
        head = newNode;
    }

    // Удаление по позиции (0 - верхний элемент)
    bool popAt(int pos)
    {
        if (!head) return false;

        Node* current = head;
        for (int i = 0; current && i < pos; i++)
            current = current->next;

        if (!current) return false;

        if (current->prev)
            current->prev->next = current->next;
        else
            head = current->next; // Удаляем первый элемент

        if (current->next)
            current->next->prev = current->prev;
        else
            tail = current->prev; // Удаляем последний элемент

        delete current;
        return true;
    }

    // Вывод стека
    void print() const
    {
        Node* temp = head;
        while (temp)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << "\n";
    }

    // Очистка памяти
    ~Stack()
    {
        while (head)
        {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main()
{
    setlocale(LC_ALL, "RU");
    Stack stack;

    // Заполняем стек
    stack.push(3);
    stack.push(2);
    stack.push(1);

    cout << "Исходный стек: ";
    stack.print();

    // Удаляем элемент на позиции 1 (второй сверху)
    if (stack.popAt(1))
        cout << "Удален элемент на позиции 1\n";
    else
        cout << "Ошибка удаления\n";

    cout << "Стек после удаления: ";
    stack.print();

    // Добавляем новый элемент
    stack.push(5);
    cout << "Добавлен 5: ";
    stack.print();

    return 0; 
}
