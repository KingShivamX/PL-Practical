/*
a) Raman has a cold drink corner shop in he wants to store information about different flavours of cold drink
available in a table using hash function hash (key) = key mod 6 where key is the data to be inserted into the
Hash table. Write a C++ program to implement hash table for collision handling using linear probing without chaining
without replacement.

Chaitanya Retawade
PRN: 202301040251
Div-D    Rollno-231
*/

#include <iostream>
using namespace std;

class HashTable
{
private:
    int table[6];

public:
    HashTable()
    {
        for (int i = 0; i < 6; i++)
        {
            table[i] = -1; // -1 indicates an empty slot
        }
    }

    int hashFunction(int key)
    {
        return key % 6; // hash function: key mod 6
    }

    void insert(int key)
    {
        int index = hashFunction(key);

        // Linear probing to handle collisions
        int i = 0;
        while (table[(index + i) % 6] != -1)
        {
            i++;
            if (i == 6)
            {
                cout << "Table is full! Cannot insert key " << key << endl;
                return;
            }
        }
        table[(index + i) % 6] = key;
        cout << "Inserted " << key << " at index " << (index + i) % 6 << endl;
    }

    void display()
    {
        cout << "Hash Table: ";
        for (int i = 0; i < 6; i++)
        {
            if (table[i] == -1)
                cout << "Empty ";
            else
                cout << table[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    HashTable ht;
    ht.insert(33);
    ht.insert(56);
    ht.insert(78);
    ht.insert(12);
    ht.insert(10);
    ht.insert(67);
    ht.display();
    return 0;
}