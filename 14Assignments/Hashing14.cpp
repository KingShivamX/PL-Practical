#include <iostream>
using namespace std;

class HashTable {
    int table[9];
    int tableSize;

public:
    HashTable() : tableSize(9) {
        for (int i = 0; i < tableSize; i++) table[i] = -1;
    }

    void insert(int key) {
        int index = key % tableSize;
        while (table[index] != -1) index = (index + 1) % tableSize;
        table[index] = key;
    }

    void display() {
        for (int i = 0; i < tableSize; i++) cout << table[i] << " ";
    }
};

int main() {
    HashTable hashTable;
    int data[] = {10, 5, 4, 14, 15, 20, 1, 11, 6, 16, 36, 28};
    int n = 12;
    for (int i = 0; i < n; i++) hashTable.insert(data[i]);
    hashTable.display();
}
