#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

class HashTable {
    Node* table[12];
    int tableSize;

public:
    HashTable() : tableSize(12) {
        for (int i = 0; i < tableSize; i++) table[i] = nullptr;
    }

    void insert(int key) {
        int index = key % tableSize;
        Node* newNode = new Node(key);
        newNode->next = table[index];
        table[index] = newNode;
    }

    void display() {
        for (int i = 0; i < tableSize; i++) {
            Node* temp = table[i];
            while (temp) {
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << endl;
        }
    }
};

int main() {
    HashTable hashTable;
    int data[] = {10, 5, 4, 14, 15, 20, 1, 11, 6, 16, 36, 28};
    int n = 12;
    for (int i = 0; i < n; i++) hashTable.insert(data[i]);
    hashTable.display();
}
