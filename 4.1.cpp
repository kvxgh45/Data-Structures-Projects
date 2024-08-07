#include <iostream>
#include <ctime>
#include <cstdlib>
#include <chrono>
#include <vector>

using namespace std;

// Node structure for Linked List
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

// Linked List class
class LinkedList {
private:
    Node* head;

public:
    LinkedList() : head(nullptr) {}

    // Insert at the end of the list
    void insert(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = newNode;
        }
        else {
            Node* temp = head;
            while (temp->next) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    // Search function
    bool search(int val) {
        Node* temp = head;
        while (temp) {
            if (temp->data == val) {
                return true;
            }
            temp = temp->next;
        }
        return false;
    }

    // Destructor to free memory
    ~LinkedList() {
        Node* temp;
        while (head) {
            temp = head->next;
            delete head;
            head = temp;
        }
    }
};

// Node structure for Binary Search Tree
struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

// Binary Search Tree class
class BST {
private:
    TreeNode* root;

    // Helper function for insertion
    TreeNode* insertUtil(TreeNode* node, int val) {
        if (!node) {
            return new TreeNode(val);
        }
        if (val < node->data) {
            node->left = insertUtil(node->left, val);
        }
        else if (val > node->data) {
            node->right = insertUtil(node->right, val);
        }
        return node;
    }

    // Helper function for searching
    bool searchUtil(TreeNode* node, int val) {
        if (!node) {
            return false;
        }
        if (node->data == val) {
            return true;
        }
        if (val < node->data) {
            return searchUtil(node->left, val);
        }
        else {
            return searchUtil(node->right, val);
        }
    }

public:
    BST() : root(nullptr) {}

    // Insertion function
    void insert(int val) {
        root = insertUtil(root, val);
    }

    // Search function
    bool search(int val) {
        return searchUtil(root, val);
    }

    // Destructor to free memory
    ~BST() {
        // Implement destructor
    }
};

// Function to generate random numbers
int getRandomNumber(int min, int max) {
    return rand() % (max - min + 1) + min;
}

int main() {
    srand(time(nullptr)); // Seed for random number generation

    // Scenario 1: A dozen random numbers between 1 and 1000
    cout << "Scenario 1: A dozen random numbers between 1 and 1000" << endl;
    LinkedList ll1;
    BST bst1;
    vector<int> dozen_random_numbers;
    for (int i = 0; i < 12; ++i) {
        int num = getRandomNumber(1, 1000);
        dozen_random_numbers.push_back(num);
        ll1.insert(num);
        bst1.insert(num);
    }
    auto startLLAppend = chrono::high_resolution_clock::now();
    auto endLLAppend = chrono::high_resolution_clock::now();
    auto durationLLAppend = chrono::duration_cast<chrono::microseconds>(endLLAppend - startLLAppend);
    cout << "Linked List Append Time: " << durationLLAppend.count() << " microseconds" << endl;

    int searchNum = getRandomNumber(1, 1000);
    auto startLLSearch = chrono::high_resolution_clock::now();
    bool llFound = ll1.search(searchNum);
    auto endLLSearch = chrono::high_resolution_clock::now();
    auto durationLLSearch = chrono::duration_cast<chrono::microseconds>(endLLSearch - startLLSearch);
    cout << "Linked List Search: Number: " << searchNum << " Found: " << llFound << " Time: " << durationLLSearch.count() << " microseconds" << endl;

    auto startBSTInsert = chrono::high_resolution_clock::now();
    bst1.insert(searchNum);
    auto endBSTInsert = chrono::high_resolution_clock::now();
    auto durationBSTInsert = chrono::duration_cast<chrono::microseconds>(endBSTInsert - startBSTInsert);
    cout << "BST Insert Time: " << durationBSTInsert.count() << " microseconds" << endl;

    auto startBSTSearch = chrono::high_resolution_clock::now();
    bool bstFound = bst1.search(searchNum);
    auto endBSTSearch = chrono::high_resolution_clock::now();
    auto durationBSTSearch = chrono::duration_cast<chrono::microseconds>(endBSTSearch - startBSTSearch);
    cout << "BST Find: Number: " << searchNum << " Found: " << bstFound << " Time: " << durationBSTSearch.count() << " microseconds" << endl;
    cout << endl;

    // Scenario 2: 2 dozen random numbers between 1 and 1000
    cout << "Scenario 2: 2 dozen random numbers between 1 and 1000" << endl;
    LinkedList ll2;
    BST bst2;
    vector<int> two_dozen_random_numbers;
    for (int i = 0; i < 24; ++i) {
        int num = getRandomNumber(1, 1000);
        two_dozen_random_numbers.push_back(num);
        ll2.insert(num);
        bst2.insert(num);
    }
    startLLAppend = chrono::high_resolution_clock::now();
    endLLAppend = chrono::high_resolution_clock::now();
    durationLLAppend = chrono::duration_cast<chrono::microseconds>(endLLAppend - startLLAppend);
    cout << "Linked List Append Time: " << durationLLAppend.count() << " microseconds" << endl;

    searchNum = getRandomNumber(1, 1000);
    startLLSearch = chrono::high_resolution_clock::now();
    llFound = ll2.search(searchNum);
    endLLSearch = chrono::high_resolution_clock::now();
    durationLLSearch = chrono::duration_cast<chrono::microseconds>(endLLSearch - startLLSearch);
    cout << "Linked List Search: Number: " << searchNum << " Found: " << llFound << " Time: " << durationLLSearch.count() << " microseconds" << endl;

    startBSTInsert = chrono::high_resolution_clock::now();
    bst2.insert(searchNum);
    endBSTInsert = chrono::high_resolution_clock::now();
    durationBSTInsert = chrono::duration_cast<chrono::microseconds>(endBSTInsert - startBSTInsert);
    cout << "BST Insert Time: " << durationBSTInsert.count() << " microseconds" << endl;

    startBSTSearch = chrono::high_resolution_clock::now();
    bstFound = bst2.search(searchNum);
    endBSTSearch = chrono::high_resolution_clock::now();
    durationBSTSearch = chrono::duration_cast<chrono::microseconds>(endBSTSearch - startBSTSearch);
    cout << "BST Find: Number: " << searchNum << " Found: " << bstFound << " Time: " << durationBSTSearch.count() << " microseconds" << endl;
    cout << endl;

    // Scenario 3: 200 random numbers between 1 and 1000
    cout << "Scenario 3: 200 random numbers between 1 and 1000" << endl;
    LinkedList ll3;
    BST bst3;
    vector<int> two_hundred_random_numbers;
    for (int i = 0; i < 200; ++i) {
        int num = getRandomNumber(1, 1000);
        two_hundred_random_numbers.push_back(num);
        ll3.insert(num);
        bst3.insert(num);
    }
    startLLAppend = chrono::high_resolution_clock::now();
    endLLAppend = chrono::high_resolution_clock::now();
    durationLLAppend = chrono::duration_cast<chrono::microseconds>(endLLAppend - startLLAppend);
    cout << "Linked List Append Time: " << durationLLAppend.count() << " microseconds" << endl;

    searchNum = getRandomNumber(1, 1000);
    startLLSearch = chrono::high_resolution_clock::now();
    llFound = ll3.search(searchNum);
    endLLSearch = chrono::high_resolution_clock::now();
    durationLLSearch = chrono::duration_cast<chrono::microseconds>(endLLSearch - startLLSearch);
    cout << "Linked List Search: Number: " << searchNum << " Found: " << llFound << " Time: " << durationLLSearch.count() << " microseconds" << endl;

    startBSTInsert = chrono::high_resolution_clock::now();
    bst3.insert(searchNum);
    endBSTInsert = chrono::high_resolution_clock::now();
    durationBSTInsert = chrono::duration_cast<chrono::microseconds>(endBSTInsert - startBSTInsert);
    cout << "BST Insert Time: " << durationBSTInsert.count() << " microseconds" << endl;

    startBSTSearch = chrono::high_resolution_clock::now();
    bstFound = bst3.search(searchNum);
    endBSTSearch = chrono::high_resolution_clock::now();
    durationBSTSearch = chrono::duration_cast<chrono::microseconds>(endBSTSearch - startBSTSearch);
    cout << "BST Find: Number: " << searchNum << " Found: " << bstFound << " Time: " << durationBSTSearch.count() << " microseconds" << endl;
    cout << endl;

    // Scenario 4: 1 Through 1k (Backwards)
    cout << "Scenario 4: 1 Through 1k (Backwards)" << endl;
    LinkedList ll4;
    BST bst4;
    for (int i = 1000; i >= 1; --i) {
        ll4.insert(i);
        bst4.insert(i);
    }
    startLLAppend = chrono::high_resolution_clock::now();
    endLLAppend = chrono::high_resolution_clock::now();
    durationLLAppend = chrono::duration_cast<chrono::microseconds>(endLLAppend - startLLAppend);
    cout << "Linked List Append Time: " << durationLLAppend.count() << " microseconds" << endl;

    searchNum = getRandomNumber(1, 1000);
    startLLSearch = chrono::high_resolution_clock::now();
    llFound = ll4.search(searchNum);
    endLLSearch = chrono::high_resolution_clock::now();
    durationLLSearch = chrono::duration_cast<chrono::microseconds>(endLLSearch - startLLSearch);
    cout << "Linked List Search: Number: " << searchNum << " Found: " << llFound << " Time: " << durationLLSearch.count() << " microseconds" << endl;

    startBSTInsert = chrono::high_resolution_clock::now();
    bst4.insert(searchNum);
    endBSTInsert = chrono::high_resolution_clock::now();
    durationBSTInsert = chrono::duration_cast<chrono::microseconds>(endBSTInsert - startBSTInsert);
    cout << "BST Insert Time: " << durationBSTInsert.count() << " microseconds" << endl;

    startBSTSearch = chrono::high_resolution_clock::now();
    bstFound = bst4.search(searchNum);
    endBSTSearch = chrono::high_resolution_clock::now();
    durationBSTSearch = chrono::duration_cast<chrono::microseconds>(endBSTSearch - startBSTSearch);
    cout << "BST Find: Number: " << searchNum << " Found: " << bstFound << " Time: " << durationBSTSearch.count() << " microseconds" << endl;
    cout << endl;

    // Scenario 5: 1 Through 1k (Forwards)
    cout << "Scenario 5: 1 Through 1k (Forwards)" << endl;
    LinkedList ll5;
    BST bst5;
    for (int i = 1; i <= 1000; ++i) {
        ll5.insert(i);
        bst5.insert(i);
    }
    startLLAppend = chrono::high_resolution_clock::now();
    endLLAppend = chrono::high_resolution_clock::now();
    durationLLAppend = chrono::duration_cast<chrono::microseconds>(endLLAppend - startLLAppend);
    cout << "Linked List Append Time: " << durationLLAppend.count() << " microseconds" << endl;

    searchNum = getRandomNumber(1, 1000);
    startLLSearch = chrono::high_resolution_clock::now();
    llFound = ll5.search(searchNum);
    endLLSearch = chrono::high_resolution_clock::now();
    durationLLSearch = chrono::duration_cast<chrono::microseconds>(endLLSearch - startLLSearch);
    cout << "Linked List Search: Number: " << searchNum << " Found: " << llFound << " Time: " << durationLLSearch.count() << " microseconds" << endl;

    startBSTInsert = chrono::high_resolution_clock::now();
    bst5.insert(searchNum);
    endBSTInsert = chrono::high_resolution_clock::now();
    durationBSTInsert = chrono::duration_cast<chrono::microseconds>(endBSTInsert - startBSTInsert);
    cout << "BST Insert Time: " << durationBSTInsert.count() << " microseconds" << endl;

    startBSTSearch = chrono::high_resolution_clock::now();
    bstFound = bst5.search(searchNum);
    endBSTSearch = chrono::high_resolution_clock::now();
    durationBSTSearch = chrono::duration_cast<chrono::microseconds>(endBSTSearch - startBSTSearch);
    cout << "BST Find: Number: " << searchNum << " Found: " << bstFound << " Time: " << durationBSTSearch.count() << " microseconds" << endl;
    cout << endl;

    return 0;
}

