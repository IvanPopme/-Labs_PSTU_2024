#include "List.h"
#include <iostream>

List::List(int n) {
    head = nullptr;
    size = n;
    cur = 0;
}

List::~List(void) {
    Node* current = head;
    while (current != nullptr) {
        Node* next = current->next;
        delete current->data;
        delete current;
        current = next;
    }
}

void List::Add() {
    if (cur >= size) return;

    Object* p;
    cout << "1. Person\n2. Student\n";
    int choice;
    cin >> choice;

    if (choice == 1) {
        Person* a = new Person;
        a->Input();
        p = a;
    } else if (choice == 2) {
        Student* b = new Student;
        b->Input();
        p = b;
    } else {
        return;
    }

    Node* newNode = new Node;
    newNode->data = p;
    newNode->next = nullptr;

    if (head == nullptr) {
        head = newNode;
    } else {
        Node* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
    }
    cur++;
}

void List::Del() {
    if (cur == 0) return;
    
    if (head->next == nullptr) {
        delete head->data;
        delete head;
        head = nullptr;
    } else {
        Node* current = head;
        Node* prev = nullptr;
        while (current->next != nullptr) {
            prev = current;
            current = current->next;
        }
        delete current->data;
        delete current;
        prev->next = nullptr;
    }
    cur--;
}

void List::Show() {
    if (cur == 0) {
        cout << "Empty\n";
        return;
    }
    
    Node* current = head;
    int index = 0;
    while (current != nullptr) {
        cout << "\nElement " << index++ << ":";
        current->data->Show();
        current = current->next;
    }
}

void List::Show(int index) {
    if (index < 0 || index >= cur) {
        cout << "Invalid index\n";
        return;
    }
    
    Node* current = head;
    for (int i = 0; i < index; i++) {
        current = current->next;
    }
    current->data->Show();
}

int List::operator()() {
    return cur;
}

void List::HandleEvent(const TEvent& e) {
    if (e.what == evMessage) {
        Node* current = head;
        while (current != nullptr) {
            current->data->HandleEvent(e);
            current = current->next;
        }
    }
}
