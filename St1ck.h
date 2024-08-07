#pragma once
#ifndef ST1CK_H
#define ST1CK_H

#include <iostream>

struct Node {
public:
    int data;
    Node* next;

    Node() : data(0), next(nullptr) {}
    Node(int data) : data(data), next(nullptr) {}
    Node(int data, Node* next) : data(data), next(next) {}
};

class Queue {
private:
    Node* front;
    Node* rear;
public:
    Queue() : front(nullptr), rear(nullptr) {}
    ~Queue();
    void enqueue(int data);
    bool dequeue();
    void display() const;
    bool peek(int& data);

};

#endif // ST1CK_H



