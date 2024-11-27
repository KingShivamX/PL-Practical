#include <iostream>
using namespace std;

class node
{
public:
    string name, branch;
    int PRN, cgpa, Marks;
    node *next;
};

class circularLinkedList
{
    node *head;

public:
    circularLinkedList() { head = NULL; }

    // Function declarations
    void create_list();
    void display_list();
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

void circularLinkedList::create_list()
{
    node *temp = NULL, *p = NULL;
    int choice = 1;

    while (choice != 0)
    {
        temp = new node();
        cout << "Enter the details:" << endl;
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

        if (head == NULL)
        {
            head = temp;
            head->next = head; // Point to itself to create the circular structure
        }
        else
        {
            p = head;
            while (p->next != head)
                p = p->next;

            p->next = temp;
            temp->next = head;
        }

        cout << "Do you want to continue? 1.Yes, 0.No: ";
        cin >> choice;
    }
    cout << endl;
}

void circularLinkedList::display_list()
{
    if (head == NULL)
    {
        cout << "The list is empty." << endl;
        return;
    }

    node *p = head;
    do
    {
        cout << "Name: " << p->name << endl;
        cout << "Branch: " << p->branch << endl;
        cout << "PRN No.: " << p->PRN << endl;
        cout << "CGPA: " << p->cgpa << endl;
        cout << "Marks: " << p->Marks << endl;
        p = p->next;
    } while (p != head);
    cout << endl;
}

void circularLinkedList::insert_at_begin()
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

    if (head == NULL)
    {
        head = temp;
        head->next = head; // Point to itself
    }
    else
    {
        node *p = head;
        while (p->next != head)
            p = p->next;

        temp->next = head;
        p->next = temp;
        head = temp;
    }
    cout << "Node inserted at the beginning." << endl;
}

void circularLinkedList::insert_at_end()
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

    if (head == NULL)
    {
        head = temp;
        head->next = head; // Point to itself
    }
    else
    {
        node *p = head;
        while (p->next != head)
            p = p->next;

        p->next = temp;
        temp->next = head;
    }
    cout << "Node inserted at the end." << endl;
}

void circularLinkedList::insert_at_pos()
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

    node *p = head;
    for (int i = 1; i < position - 1 && p->next != head; i++)
        p = p->next;

    if (p->next == head && position != 1)
    {
        cout << "Position out of range." << endl;
        return;
    }

    temp->next = p->next;
    p->next = temp;
    cout << "Node inserted at position " << position << "." << endl;
}

void circularLinkedList::delete_at_first()
{
    if (head == NULL)
    {
        cout << "List is empty. No node to delete." << endl;
        return;
    }

    node *p = head;
    while (p->next != head)
        p = p->next;

    if (head->next == head) // Only one node
    {
        delete head;
        head = NULL;
    }
    else
    {
        node *temp = head;
        p->next = head->next;
        head = head->next;
        delete temp;
    }
    cout << "First node deleted." << endl;
}

void circularLinkedList::delete_at_end()
{
    if (head == NULL)
    {
        cout << "List is empty. No node to delete." << endl;
        return;
    }

    node *p = head, *q = NULL;
    while (p->next != head)
    {
        q = p;
        p = p->next;
    }

    if (p == head) // Only one node
    {
        delete head;
        head = NULL;
    }
    else
    {
        q->next = head;
        delete p;
    }
    cout << "Last node deleted." << endl;
}

void circularLinkedList::delete_by_position()
{
    int position;
    cout << "Enter the position of the node to delete: ";
    cin >> position;

    if (position == 1)
    {
        delete_at_first();
        return;
    }

    node *p = head, *q = NULL;
    for (int i = 1; i < position && p->next != head; i++)
    {
        q = p;
        p = p->next;
    }

    if (p->next == head && position != 1)
    {
        cout << "Position out of range." << endl;
    }
    else
    {
        q->next = p->next;
        delete p;
        cout << "Node at position " << position << " deleted." << endl;
    }
}

void circularLinkedList::delete_by_value()
{
    int value;
    cout << "Enter the PRN of the node to delete: ";
    cin >> value;

    node *p = head, *q = NULL;

    if (head == NULL)
    {
        cout << "List is empty." << endl;
        return;
    }

    do
    {
        if (p->PRN == value)
        {
            if (p == head)
            {
                delete_at_first();
                return;
            }
            else
            {
                q->next = p->next;
                delete p;
                cout << "Node with PRN " << value << " deleted." << endl;
                return;
            }
        }
        q = p;
        p = p->next;
    } while (p != head);

    cout << "Node with PRN " << value << " not found." << endl;
}

void circularLinkedList::bubble_sort()
{
    if (head == NULL || head->next == head)
        return;

    node *end = NULL;

    do
    {
        node *p = head;
        node *q = NULL;

        while (p->next != end && p->next != head)
        {
            if (p->PRN > p->next->PRN)
            {
                swap(p->name, p->next->name);
                swap(p->branch, p->next->branch);
                swap(p->PRN, p->next->PRN);
                swap(p->cgpa, p->next->cgpa);
                swap(p->Marks, p->next->Marks);
            }
            q = p;
            p = p->next;
        }
        end = q;
    } while (end != head);

    cout << "List sorted by PRN." << endl;
}

void circularLinkedList::search_node()
{
    int value;
    cout << "Enter the PRN to search: ";
    cin >> value;

    node *p = head;

    if (head == NULL)
    {
        cout << "List is empty." << endl;
        return;
    }

    do
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
    } while (p != head);

    cout << "Node with PRN " << value << " not found." << endl;
}

int main()
{
    circularLinkedList L1;
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