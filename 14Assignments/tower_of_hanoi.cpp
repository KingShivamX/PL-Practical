#include <iostream>
using namespace std;

void Tower_Hanoi(char begin_A, char temp_B, char end_C, int n) {
    if (n == 0) {
        return;
    }

    Tower_Hanoi(begin_A, end_C, temp_B, n - 1);

    cout << "Move disk " << n << " from rod " << begin_A << " to rod " << end_C << endl;

    Tower_Hanoi(temp_B, begin_A, end_C, n - 1);
}

int main() {
    int n;
    cout << "\nEnter the number of disks: ";
    cin >> n;

    Tower_Hanoi('A', 'B', 'C', n);

    return 0;
}

