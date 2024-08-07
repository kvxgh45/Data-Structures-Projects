#include "LinkedList.h"

// Constructor
LinkedList::LinkedList() : head(nullptr), tail(nullptr) {}

// Destructor
LinkedList::~LinkedList() {
    Node* tmp = head;
    while (tmp != nullptr) {
        Node* next = tmp->next;
        delete tmp;
        tmp = next;
    }
    head = nullptr;
    tail = nullptr;
}

// Function to prepend a number into the front of the LL
void LinkedList::prepend(int data) {
    Node* tmp = new Node(data);
    if (head == nullptr) {
        head = tmp;
        tail = tmp;
    }
    else {
        tmp->next = head;
        head = tmp;
    }
}

// Function to remove a node with specific data from the LL
bool LinkedList::remove(int data) {
    Node* tmp = head;
    Node* prev = nullptr;

    while (tmp != nullptr) {
        if (tmp->data == data) {
            if (tmp == head) {
                head = tmp->next;
            }
            else if (tmp == tail) {
                tail = prev;
            }
            else {
                prev->next = tmp->next;
            }
            delete tmp;
            return true;
        }
        prev = tmp;
        tmp = tmp->next;
    }
    return false;
}


// Function to append a number into the LL
void LinkedList::append(int data) {
    Node* tmp = new Node(data);
    if (head == nullptr) {
        head = tmp;
        tail = tmp;
    }
    else {
        tail->next = tmp;
        tail = tmp;
    }
}

// Function to display the elements of the LL
void LinkedList::display() {
    Node* tmp = head;
    while (tmp != nullptr) {
        std::cout << tmp->data << " ";
        tmp = tmp->next;
    }
    std::cout << std::endl;
}
// Done in Demo on Monday
void LinkedList::tailDisplay()
{
    std::cout << "The tail element is: " << tail->data << std::endl;    // Tail Display Function, void becasue not returning anything 
}
bool LinkedList::tailRemove(int data)                                   // Tail Remove Function, bool becasue it uses true/false statements, also has 1 parameter
{
    if (head == nullptr) {
        std::cout << "List is empty. No node to remove.\n";
        return false;
    }
    if (head == tail) {
        delete head;
        head = nullptr;
        tail = nullptr;
        return true;
    }

    Node* temp = head;
    while (temp->next != tail) {
        temp = temp->next;
    }
    delete tail;
    tail = temp;
    tail->next = nullptr;
    return true;

}
int main() {
   // Linked List Declaration
    LinkedList mL;
  // Operations
    mL.append(5);
    mL.append(33);
    mL.append(1);
    mL.append(7);
    mL.append(33);
    mL.append(12);
    mL.display();
    mL.remove(33);
    mL.display();
    mL.prepend(12);
    mL.display();
    mL.remove(13);
    mL.display();
    mL.tailRemove(12);
    mL.tailDisplay();
    mL.display();
    
    return 0;
}