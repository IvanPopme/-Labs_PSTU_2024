#pragma once
#include "Object.h"
#include "Event.h"

struct Node {
    Object* data;
    Node* next;
};

class List {
public:
    List(int size);
    ~List(void);
    
    void Add();
    void Del();
    void Show();
    void Show(int index);
    void HandleEvent(const TEvent& e);
    
    int operator()();
    
protected:
    Node* head;
    int size;
    int cur;
};
