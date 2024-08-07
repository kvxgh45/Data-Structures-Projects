#include <iostream>
#include "bst.h"

using namespace std;

Node* BST::insert(Node* root, int val) {
    if (root == nullptr)
        return new Node(val);
    if (val < root->data)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);
    return root;
}

Node* BST::remove(Node*& node, int data) {
    if (node == nullptr)
        return nullptr;

    if (data < node->data)
        node->left = remove(node->left, data);
    else if (data > node->data)
        node->right = remove(node->right, data);
    else {
        int deg = node->degree();                           
        if (deg == 0) {
            delete node;
            node = nullptr;
        }
        else if (deg == 1) {
            Node* tmp = node;
            if (node->left != nullptr)
                node = node->left;
            else
                node = node->right;
            delete tmp;
        }
        else {
            Node* tmp = node->left;
            while (tmp->right != nullptr)
                tmp = tmp->right;
            node->data = tmp->data;
            node->left = remove(node->left, tmp->data);
        }
    }
    return node;
}


Node* BST::findMin(Node* root) {
    while (root->left != nullptr) {
        root = root->left;
    }
    return root;
}

Node* BST::find(Node* root, int val) {
    if (root == nullptr) return nullptr;

    if (val < root->data)
        return find(root->left, val);
    else if (val > root->data)
        return find(root->right, val);
    else
        return root;
}

void BST::preOrderPrint(Node* root, ostream& os) {
    if (root == nullptr) return;
    os << root->data << " ";
    preOrderPrint(root->left, os);
    preOrderPrint(root->right, os);
}

void BST::inOrderPrint(Node* root, ostream& os) {
    if (root == nullptr) return;
    inOrderPrint(root->left, os);
    os << root->data << " ";
    inOrderPrint(root->right, os);
}

void BST::postOrderPrint(Node* root, ostream& os) {
    if (root == nullptr) return;
    postOrderPrint(root->left, os);
    postOrderPrint(root->right, os);
    os << root->data << " ";
}

BST::BST() : root(nullptr) {}

void BST::insert(int val) {
    root = insert(root, val);
}

bool BST::remove(int val) {
    if (!find(val)) return false;
    remove(root, val);
    return true;
}

bool BST::find(int val) {
    return find(root, val) != nullptr;
}

void BST::preOrder(ostream& os) {
    os << "Pre Order: ";
    preOrderPrint(root, os);
    os << endl;
}

void BST::inOrder(ostream& os) {
    os << "In Order: ";
    inOrderPrint(root, os);
    os << endl;
}

void BST::postOrder(ostream& os) {
    os << "Post Order: ";
    postOrderPrint(root, os);
    os << endl;
}
int main() {
    BST b;
    b.insert(56);
    b.insert(34);
    b.insert(70);
    b.insert(5);
    b.insert(1);
    b.insert(42);
    b.insert(40);
    b.insert(52);
    b.insert(62);
    b.insert(57);
    b.insert(89);
    b.insert(90);

    cout << b.find(44) << endl; // Output: 0 (not found)
    cout << b.find(62) << endl; // Output: 1 (found)

    b.remove(62);
    cout << b.find(62) << endl; // Output: 0 (removed)

    b.insert(44);
    cout << b.find(44) << endl; // Output: 1 (found after re-insertion)

    b.postOrder(cout); // Output: postOrder: 1 40 42 5 34 52 90 89 57 70 56 
    b.preOrder(cout);  // Output: preOrder: 56 34 5 1 42 40 52 70 57 89 90 
    b.inOrder(cout);   // Output: inOrder: 1 5 34 40 42 52 56 57 70 89 90 

    return 0;
}


