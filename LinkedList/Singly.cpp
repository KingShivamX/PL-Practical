#include <iostream>
using namespace std;

class node
{
public:
    string name, branch;
    int PRN;
    int cgpa, Marks;
    node *next;
};

class linkedList
{
    node *head;

public:
    linkedList() { head = NULL; }

    // Function declarations
    void create_list();
    void display_list();
    void insert_at_begin();
    void insert_at_end();
    void insert_at_pos();
    void insert_by_value();
    void delete_at_first();
    void delete_at_end();
    void delete_by_position();
    void delete_by_value();
    void bubble_sort();
    void search_node();
};

void linkedList::create_list()
{
    node *temp = NULL;
    int choice = 1;
    node *p = NULL;

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
            p->next = temp;
            p = p->next;
        }
        cout << "Do you want to continue? 1.Yes, 0.No: ";
        cin >> choice;
    }
    cout << endl;
}

void linkedList::display_list()
{
    node *p = head;
    if (head == NULL)
    {
        cout << "The list is empty" << endl;
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

void linkedList::insert_at_begin()
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
    head = temp;
    cout << "Node inserted at the beginning." << endl;
}

void linkedList::insert_at_end()
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
        head = temp;
    }
    else
    {
        while (p->next != NULL)
            p = p->next;
        p->next = temp;
    }
    cout << "Node inserted at the end." << endl;
}

void linkedList::insert_at_pos()
{
    int position;
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

    cout << "Enter the position to insert: ";
    cin >> position;

    if (position == 1)
    {
        temp->next = head;
        head = temp;
    }
    else
    {
        for (int i = 1; i < position - 1 && p != NULL; i++)
            p = p->next;

        if (p == NULL)
        {
            cout << "Position out of range." << endl;
        }
        else
        {
            temp->next = p->next;
            p->next = temp;
        }
    }
    cout << "Node inserted at position " << position << "." << endl;
}

void linkedList::delete_at_first()
{
    if (head == NULL)
    {
        cout << "List is empty. No node to delete." << endl;
        return;
    }

    node *temp = head;
    head = head->next;
    delete temp;

    cout << "First node deleted." << endl;
}

void linkedList::delete_at_end()
{
    if (head == NULL)
    {
        cout << "List is empty. No node to delete." << endl;
        return;
    }

    if (head->next == NULL)
    {
        delete head;
        head = NULL;
    }
    else
    {
        node *p = head, *q = NULL;
        while (p->next != NULL)
        {
            q = p;
            p = p->next;
        }
        q->next = NULL;
        delete p;
    }

    cout << "Last node deleted." << endl;
}

void linkedList::delete_by_position()
{
    int position;
    cout << "Enter the position of the node to delete: ";
    cin >> position;

    if (head == NULL)
    {
        cout << "List is empty. No node to delete." << endl;
        return;
    }

    if (position == 1)
    {
        node *temp = head;
        head = head->next;
        delete temp;
    }
    else
    {
        node *p = head, *q = NULL;
        for (int i = 1; i < position && p != NULL; i++)
        {
            q = p;
            p = p->next;
        }

        if (p == NULL)
        {
            cout << "Position out of range." << endl;
        }
        else
        {
            q->next = p->next;
            delete p;
        }
    }
    cout << "Node at position " << position << " deleted." << endl;
}

void linkedList::delete_by_value()
{
    int value;
    cout << "Enter the PRN of the node to delete: ";
    cin >> value;

    if (head == NULL)
    {
        cout << "List is empty. No node to delete." << endl;
        return;
    }

    if (head->PRN == value)
    {
        node *temp = head;
        head = head->next;
        delete temp;
        cout << "Node with PRN " << value << " deleted." << endl;
        return;
    }

    node *p = head, *q = NULL;
    while (p != NULL && p->PRN != value)
    {
        q = p;
        p = p->next;
    }

    if (p == NULL)
    {
        cout << "Value not found." << endl;
    }
    else
    {
        q->next = p->next;
        delete p;
        cout << "Node with PRN " << value << " deleted." << endl;
    }
}

void linkedList::bubble_sort()
{
    if (head == NULL || head->next == NULL)
        return;

    node *p = NULL, *q = NULL;
    int swapped;
    do
    {
        swapped = 0;
        p = head;
        while (p->next != q)
        {
            if (p->PRN > p->next->PRN)
            {
                swap(p->name, p->next->name);
                swap(p->branch, p->next->branch);
                swap(p->PRN, p->next->PRN);
                swap(p->cgpa, p->next->cgpa);
                swap(p->Marks, p->next->Marks);
                swapped = 1;
            }
            p = p->next;
        }
        q = p;
    } while (swapped);

    cout << "List sorted by PRN." << endl;
}

void linkedList::search_node()
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
    linkedList L1;
    int choice;

    do
    {
        cout << "Menu:" << endl;
        cout << "1. Create list" << endl;
        cout << "2. Display list" << endl;
        cout << "3. Insert at beginning" << endl;
        cout << "4. Insert at end" << endl;
        cout << "5. Insert at position" << endl;
        cout << "6. Delete first node" << endl;
        cout << "7. Delete last node" << endl;
        cout << "8. Delete by position" << endl;
        cout << "9. Delete by value" << endl;
        cout << "10. Sort list by PRN" << endl;
        cout << "11. Search for a node" << endl;
        cout << "12. Exit" << endl;

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
            L1.insert_at_begin();
            break;
        case 4:
            L1.insert_at_end();
            break;
        case 5:
            L1.insert_at_pos();
            break;
        case 6:
            L1.delete_at_first();
            break;
        case 7:
            L1.delete_at_end();
            break;
        case 8:
            L1.delete_by_position();
            break;
        case 9:
            L1.delete_by_value();
            break;
        case 10:
            L1.bubble_sort();
            break;
        case 11:
            L1.search_node();
            break;
        case 12:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
            break;
        }
    } while (choice != 12);

    return 0;
}