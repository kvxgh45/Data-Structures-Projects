// Defining Linked List Class
#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>

// Node structure/ Class 
struct Node {
    int data;
    Node* next;
    Node* prev; 

    Node(int data) : data(data), next(nullptr) {}
};

// LL class
class LinkedList {
private:
    Node* head;
    Node* tail;
public:
    LinkedList();
    ~LinkedList();

    void append(int data);
    void prepend(int data);
    bool remove(int data);
    void display();
    void tailDisplay();
    bool tailRemove(int data);
    
};

#endif /* LINKEDLIST_H */
