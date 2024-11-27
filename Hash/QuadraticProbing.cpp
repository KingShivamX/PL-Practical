/*
c) Lalit has a fresh mango fruit shop and he wants to store information about 11 varieties of mangoes available
in a table using hash function hash (key) = key mod 11 where key is the number of mangoes of each category.
Write a C++ program to implement hash table for collision handling using quadratic probing without replacement for the following data.
Category 1 2 3 4 5 6 7 8 9 10 11
No of Mangoes 25 15 10 5 11 19 16 36 42 28 32

Chaitanya Retawade
PRN: 202301040251
Div-D    Rollno-231
*/

#include <iostream>
using namespace std;

class HashTable
{
private:
    int table[11];

public:
    HashTable()
    {
        for (int i = 0; i < 11; i++)
        {
            table[i] = -1; // -1 indicates an empty slot
        }
    }

    int hashFunction(int key)
    {
        return key % 11; // hash function: key mod 11
    }

    void insert(int key)
    {
        int index = hashFunction(key);
        int i = 0;

        // Quadratic probing to handle collisions
        while (table[(index + i * i) % 11] != -1)
        {
            i++;
            if (i == 11)
            {
                cout << "Table is full! Cannot insert key " << key << endl;
                return;
            }
        }
        table[(index + i * i) % 11] = key;
        cout << "Inserted " << key << " at index " << (index + i * i) % 11 << endl;
    }

    void display()
    {
        cout << "Hash Table: ";
        for (int i = 0; i < 11; i++)
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
    int mangoCategories[] = {25, 15, 10, 5, 11, 19, 16, 36, 42, 28, 32};
    for (int i = 0; i < 11; i++)
    {
        ht.insert(mangoCategories[i]);
    }
    ht.display();
    return 0;
}