/*
Bryce Harper 
CSE 2383
Dr. Jones 
3/08/2024
*/

//precursor directives 
#include "St1ck.h"  //header file 
#include <iostream>

using namespace std;

// Destructor 
Queue::~Queue()
{
    Node* tmp = front;
    while (tmp != nullptr) {
        front = front->next;
        delete tmp;
        tmp = front;  // Fix the typo here
    }
}

// Enqueue function, used to insert 
void Queue::enqueue(int data)
{
    Node* newNode = new Node(data);
    if (rear == nullptr) {
        front = rear = newNode;
        return;
    }
    rear->next = newNode;
    rear = newNode;
}
// Dequeue function, used to remove 
bool Queue::dequeue()
{
    Node* tmp = front ;
    if (front == nullptr) return false;
    front = front->next; // Fix the assignment operator here
    delete tmp;
    return true;
}
// Display function, used to display contents 
void Queue::display() const
{
        Node* current = front;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
     cout << endl;
}
// Peek function, used to return a value
bool Queue::peek(int& data)
{
    if (front == nullptr) return false;
    data = front->data;
    return true;
}
// Main function
int main() {
    Queue S;
    int tmp;
    S.enqueue(5);
    S.peek(tmp);
    cout << tmp << endl;
    S.enqueue(33);
    S.enqueue(1);
    S.enqueue(7);
    S.peek(tmp);
    cout << tmp << endl;
    S.enqueue(33);
    S.enqueue(12);
    S.display();
    S.dequeue();
    S.display();
    S.enqueue(14);
    S.display();
    S.dequeue();
    S.dequeue();
    S.display();
    S.dequeue();
    S.dequeue();
    S.display();
    S.peek(tmp);
    cout << tmp << endl;
}
