#include <iostream>
#include <string>
using namespace std;

class Friend {
public:
    string name;
    string mobile;
};

class PhoneBook {
    Friend friends[100];
    int n;

public:
    PhoneBook() : n(0) {}

    void insertFriend(string name, string mobile) {
        friends[n++] = {name, mobile};
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                if (friends[i].name > friends[j].name) {
                    Friend temp = friends[i];
                    friends[i] = friends[j];
                    friends[j] = temp;
                }
            }
        }
    }

    int sentinelSearch(string name) {
        string lastName = friends[n - 1].name;
        friends[n - 1].name = name;
        int i = 0;
        while (friends[i].name != name) i++;
        friends[n - 1].name = lastName;
        return (i < n - 1 || friends[n - 1].name == name) ? i : -1;
    }

    void searchOrInsert(string name, string mobile) {
        int index = sentinelSearch(name);
        if (index == -1) {
            insertFriend(name, mobile);
            cout << name << " added to phonebook." << endl;
        } else {
            cout << "Mobile number of " << name << " is: " << friends[index].mobile << endl;
        }
    }
};

int main() {
    PhoneBook pb;
    pb.insertFriend("Anjali", "12345");
    pb.insertFriend("Raj", "23456");
    pb.insertFriend("Priya", "34567");

    string searchName, mobile;
    cout << "Enter friend's name to search: ";
    cin >> searchName;

    int index = pb.sentinelSearch(searchName);
    if (index == -1) {
        cout << "Friend not found. Enter mobile number to add " << searchName << ": ";
        cin >> mobile;
        pb.searchOrInsert(searchName, mobile);
    } else {
        pb.searchOrInsert(searchName, "");
    }
}
