#include <iostream>
using namespace std;

class node
{
public:
    string name, branch;
    int PRN, cgpa, Marks;
    node *next, *prev;
};

class doublyLinkedList
{
    node *head;

public:
    doublyLinkedList() { head = NULL; }

    // Function declarations
    void create_list();
    void display_list();
    void display_reverse();
    void insert_at_begin();
    void insert_at_end();
    void insert_at_pos();
    void delete_at_first();
    void delete_at_end();
    void delete_by_position();
    void delete_by_value();
    void bubble_sort();
    void search_node();
};

void doublyLinkedList::create_list()
{
    node *temp = NULL, *p = NULL;
    int choice = 1;

    while (choice != 0)
    {
        if (head == NULL)
        {
            head = new node();
            cout << "Enter the details:" << endl;
            cout << "Name: ";
            cin >> head->name;
            cout << "Branch: ";
            cin >> head->branch;
            cout << "PRN No.: ";
            cin >> head->PRN;
            cout << "CGPA: ";
            cin >> head->cgpa;
            cout << "Marks: ";
            cin >> head->Marks;
            head->next = NULL;
            head->prev = NULL;
            p = head;
        }
        else
        {
            temp = new node();
            cout << "Enter details:" << endl;
            cout << "Name: ";
            cin >> temp->name;
            cout << "Branch: ";
            cin >> temp->branch;
            cout << "PRN No.: ";
            cin >> temp->PRN;
            cout << "CGPA: ";
            cin >> temp->cgpa;
            cout << "Marks: ";
            cin >> temp->Marks;

            temp->next = NULL;
            temp->prev = p;
            p->next = temp;
            p = temp;
        }

        cout << "Do you want to continue? 1.Yes, 0.No: ";
        cin >> choice;
    }
    cout << endl;
}

void doublyLinkedList::display_list()
{
    node *p = head;
    if (head == NULL)
    {
        cout << "The list is empty." << endl;
        return;
    }

    while (p != NULL)
    {
        cout << "Name: " << p->name << endl;
        cout << "Branch: " << p->branch << endl;
        cout << "PRN No.: " << p->PRN << endl;
        cout << "CGPA: " << p->cgpa << endl;
        cout << "Marks: " << p->Marks << endl;
        p = p->next;
    }
    cout << endl;
}

void doublyLinkedList::display_reverse()
{
    if (head == NULL)
    {
        cout << "The list is empty." << endl;
        return;
    }

    // Move to the last node
    node *p = head;
    while (p->next != NULL)
        p = p->next;

    // Traverse backward
    while (p != NULL)
    {
        cout << "Name: " << p->name << endl;
        cout << "Branch: " << p->branch << endl;
        cout << "PRN No.: " << p->PRN << endl;
        cout << "CGPA: " << p->cgpa << endl;
        cout << "Marks: " << p->Marks << endl;
        p = p->prev;
    }
    cout << endl;
}

void doublyLinkedList::insert_at_begin()
{
    node *temp = new node();
    cout << "Enter the details of the new node:" << endl;
    cout << "Name: ";
    cin >> temp->name;
    cout << "PRN No.: ";
    cin >> temp->PRN;
    cout << "Branch: ";
    cin >> temp->branch;
    cout << "CGPA: ";
    cin >> temp->cgpa;
    cout << "Marks: ";
    cin >> temp->Marks;

    temp->next = head;
    temp->prev = NULL;

    if (head != NULL)
        head->prev = temp;

    head = temp;
    cout << "Node inserted at the beginning." << endl;
}

void doublyLinkedList::insert_at_end()
{
    node *temp = new node();
    node *p = head;

    cout << "Enter the details of the new node:" << endl;
    cout << "Name: ";
    cin >> temp->name;
    cout << "PRN No.: ";
    cin >> temp->PRN;
    cout << "Branch: ";
    cin >> temp->branch;
    cout << "CGPA: ";
    cin >> temp->cgpa;
    cout << "Marks: ";
    cin >> temp->Marks;

    temp->next = NULL;

    if (head == NULL)
    {
        temp->prev = NULL;
        head = temp;
    }
    else
    {
        while (p->next != NULL)
            p = p->next;

        p->next = temp;
        temp->prev = p;
    }
    cout << "Node inserted at the end." << endl;
}

void doublyLinkedList::insert_at_pos()
{
    int position;
    cout << "Enter the position to insert: ";
    cin >> position;

    if (position == 1)
    {
        insert_at_begin();
        return;
    }

    node *temp = new node();
    node *p = head;

    cout << "Enter the details of the new node:" << endl;
    cout << "Name: ";
    cin >> temp->name;
    cout << "PRN No.: ";
    cin >> temp->PRN;
    cout << "Branch: ";
    cin >> temp->branch;
    cout << "CGPA: ";
    cin >> temp->cgpa;
    cout << "Marks: ";
    cin >> temp->Marks;

    for (int i = 1; i < position - 1 && p != NULL; i++)
        p = p->next;

    if (p == NULL)
    {
        cout << "Position out of range." << endl;
    }
    else
    {
        temp->next = p->next;
        if (p->next != NULL)
            p->next->prev = temp;
        temp->prev = p;
        p->next = temp;
        cout << "Node inserted at position " << position << "." << endl;
    }
}

void doublyLinkedList::delete_at_first()
{
    if (head == NULL)
    {
        cout << "List is empty. No node to delete." << endl;
        return;
    }

    node *temp = head;
    head = head->next;

    if (head != NULL)
        head->prev = NULL;

    delete temp;
    cout << "First node deleted." << endl;
}

void doublyLinkedList::delete_at_end()
{
    if (head == NULL)
    {
        cout << "List is empty. No node to delete." << endl;
        return;
    }

    node *p = head;
    while (p->next != NULL)
        p = p->next;

    if (p->prev != NULL)
        p->prev->next = NULL;
    else
        head = NULL;

    delete p;
    cout << "Last node deleted." << endl;
}

void doublyLinkedList::delete_by_position()
{
    int position;
    cout << "Enter the position of the node to delete: ";
    cin >> position;

    if (position == 1)
    {
        delete_at_first();
        return;
    }

    node *p = head;
    for (int i = 1; i < position && p != NULL; i++)
        p = p->next;

    if (p == NULL)
    {
        cout << "Position out of range." << endl;
    }
    else
    {
        if (p->prev != NULL)
            p->prev->next = p->next;

        if (p->next != NULL)
            p->next->prev = p->prev;

        delete p;
        cout << "Node at position " << position << " deleted." << endl;
    }
}

void doublyLinkedList::delete_by_value()
{
    int value;
    cout << "Enter the PRN of the node to delete: ";
    cin >> value;

    node *p = head;
    while (p != NULL && p->PRN != value)
        p = p->next;

    if (p == NULL)
    {
        cout << "Value not found." << endl;
    }
    else
    {
        if (p->prev != NULL)
            p->prev->next = p->next;

        if (p->next != NULL)
            p->next->prev = p->prev;

        if (p == head)
            head = p->next;

        delete p;
        cout << "Node with PRN " << value << " deleted." << endl;
    }
}

void doublyLinkedList::bubble_sort()
{
    if (head == NULL || head->next == NULL)
        return;

    node *i = head, *j = NULL;
    int swapped;

    do
    {
        swapped = 0;
        i = head;

        while (i->next != j)
        {
            if (i->PRN > i->next->PRN)
            {
                swap(i->PRN, i->next->PRN);
                swap(i->name, i->next->name);
                swap(i->branch, i->next->branch);
                swap(i->cgpa, i->next->cgpa);
                swap(i->Marks, i->next->Marks);
                swapped = 1;
            }
            i = i->next;
        }
        j = i;
    } while (swapped);
    cout << "List sorted by PRN." << endl;
}

void doublyLinkedList::search_node()
{
    int value;
    cout << "Enter the PRN to search: ";
    cin >> value;

    node *p = head;
    while (p != NULL)
    {
        if (p->PRN == value)
        {
            cout << "Node found:" << endl;
            cout << "Name: " << p->name << endl;
            cout << "Branch: " << p->branch << endl;
            cout << "CGPA: " << p->cgpa << endl;
            cout << "Marks: " << p->Marks << endl;
            return;
        }
        p = p->next;
    }
    cout << "Node with PRN " << value << " not found." << endl;
}

int main()
{
    doublyLinkedList L1;
    int choice;

    do
    {
        cout << "Menu:" << endl;
        cout << "1. Create list" << endl;
        cout << "2. Display list" << endl;
        cout << "3. Display list in reverse" << endl;
        cout << "4. Insert at beginning" << endl;
        cout << "5. Insert at end" << endl;
        cout << "6. Insert at position" << endl;
        cout << "7. Delete first node" << endl;
        cout << "8. Delete last node" << endl;
        cout << "9. Delete by position" << endl;
        cout << "10. Delete by value" << endl;
        cout << "11. Sort list by PRN" << endl;
        cout << "12. Search for a node" << endl;
        cout << "13. Exit" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            L1.create_list();
            break;
        case 2:
            L1.display_list();
            break;
        case 3:
            L1.display_reverse();
            break;
        case 4:
            L1.insert_at_begin();
            break;
        case 5:
            L1.insert_at_end();
            break;
        case 6:
            L1.insert_at_pos();
            break;
        case 7:
            L1.delete_at_first();
            break;
        case 8:
            L1.delete_at_end();
            break;
        case 9:
            L1.delete_by_position();
            break;
        case 10:
            L1.delete_by_value();
            break;
        case 11:
            L1.bubble_sort();
            break;
        case 12:
            L1.search_node();
            break;
        case 13:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
            break;
        }
    } while (choice != 13);

    return 0;
}