#include <iostream>
#include <ctime>
#include <cstdlib>
#include <chrono>

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
    // Seed for random number generation
    srand(time(nullptr));

    // Generate random numbers
    int max_ct = 15;
    int max_rand = 1000;

    cout << "Random Numbers:\n";
    for (int i = 0; i < max_ct; i++) {
        cout << getRandomNumber(1, max_rand) << endl;
    }

    // Sample scenarios
    int scenarios[5][2] = {
        {12, 12},
        {24, 24},
        {200, 1},
        {1000, 1},
        {1, 1000}
    };

    for (int i = 0; i < 5; ++i) {
        int dataSize = scenarios[i][0];
        int searchValue = scenarios[i][1];

        // Populate Linked List and BST with random numbers
        LinkedList ll;
        BST bst;

        // Insertion phase
        auto startInsertion = chrono::high_resolution_clock::now();
        for (int j = 0; j < dataSize; ++j) {
            int randomNum = getRandomNumber(1, 1000);
            ll.insert(randomNum);
            bst.insert(randomNum);
        }
        auto endInsertion = chrono::high_resolution_clock::now();
        double insertionTime = chrono::duration_cast<chrono::microseconds>(endInsertion - startInsertion).count() / 1e6;

        // Search phase - Linked List
        auto startLLSearch = chrono::high_resolution_clock::now();
        bool llFound = ll.search(searchValue);
        auto endLLSearch = chrono::high_resolution_clock::now();
        double llSearchTime = chrono::duration_cast<chrono::microseconds>(endLLSearch - startLLSearch).count() / 1e6;

        // Search phase - BST
        auto startBSTSearch = chrono::high_resolution_clock::now();
        bool bstFound = bst.search(searchValue);
        auto endBSTSearch = chrono::high_resolution_clock::now();
        double bstSearchTime = chrono::duration_cast<chrono::microseconds>(endBSTSearch - startBSTSearch).count() / 1e6;

        cout << "Scenario " << i + 1 << ":\n";
        cout << "Insertion time (Linked List): " << insertionTime << " seconds\n";
        cout << "Search time (Linked List): " << llSearchTime << " seconds. Found: " << boolalpha << llFound << "\n";
        cout << "Search time (BST): " << bstSearchTime << " seconds. Found: " << boolalpha << bstFound << "\n\n";
    }

    // Measuring execution time using high-resolution clocks
    auto start_time = chrono::high_resolution_clock::now();

    // Your code here

    auto end_time = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(end_time - start_time);
    long microseconds = duration.count();

    cout << "Time taken by code segment: " << microseconds << " microseconds." << endl;

    return 0;
}

