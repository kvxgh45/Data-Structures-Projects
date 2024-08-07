#ifndef BST_H
#define BST_H

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}

    int degree() {
        int deg = 0;
        if (left != nullptr) deg++;
        if (right != nullptr) deg++;
        return deg;
    }
};

class BST {
private:
    Node* root;

    Node* insert(Node* root, int val);
    Node* remove(Node*& node, int data);
    Node* findMin(Node* root);
    Node* find(Node* root, int val);
    void preOrderPrint(Node* root, ostream& os);
    void inOrderPrint(Node* root, ostream& os);
    void postOrderPrint(Node* root, ostream& os);

public:
    BST();
    void insert(int val);
    bool remove(int val);
    bool find(int val);
    void preOrder(ostream& os);
    void inOrder(ostream& os);
    void postOrder(ostream& os);
};

#endif // BST_H





