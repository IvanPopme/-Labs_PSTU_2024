#include <iostream>
using namespace std;

struct Node 
{
    int value;
    Node* next = nullptr;
};

struct Queue 
{
    Node* first = nullptr;
    Node* last = nullptr;

    // Добавить в конец
    void push(int x)
    {
        Node* newNode = new Node{ x };
        if (last) last->next = newNode;
        else first = newNode;
        last = newNode;
    }

    // Удалить из начала
    void pop()
    {
        if (!first) return;
        Node* temp = first;
        first = first->next;
        if (!first) last = nullptr;
        delete temp;
    }

    // Вывести очередь
    void print()
    {
        Node* current = first;
        while (current)
        {
            cout << current->value << " ";
            current = current->next;
        }
        cout << endl;
    }

    // Очистить память
    ~Queue()
    {
        while (first) pop();
    }
};

int main()
{
    setlocale(LC_ALL, "RU");
    Queue q;
    q.push(1);
    q.push(2);
    q.push(3);

    cout << "Очередь: ";
    q.print();

    q.pop();
    cout << "После удаления: ";
    q.print();

    q.push(4);
    cout << "После добавления: ";
    q.print();

    return 0;
}
