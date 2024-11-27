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