#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    Node* next; 
    string name;
    string gender;
    int age;

    Node(string name, string gender, int age) {
        this->name = name;
        this->gender = gender;
        this->age = age;
        next = NULL;
    }

    ~Node() {}
};

class train {
public:
    string from; 
    string to;
    Node* head;   
    const int maxTickit  = 6;      
    int curTickit;

    train(string from, string to){
        head = NULL;
        this->from = from;
        this->to = to;
        curTickit = 0;
    }

    ~train() {
        if (head) {
            Node* temp = head;
            Node* nextNode = NULL;
            do {
                nextNode = temp->next;
                delete temp; 
                temp = nextNode;
            } while (temp != head);
            head = NULL;
        }
    }    

    void bookTicket(string name, string gender, int age) {
        if (curTickit >= maxTickit){
            cout << "The booking for the train " << from << " to " << to << " has been full" << endl;
            return;
        }

        Node* newNode = new Node(name, gender, age);
        if(head == NULL){
            head = newNode;
            newNode->next = head;
        } else {
            Node* temp = head;
            while(temp->next != head){
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head;
        }

        curTickit++;
        cout << endl;
        cout << "Tickit from " << from << " to " << to << " has been booked for " << name << " !" << endl;
    }

    void cancelTicket() {
        if (head == NULL) {
            cout << "The train from " << from << " to " << to << " has no reseeravtion to cancel" << endl;
            return;
        }

        Node* temp = head;
        if (temp->next == head) {
            cout << "Ticket canceled for pasanger " << head->name  << ", of train from " << from << " to " << to << endl;
            delete head;
            head = NULL;
        } else {
            while (temp->next->next != head) {
                temp = temp->next;
            }
            Node* toDelete = temp->next;
            cout << "Ticket canceled for pasanger " << head->name  << ", of train from " << from << " to " << to << endl;
            temp->next = head;
            delete toDelete;
        }
        curTickit--;
    }

    void displayTicket() {
        if (head == NULL) {
            cout << "The train from " << from << " to " << to << " has no reseeravtion to show" << endl;
            return;
        }

        cout << "Bookings for the train from " << from << " to " << to << " has these pasangers" << endl;
        Node* temp = head;
        do {
            cout << "Passenger: " << temp->name << ", Gender: " << temp->gender << ", Age: " << temp->age << endl;
            temp = temp->next;
        } while (temp != head);
    }

};

int main() {
    string from, to;
    cout << "Enter the source station: ";
    cin >> from;
    cout << "Enter the destination station: ";
    cin >> to;

    train myTrain(from, to);

    int choice;
    string name, gender;
    int age;

    do {
        cout << "\n--- Railway Reservation System ---\n";
        cout << "1. Book Ticket\n";
        cout << "2. Cancel Ticket\n";
        cout << "3. Display Tickets\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter passenger name: ";
                cin >> name;
                cout << "Enter gender: ";
                cin >> gender;
                cout << "Enter age: ";
                cin >> age;
                myTrain.bookTicket(name, gender, age);
                break;
            case 2:
                myTrain.cancelTicket();
                break;
            case 3:
                myTrain.displayTicket();
                break;
            case 4:
                cout << "Exiting the system. Thank you!\n";
                break;
            default:
                cout << "Invalid choice! Please select a valid option.\n";
        }
    } while (choice != 4);

    return 0;
}