#include <iostream>
#include <chrono>
#include <vector>
#include <random>

using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int data) : data(data), left(nullptr), right(nullptr) {}
    ~Node() {
        delete left;
        delete right;
    }
};

class BST {
private:
    Node* root;

    bool insert(Node*& node, int data) {
        if (node == nullptr) {
            node = new Node(data);
            return true;
        }
        if (data < node->data)
            return insert(node->left, data);
        if (data > node->data)
            return insert(node->right, data);
        return false; // Data already exists
    }

    bool search(Node* node, int data) const {
        if (node == nullptr)
            return false;
        if (node->data == data)
            return true;
        if (data < node->data)
            return search(node->left, data);
        else
            return search(node->right, data);
    }

public:
    BST() : root(nullptr) {}
    ~BST() {
        delete root;
    }

    bool insert(int data) {
        return insert(root, data);
    }

    bool search(int data) const {
        return search(root, data);
    }
};

class LinkedList {
private:
    class Node {
    public:
        int data;
        Node* next;
        Node(int data) : data(data), next(nullptr) {}
    };

    Node* head;

public:
    LinkedList() : head(nullptr) {}
    ~LinkedList() {
        Node* current = head;
        while (current != nullptr) {
            Node* next = current->next;
            delete current;
            current = next;
        }
    }

    void append(int data) {
        Node* newNode = new Node(data);
        if (head == nullptr) {
            head = newNode;
            return;
        }
        Node* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
    }

    bool search(int data) const {
        Node* current = head;
        while (current != nullptr) {
            if (current->data == data)
                return true;
            current = current->next;
        }
        return false;
    }
};
// Delete 
vector<int> generateRandomNumbers(int count, int min, int max) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(min, max);
        vector<int> numbers;
        for (int i = 0; i < count; ++i) {
            numbers.push_back(dis(gen));
        }
        return numbers;
}

int main() {
    // Generate random numbers
    vector<int> randomNumbers12 = generateRandomNumbers(12, 1, 1000);
    vector<int> randomNumbers24 = generateRandomNumbers(24, 1, 1000);
    vector<int> randomNumbers200 = generateRandomNumbers(200, 1, 1000);
    vector<int> numbersBackwards1000 = generateRandomNumbers(1000, 1, 1000);
    vector<int> numbersForwards1000 = generateRandomNumbers(1000, 1, 1000);

    // Dozen
    LinkedList ll1;
    BST bst1;

    auto startLLInsert1 = chrono::high_resolution_clock::now();
    for (int num : randomNumbers12) {
        ll1.append(num);
    }
    auto endLLInsert1 = chrono::high_resolution_clock::now();

    auto startBSTInsert1 = chrono::high_resolution_clock::now();
    for (int num : randomNumbers12) {
        bst1.insert(num);
    }
    auto endBSTInsert1 = chrono::high_resolution_clock::now();

    auto durationLLInsert1 = chrono::duration_cast<chrono::microseconds>(endLLInsert1 - startLLInsert1);
    auto durationBSTInsert1 = chrono::duration_cast<chrono::microseconds>(endBSTInsert1 - startBSTInsert1);

    cout << "LinkedList Insertion Time (Dozen): " << durationLLInsert1.count() << " microseconds" << endl;
    cout << "BST Insertion Time (Dozen): " << durationBSTInsert1.count() << " microseconds" << endl;

    // Search a random value
    int searchValue1 = randomNumbers12[rand() % randomNumbers12.size()];

    auto startLLSearch1 = chrono::high_resolution_clock::now();
    bool llFound1 = ll1.search(searchValue1);
    auto endLLSearch1 = chrono::high_resolution_clock::now();
    auto durationLLSearch1 = chrono::duration_cast<chrono::microseconds>(endLLSearch1 - startLLSearch1);

    auto startBSTSearch1 = chrono::high_resolution_clock::now();
    bool bstFound1 = bst1.search(searchValue1);
    auto endBSTSearch1 = chrono::high_resolution_clock::now();
    auto durationBSTSearch1 = chrono::duration_cast<chrono::microseconds>(endBSTSearch1 - startBSTSearch1);

    cout << "LinkedList Search Time (Dozen): " << durationLLSearch1.count() << " microseconds, Found: " << llFound1 << endl;
    cout << "BST Search Time (Dozen): " << durationBSTSearch1.count() << " microseconds, Found: " << bstFound1 << "\n" << endl;

    // 2 Dozen
    LinkedList ll2;
    BST bst2;

    auto startInsertLL2 = chrono::high_resolution_clock::now();
    for (int num : randomNumbers24) {
        ll2.append(num);
    }
    auto endInsertLL2 = chrono::high_resolution_clock::now();

    auto startInsertB2 = chrono::high_resolution_clock::now();
    for (int num : randomNumbers24) {
        bst2.insert(num);
    }
    auto endInsertB2 = chrono::high_resolution_clock::now();

    auto durationInsertLL2 = chrono::duration_cast<chrono::microseconds>(endInsertLL2 - startInsertLL2);
    auto durationInsertB2 = chrono::duration_cast<chrono::microseconds>(endInsertB2 - startInsertB2);

    cout << "LinkedList Insertion Time (2 Dozen): " << durationInsertLL2.count() << " microseconds" << endl;
    cout << "BST Insertion Time (2 Dozen): " << durationInsertB2.count() << " microseconds" << endl;

    int searchValue2 = randomNumbers24[12]; // Search for the 13th value 

    auto startLL2 = chrono::high_resolution_clock::now();
    bool foundLL2 = ll2.search(searchValue2);
    auto endLL2 = chrono::high_resolution_clock::now();

    auto startB2 = chrono::high_resolution_clock::now();
    bool foundB2 = bst2.search(searchValue2);
    auto endB2 = chrono::high_resolution_clock::now();

    auto durationSearchLL2 = chrono::duration_cast<chrono::microseconds>(endLL2 - startLL2);
    auto durationSearchB2 = chrono::duration_cast<chrono::microseconds>(endB2 - startB2);

    cout << "LinkedList Search Time (2 Dozen): " << durationSearchLL2.count() << " microseconds, Found: " << foundLL2 << endl;
    cout << "BST Search Time (2 Dozen): " << durationSearchB2.count() << " microseconds, Found: " << foundB2 << "\n" << endl;

    // 200 Hundred
    LinkedList ll200;
    BST bst200;

    auto startInsertLL200 = chrono::high_resolution_clock::now();
    for (int num : randomNumbers200) {
        ll200.append(num);
    }
    auto endInsertLL200 = chrono::high_resolution_clock::now();

    auto startInsertBST200 = chrono::high_resolution_clock::now();
    for (int num : randomNumbers200) {
        bst200.insert(num);
    }
    auto endInsertBST200 = chrono::high_resolution_clock::now();

    auto durationInsertLL200 = chrono::duration_cast<chrono::microseconds>(endInsertLL200 - startInsertLL200);
    auto durationInsertBST200 = chrono::duration_cast<chrono::microseconds>(endInsertBST200 - startInsertBST200);

    cout << "LinkedList Insertion Time (200 Hundred): " << durationInsertLL200.count() << " microseconds" << endl;
    cout << "BST Insertion Time (200 Hundred): " << durationInsertBST200.count() << " microseconds" << endl;

    int searchValue200 = randomNumbers200[100]; // Search for the 101st value 

    auto startSearchLL200 = chrono::high_resolution_clock::now();
    bool foundLL200 = ll200.search(searchValue200);
    auto endSearchLL200 = chrono::high_resolution_clock::now();
    auto durationSearchLL200 = chrono::duration_cast<chrono::microseconds>(endSearchLL200 - startSearchLL200);

    auto startSearchBST200 = chrono::high_resolution_clock::now();
    bool foundBST200 = bst200.search(searchValue200);
    auto endSearchBST200 = chrono::high_resolution_clock::now();
    auto durationSearchBST200 = chrono::duration_cast<chrono::microseconds>(endSearchBST200 - startSearchBST200);

    cout << "LinkedList Search Time (200 Hundred): " << durationSearchLL200.count() << " microseconds, Found: " << foundLL200 << endl;
    cout << "BST Search Time (200 Hundred): " << durationSearchBST200.count() << " microseconds, Found: " << foundBST200 << "\n" << endl;

    // 1000 -> 1
    LinkedList ll3;
    BST bst3;

    auto startLLInsert3 = chrono::high_resolution_clock::now();
    for (int num : numbersBackwards1000) {
        ll3.append(num);
    }
    auto endLLInsert3 = chrono::high_resolution_clock::now();

    auto startBSTInsert3 = chrono::high_resolution_clock::now();
    for (int num : numbersBackwards1000) {
        bst3.insert(num);
    }
    auto endBSTInsert3 = chrono::high_resolution_clock::now();

    auto durationLLInsert3 = chrono::duration_cast<chrono::microseconds>(endLLInsert3 - startLLInsert3);
    auto durationBSTInsert3 = chrono::duration_cast<chrono::microseconds>(endBSTInsert3 - startBSTInsert3);

    cout << "LinkedList Insertion Time (1000 -> 1): " << durationLLInsert3.count() << " microseconds" << endl;
    cout << "BST Insertion Time (1000 -> 1): " << durationBSTInsert3.count() << " microseconds" << endl;

    int searchValue3 = numbersBackwards1000[rand() % numbersBackwards1000.size()];

    auto startLLSearch3 = chrono::high_resolution_clock::now();
    bool llFound3 = ll3.search(searchValue3);
    auto endLLSearch3 = chrono::high_resolution_clock::now();
    auto durationLLSearch3 = chrono::duration_cast<chrono::microseconds>(endLLSearch3 - startLLSearch3);

    auto startBSTSearch3 = chrono::high_resolution_clock::now();
    bool bstFound3 = bst3.search(searchValue3);
    auto endBSTSearch3 = chrono::high_resolution_clock::now();
    auto durationBSTSearch3 = chrono::duration_cast<chrono::microseconds>(endBSTSearch3 - startBSTSearch3);

    cout << "LinkedList Search Time (1000 -> 1): " << durationLLSearch3.count() << " microseconds, Found: " << llFound3 << endl;
    cout << "BST Search Time (1000 -> 1): " << durationBSTSearch3.count() << " microseconds, Found: " << bstFound3 << "\n" << endl;

    // 1 -> 1K
    LinkedList ll4;
    BST bst4;

    auto startLLInsert4 = chrono::high_resolution_clock::now();
    for (int num : numbersForwards1000) {
        ll4.append(num);
    }
    auto endLLInsert4 = chrono::high_resolution_clock::now();

    auto startBSTInsert4 = chrono::high_resolution_clock::now();
    for (int num : numbersForwards1000) {
        bst4.insert(num);
    }
    auto endBSTInsert4 = chrono::high_resolution_clock::now();

    auto durationLLInsert4 = chrono::duration_cast<chrono::microseconds>(endLLInsert4 - startLLInsert4);
    auto durationBSTInsert4 = chrono::duration_cast<chrono::microseconds>(endBSTInsert4 - startBSTInsert4);

    cout << "LinkedList Insertion Time (1 -> 1K): " << durationLLInsert4.count() << " microseconds" << endl;
    cout << "BST Insertion Time (1 -> 1K): " << durationBSTInsert4.count() << " microseconds" << endl;

    int searchValue4 = numbersForwards1000[500]; // Search for a value in the middle

    auto startLLSearch4 = chrono::high_resolution_clock::now();
    bool llFound4 = ll4.search(searchValue4);
    auto endLLSearch4 = chrono::high_resolution_clock::now();
    auto durationLLSearch4 = chrono::duration_cast<chrono::microseconds>(endLLSearch4 - startLLSearch4);

    auto startBSTSearch4 = chrono::high_resolution_clock::now();
    bool bstFound4 = bst4.search(searchValue4);
    auto endBSTSearch4 = chrono::high_resolution_clock::now();
    auto durationBSTSearch4 = chrono::duration_cast<chrono::microseconds>(endBSTSearch4 - startBSTSearch4);

    cout << "LinkedList Search Time (1 -> 1K): " << durationLLSearch4.count() << " microseconds, Found: " << llFound4 << endl;
    cout << "BST Search Time (1 -> 1K): " << durationBSTSearch4.count() << " microseconds, Found: " << bstFound4 << "\n" << endl;

    return 0;
}


