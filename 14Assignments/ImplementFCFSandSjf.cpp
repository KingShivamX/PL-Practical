#include <iostream>
#include <string>
using namespace std;

struct Process {
    int pid;
    int arrivalTime;
    int burstTime;
};

class Scheduler {
private:
    Process processes[20];
    int processCount;

public:
    Scheduler() : processCount(0) {}

    void addProcess(int pid, int arrivalTime, int burstTime) {
        if (processCount < 20) {
            processes[processCount++] = {pid, arrivalTime, burstTime};
            cout << "Process " << pid << " added with Arrival Time: " << arrivalTime << ", Burst Time: " << burstTime << ".\n";
        } else {
            cout << "Process list is full.\n";
        }
    }

    void fcfsSchedule() {
        cout << "\n--- FCFS Scheduling ---\n";
        int waitTime = 0;
        for (int i = 0; i < processCount; i++) {
            cout << "Process " << processes[i].pid 
                 << " - Arrival Time: " << processes[i].arrivalTime 
                 << ", Burst Time: " << processes[i].burstTime 
                 << ", Wait Time: " << waitTime << "\n";
            waitTime += processes[i].burstTime;
        }
    }

    void sjfSchedule() {
        cout << "\n--- SJF Scheduling ---\n";
        sortByBurstTime();
        int waitTime = 0;
        for (int i = 0; i < processCount; i++) {
            cout << "Process " << processes[i].pid 
                 << " - Arrival Time: " << processes[i].arrivalTime 
                 << ", Burst Time: " << processes[i].burstTime 
                 << ", Wait Time: " << waitTime << "\n";
            waitTime += processes[i].burstTime;
        }
    }

    void sortByBurstTime() {
        for (int i = 0; i < processCount - 1; i++) {
            for (int j = i + 1; j < processCount; j++) {
                if (processes[i].burstTime > processes[j].burstTime) {
                    swap(processes[i], processes[j]);
                }
            }
        }
    }
};

int main() {
    Scheduler scheduler;
    int choice;
    do {
        cout << "\n--- Scheduling Menu ---\n";
        cout << "1. Add Process\n";
        cout << "2. FCFS Scheduling\n";
        cout << "3. SJF Scheduling\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int pid, arrivalTime, burstTime;
                cout << "Enter Process ID: ";
                cin >> pid;
                cout << "Enter Arrival Time: ";
                cin >> arrivalTime;
                cout << "Enter Burst Time: ";
                cin >> burstTime;
                scheduler.addProcess(pid, arrivalTime, burstTime);
                break;
            }
            case 2:
                scheduler.fcfsSchedule();
                break;
            case 3:
                scheduler.sjfSchedule();
                break;
            case 4:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 4);

    return 0;
}
