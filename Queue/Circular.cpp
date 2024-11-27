#include <iostream>
using namespace std;

class CircularQueue
{
    int front, rear, size;
    int *arr;

public:
    CircularQueue(int s = 5)
    {
        size = s;
        arr = new int[size];
        front = rear = -1;
    }

    ~CircularQueue()
    {
        delete[] arr;
    }

    bool isEmpty()
    {
        return (front == -1);
    }

    bool isFull()
    {
        return ((rear + 1) % size == front);
    }

    void enqueue(int value)
    {
        if (isFull())
        {
            cout << "Queue is Full" << endl;
            return;
        }
        if (isEmpty())
        {
            front = rear = 0;
        }
        else
        {
            rear = (rear + 1) % size;
        }
        arr[rear] = value;
    }

    int dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue is Empty" << endl;
            return -1;
        }
        int value = arr[front];
        if (front == rear)
        {
            front = rear = -1;
        }
        else
        {
            front = (front + 1) % size;
        }
        return value;
    }

    void display()
    {
        if (isEmpty())
        {
            cout << "Queue is Empty" << endl;
            return;
        }
        cout << "Queue elements: ";
        int i = front;
        while (true)
        {
            cout << arr[i] << " ";
            if (i == rear)
                break;
            i = (i + 1) % size;
        }
        cout << endl;
    }

    void frontElement()
    {
        if (isEmpty())
        {
            cout << "Queue is Empty" << endl;
        }
        else
        {
            cout << "Front element: " << arr[front] << endl;
        }
    }
};

void roundRobinScheduling(int processes[], int n, int burst[], int quantum)
{
    int remaining_bursttime[n];
    for (int i = 0; i < n; i++)
    {
        remaining_bursttime[i] = burst[i];
    }

    int currentTime = 0;

    while (true)
    {
        bool allProcessesComplete = true;

        for (int i = 0; i < n; i++)
        {
            if (remaining_bursttime[i] > 0)
            {
                allProcessesComplete = false;

                if (remaining_bursttime[i] > quantum)
                {
                    currentTime += quantum;
                    remaining_bursttime[i] -= quantum;
                    cout << "Process " << processes[i] << " executed for " << quantum << " units. Remaining: " << remaining_bursttime[i] << endl;
                }
                else
                {
                    currentTime += remaining_bursttime[i];
                    cout << "Process " << processes[i] << " completed at time: " << currentTime << endl;
                    remaining_bursttime[i] = 0;
                }
            }
        }

        if (allProcessesComplete)
            break;
    }
}

int main()
{
    CircularQueue cq;
    int choice;

    do
    {
        cout << "\nMENU:\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Display Queue\n";
        cout << "4. Get Front Element\n";
        cout << "5. Perform Round Robin Scheduling\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            int value;
            cout << "Enter the value to enqueue: ";
            cin >> value;
            cq.enqueue(value);
            break;
        }
        case 2:
        {
            int removed = cq.dequeue();
            if (removed != -1)
            {
                cout << "Dequeued value: " << removed << endl;
            }
            break;
        }
        case 3:
            cq.display();
            break;
        case 4:
            cq.frontElement();
            break;
        case 5:
        {
            int n, quantum;
            cout << "Enter the number of processes: ";
            cin >> n;
            int processes[n];
            int bursttime[n];
            cout << "Enter the process IDs and Burst times:\n";
            for (int i = 0; i < n; i++)
            {
                cout << "Process ID: ";
                cin >> processes[i];
                cout << "Burst Time: ";
                cin >> bursttime[i];
            }
            cout << "Enter the time quantum: ";
            cin >> quantum;
            roundRobinScheduling(processes, n, bursttime, quantum);
            break;
        }
        case 0:
            cout << "Exiting program..." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 0);

    return 0;
}