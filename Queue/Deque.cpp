#include <iostream>
using namespace std;

const int MAX_SIZE = 10;

class Deque
{
private:
    int front, back;
    string arr[MAX_SIZE];
    bool isInputRestricted;

public:
    Deque(bool inputRestricted);

    void addFront(const string &item);
    void addBack(const string &item);
    string removeFront();
    string removeBack();
    void display();
};

Deque::Deque(bool inputRestricted)
{
    front = back = -1;
    isInputRestricted = inputRestricted;
}

void Deque::addFront(const string &item)
{
    if ((front == 0 && back == MAX_SIZE - 1) || (front == back + 1))
    {
        cout << "Deque is full. Cannot add." << endl;
        return;
    }

    if (front == -1)
    {
        front = back = 0;
    }
    else if (front == 0)
    {
        front = MAX_SIZE - 1;
    }
    else
    {
        front--;
    }

    arr[front] = item;
    cout << "Added " << item << " at the front." << endl;
}

void Deque::addBack(const string &item)
{
    if ((front == 0 && back == MAX_SIZE - 1) || (front == back + 1))
    {
        cout << "Deque is full. Cannot add." << endl;
        return;
    }

    if (front == -1)
    {
        front = back = 0;
    }
    else if (back == MAX_SIZE - 1)
    {
        back = 0;
    }
    else
    {
        back++;
    }

    arr[back] = item;
    cout << "Added " << item << " at the back." << endl;
}

string Deque::removeFront()
{
    if (front == -1)
    {
        cout << "Deque is empty. Cannot remove from front." << endl;
        return "";
    }

    string item = arr[front];
    if (front == back)
    {
        front = back = -1;
    }
    else if (front == MAX_SIZE - 1)
    {
        front = 0;
    }
    else
    {
        front++;
    }

    cout << "Removed " << item << " from the front." << endl;
    return item;
}

string Deque::removeBack()
{
    if (front == -1)
    {
        cout << "Deque is empty. Cannot remove from back." << endl;
        return "";
    }

    string item = arr[back];
    if (front == back)
    {
        front = back = -1;
    }
    else if (back == 0)
    {
        back = MAX_SIZE - 1;
    }
    else
    {
        back--;
    }

    cout << "Removed " << item << " from the back." << endl;
    return item;
}

void Deque::display()
{
    if (front == -1)
    {
        cout << "Deque is empty." << endl;
        return;
    }

    cout << "Deque items: ";
    int i = front;
    while (i != back)
    {
        cout << arr[i] << " ";
        i = (i + 1) % MAX_SIZE;
    }
    cout << arr[back] << endl;
}

int main()
{
    int choice, scenario;
    string item;

    cout << "\nShopping Mall Deque Operations" << endl;
    cout << "Choose Scenario:" << endl;
    cout << "1. Input Restricted Deque" << endl;
    cout << "2. Output Restricted Deque" << endl;
    cout << "Enter your choice (1 or 2): ";
    cin >> scenario;

    Deque deque((scenario == 1));

    if (scenario == 1)
    {
        cout << "Input Restricted Deque selected." << endl;
    }
    else if (scenario == 2)
    {
        cout << "Output Restricted Deque selected." << endl;
    }
    else
    {
        cout << "Invalid scenario selected." << endl;
        return 0;
    }

    do
    {
        cout << "\nDeque Operations:" << endl;
        cout << "1. Add at Front" << endl;
        cout << "2. Add at Back" << endl;
        cout << "3. Remove from Front" << endl;
        cout << "4. Remove from Back" << endl;
        cout << "5. Display Deque" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            if (scenario == 1)
            {
                cout << "Cannot add at front in Input Restricted Deque." << endl;
            }
            else
            {
                cout << "Enter item to add at front: ";
                cin >> item;
                deque.addFront(item);
            }
            break;

        case 2:
            if (scenario == 1)
            {
                cout << "Enter item to add at back: ";
                cin >> item;
                deque.addBack(item);
            }
            else
            {
                cout << "Cannot add at back in Output Restricted Deque." << endl;
            }
            break;

        case 3:
            deque.removeFront();
            break;

        case 4:
            deque.removeBack();
            break;

        case 5:
            deque.display();
            break;

        case 6:
            cout << "Exiting Deque operations." << endl;
            break;

        default:
            cout << "Invalid choice. Try again." << endl;
        }
    } while (choice != 6);

    return 0;
}