#include <iostream>
using namespace std;

struct Node 
{
    int value;
    Node* next = nullptr;
    Node* prev = nullptr;  // Добавлен указатель на предыдущий элемент
};

struct Queue 
{
    Node* first = nullptr;
    Node* last = nullptr;

    // Добавить в конец
    void push(int x)
    {
        Node* newNode = new Node{ x };
        if (last) 
        {
            last->next = newNode;
            newNode->prev = last;  // Устанавливаем связь с предыдущим элементом
        }
        else 
        {
            first = newNode;
        }
        last = newNode;
    }

    // Удалить из начала
    void pop()
    {
        if (!first) return;
        Node* temp = first;
        first = first->next;
        if (first) 
        {
            first->prev = nullptr;  // Обнуляем указатель на предыдущий элемент
        }
        else 
        {
            last = nullptr;
        }
        delete temp;
    }

    // Вывести очередь (с начала в конец)
    void print_forward()
    {
        Node* current = first;
        while (current)
        {
            cout << current->value << " ";
            current = current->next;
        }
        cout << endl;
    }

    // Вывести очередь (с конца в начало)
    void print_backward()
    {
        Node* current = last;
        while (current)
        {
            cout << current->value << " ";
            current = current->prev;
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

    cout << "Очередь (с начала в конец): ";
    q.print_forward();

    cout << "Очередь (с конца в начало): ";
    q.print_backward();

    q.pop();
    cout << "После удаления (с начала в конец): ";
    q.print_forward();

    q.push(4);
    cout << "После добавления (с начала в конец): ";
    q.print_forward();

    cout << "После добавления (с конца в начало): ";
    q.print_backward();

    return 0;
}
