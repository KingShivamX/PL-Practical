#include<iostream>
#include<cstring>
using namespace std;

class Node {
    int price;
    char product_name[100];
    Node* previous;
    Node* next;

public:
    Node* createnode();
    Node* createdll(Node* h);
    void displaydll(Node* h);
    Node* mergealternate(Node* dll_1, Node* dll_2);
    Node* sort(Node* head);
};

Node* Node::createnode() {
    Node* temp = new Node();
    cout << "Enter product name: ";
    cin >> temp->product_name;
    cout << "Enter price: ";
    cin >> temp->price;
    temp->previous = NULL;
    temp->next = NULL;
    return temp;
}

Node* Node::createdll(Node* h) {
    Node* t;
    int n;
    cout << "Enter number of nodes: ";
    cin >> n;

    for (int i = 1; i <= n; i++) {
        t = createnode();
        if (h == NULL) {
            h = t;
        } else {
            t->next = h;
            h->previous = t;
            h = t;
        }
    }
    return h;
}

void Node::displaydll(Node* h) {
    Node* t = h;
    cout << "Double linked list is: " << endl;
    while (t != NULL) {
        cout << "Product Name: " << t->product_name << " -> ";
        cout << "Price: " << t->price << " -> ";
        t = t->next;
    }
    cout << "NULL" << endl;
}

Node* Node::mergealternate(Node* dll_1, Node* dll_2) {
    if (dll_1 == NULL) return dll_2;
    if (dll_2 == NULL) return dll_1;

    Node* P1 = dll_1;
    Node* P2 = dll_2;
    Node* next1, *next2;

    while (P1 != NULL && P2 != NULL) {
        next1 = P1->next;
        next2 = P2->next;
        P1->next = P2;
        P2->previous = P1;

        if (next1 != NULL) {
            P2->next = next1;
            next1->previous = P2;
        }

        P1 = next1;
        P2 = next2;
    }

    return dll_1;
}

Node* Node::sort(Node* head) {
    if (head == NULL) return head;

    bool swapped;
    Node* ptr1;
    Node* lptr = NULL;

    do {
        swapped = false;
        ptr1 = head;

        while (ptr1->next != lptr) {
            if (ptr1->price > ptr1->next->price) {
                swap(ptr1->price, ptr1->next->price);
                swap(ptr1->product_name, ptr1->next->product_name);
                swapped = true;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);

    return head;
}

int main() {
    Node dll;
    Node *head1 = NULL, *head2 = NULL, *mergedList = NULL;

    cout << "Create first double linked list:" << endl;
    head1 = dll.createdll(head1);

    cout << "Create second double linked list:" << endl;
    head2 = dll.createdll(head2);

    cout << "First doubly linked list (before merging):" << endl;
    dll.displaydll(head1);

    cout << "Second doubly linked list (before merging):" << endl;
    dll.displaydll(head2);

    mergedList = dll.mergealternate(head1, head2);
    cout << "Merged doubly linked list (before sorting):" << endl;
    dll.displaydll(mergedList);

    mergedList = dll.sort(mergedList);
    cout << "Merged doubly linked list (after sorting):" << endl;
    dll.displaydll(mergedList);

    return 0;
}
