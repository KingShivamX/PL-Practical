/*
b) Marks out of 100 of 20 students needs to be stored in a table using hash function hash (key) = key mod 20
where key is the data to be inserted into the Hash table. Write a C++ program to implement hash table for collision
handling using separate chaining without replacement using linked list for the following
data :- 33,56,78,12,10,67,89,99,100,23,45,71,39,62,59,90,91,20,75,66.

Chaitanya Retawade
PRN: 202301040251
Div-D    Rollno-231
*/

#include <iostream>
#include <list>
using namespace std;

class HashTable
{
private:
    list<int> *table;
    int size;

public:
    HashTable(int size)
    {
        this->size = size;
        table = new list<int>[size];
    }

    int hashFunction(int key)
    {
        return key % size; // hash function: key mod 20
    }

    void insert(int key)
    {
        int index = hashFunction(key);
        table[index].push_back(key); // Insert the key into the corresponding list
    }

    void display()
    {
        for (int i = 0; i < size; i++)
        {
            if (table[i].size() > 0)
            {
                cout << "Index " << i << ": ";
                for (int key : table[i])
                {
                    cout << key << " ";
                }
                cout << endl;
            }
        }
    }
};

int main()
{
    HashTable ht(20);
    int marks[] = {33, 56, 78, 12, 10, 67, 89, 99, 100, 23, 45, 71, 39, 62, 59, 90, 91, 20, 75, 66};
    for (int i = 0; i < 20; i++)
    {
        ht.insert(marks[i]);
    }
    ht.display();
    return 0;
}

#include <iostream>
using namespace std;

// Node structure for the linked list
struct Node {
    int data;
    Node* next;
};

// HashTable class using chaining
class HashTable {
private:
    int size;         // Size of the hash table
    Node** table;     // Array of linked lists (table)

    // Hash function
    int hashFunction(int key) {
        return key % size;
    }

public:
    // Constructor
    HashTable(int tableSize) {
        size = tableSize;
        table = new Node*[size];
        for (int i = 0; i < size; i++) {
            table[i] = nullptr; // Initialize each slot as null
        }
    }

    // Destructor
    ~HashTable() {
        for (int i = 0; i < size; i++) {
            Node* current = table[i];
            while (current) {
                Node* temp = current;
                current = current->next;
                delete temp;
            }
        }
        delete[] table;
    }

    // Insert a key into the hash table
    void insert(int key) {
        int index = hashFunction(key);
        Node* newNode = new Node{key, nullptr};

        if (table[index] == nullptr) {
            table[index] = newNode; // Insert directly if no collision
        } else {
            // Handle collision by chaining
            Node* current = table[index];
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    // Search for a key in the hash table
    bool search(int key) {
        int index = hashFunction(key);
        Node* current = table[index];
        while (current) {
            if (current->data == key)
                return true;
            current = current->next;
        }
        return false;
    }

    // Remove a key from the hash table
    void remove(int key) {
        int index = hashFunction(key);
        Node* current = table[index];
        Node* prev = nullptr;

        while (current) {
            if (current->data == key) {
                if (prev == nullptr) {
                    table[index] = current->next; // Remove head node
                } else {
                    prev->next = current->next; // Remove intermediate node
                }
                delete current;
                cout << "Key " << key << " removed from hash table.\n";
                return;
            }
            prev = current;
            current = current->next;
        }
        cout << "Key " << key << " not found in hash table.\n";
    }

    // Display the hash table
    void display() {
        for (int i = 0; i < size; i++) {
            cout << "Slot " << i << ": ";
            Node* current = table[i];
            while (current) {
                cout << current->data << " -> ";
                current = current->next;
            }
            cout << "NULL\n";
        }
    }
};

// Main function to test the HashTable
int main() {
    HashTable ht(7); // Hash table with 7 slots

    ht.insert(10);
    ht.insert(20);
    ht.insert(15);
    ht.insert(30);
    ht.insert(5);

    cout << "Hash table after insertion:\n";
    ht.display();

    cout << "\nSearch for key 15: " << (ht.search(15) ? "Found" : "Not Found") << endl;
    cout << "Search for key 25: " << (ht.search(25) ? "Found" : "Not Found") << endl;

    ht.remove(15);
    ht.remove(25);

    cout << "\nHash table after deletion:\n";
    ht.display();

    return 0;
}
