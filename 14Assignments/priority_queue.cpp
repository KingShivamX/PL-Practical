#include <iostream>
#include <string>
using namespace std;

struct Patient {
    string name;
    int priority;       // Lower value means higher priority
    int appointmentTime;
};

class Hospital {
private:
    Patient appointments[20];
    int appointmentCount;

public:
    Hospital() : appointmentCount(0) {}

    void addPatient(const string& name, int priority, int appointmentTime) {
        if (appointmentCount < 20) {
            appointments[appointmentCount++] = {name, priority, appointmentTime};
            sortAppointments();
            cout << "Appointment added for " << name << " with priority " << priority << " and time " << appointmentTime << ".\n";
        } else {
            cout << "Appointment queue is full.\n";
        }
    }

    void sortAppointments() {
        for (int i = 0; i < appointmentCount - 1; i++) {
            for (int j = i + 1; j < appointmentCount; j++) {
                if (appointments[i].priority > appointments[j].priority) {
                    swap(appointments[i], appointments[j]);
                }
            }
        }
    }

    void attendPatient() {
        if (appointmentCount == 0) {
            cout << "No patients in the queue.\n";
            return;
        }
        cout << "Attending patient: " << appointments[0].name 
             << " (Priority: " << appointments[0].priority 
             << ", Time: " << appointments[0].appointmentTime << ")\n";
        for (int i = 1; i < appointmentCount; i++) {
            appointments[i - 1] = appointments[i];
        }
        appointmentCount--;
    }

    void displayAllAppointments() {
        if (appointmentCount == 0) {
            cout << "No appointments in the queue.\n";
            return;
        }
        cout << "Appointments list:\n";
        for (int i = 0; i < appointmentCount; i++) {
            cout << "Patient: " << appointments[i].name 
                 << ", Priority: " << appointments[i].priority 
                 << ", Appointment Time: " << appointments[i].appointmentTime << endl;
        }
    }
};

int main() {
    Hospital hospital;
    int choice;
    do {
        cout << "\n--- Hospital Appointment Menu ---\n";
        cout << "1. Add Patient\n";
        cout << "2. Attend Patient\n";
        cout << "3. Display All Appointments\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                string name;
                int priority, time;
                cout << "Enter patient name: ";
                cin.ignore();
                getline(cin, name);
                cout << "Enter priority (1 = high priority, higher number = lower priority): ";
                cin >> priority;
                cout << "Enter appointment time: ";
                cin >> time;
                hospital.addPatient(name, priority, time);
                break;
            }
            case 2:
                hospital.attendPatient();
                break;
            case 3:
                hospital.displayAllAppointments();
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
