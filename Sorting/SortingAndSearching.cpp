#include <iostream>
#include <string>
using namespace std;

class Student
{
    string name;
    int roll_no;
    float sgpa;
    string branch;

public:
    // Input Methods
    int input(int size, int max_size, Student students[]);

    // Display Methods
    void display(int size, Student students[]);

    // Sorting Techniques
    void bubbleSort(int size, Student students[]);
    void insertionSort(int size, Student students[]);
    void quickSort(Student students[], int low, int high);
    int partition(Student students[], int low, int high);

    // Searching Techniques
    void linearSearch(int size, Student students[]);
    void binarySearch(int size, Student students[]);
    void fibonacciSearch(Student students[], int size);

    // Setter and Getter Methods
    void setName(string n) { name = n; }
    void setRollNo(int r) { roll_no = r; }
    void setSgpa(float s) { sgpa = s; }
    void setBranch(string b) { branch = b; }
    string getName() { return name; }
    int getRollNo() { return roll_no; }
    float getSgpa() { return sgpa; }
    string getBranch() { return branch; }
};

// Input student details
int Student::input(int size, int max_size, Student students[])
{
    int num;
    cout << "Enter the number of students to add: ";
    cin >> num;

    if (size + num <= max_size)
    {
        for (int i = 0; i < num; i++)
        {
            string n, b;
            int r;
            float s;

            cout << "\nEnter details for student " << (size + i + 1) << ":\n";
            cout << "Name: ";
            cin.ignore();
            getline(cin, n);
            cout << "Roll No: ";
            cin >> r;
            cout << "SGPA: ";
            cin >> s;
            cout << "Branch: ";
            cin.ignore();
            getline(cin, b);

            students[size + i].setName(n);
            students[size + i].setRollNo(r);
            students[size + i].setSgpa(s);
            students[size + i].setBranch(b);
        }
        size += num; // Update total size
    }
    else
    {
        cout << "Cannot add more students. Only " << max_size - size << " slots are available.\n";
    }
    return size;
}

// Display student details
void Student::display(int size, Student students[])
{
    if (size == 0)
    {
        cout << "No students to display.\n";
        return;
    }

    for (int i = 0; i < size; i++)
    {
        cout << "\nStudent " << (i + 1) << ":\n";
        cout << "Name: " << students[i].getName() << "\n";
        cout << "Roll No: " << students[i].getRollNo() << "\n";
        cout << "SGPA: " << students[i].getSgpa() << "\n";
        cout << "Branch: " << students[i].getBranch() << "\n";
    }
}

// Bubble Sort for roll numbers
void Student::bubbleSort(int size, Student students[])
{
    for (int i = 0; i < size - 1; i++)
    {
        bool swapped = false;
        for (int j = 0; j < size - i - 1; j++)
        {
            if (students[j].getRollNo() > students[j + 1].getRollNo())
            {
                swap(students[j], students[j + 1]);
                swapped = true;
            }
        }
        if (!swapped)
            break;
    }
}

// Insertion Sort for alphabetical order of names
void Student::insertionSort(int size, Student students[])
{
    for (int i = 1; i < size; i++)
    {
        Student key = students[i];
        int j = i - 1;

        while (j >= 0 && students[j].getName() > key.getName())
        {
            students[j + 1] = students[j];
            j--;
        }
        students[j + 1] = key;
    }
}

// Partition function for Quick Sort
int Student::partition(Student students[], int low, int high)
{
    float pivot = students[high].getSgpa();
    int i = low - 1;

    for (int j = low; j < high; j++)
    {
        if (students[j].getSgpa() > pivot)
        {
            i++;
            swap(students[i], students[j]);
        }
    }
    swap(students[i + 1], students[high]);
    return i + 1;
}

// Quick Sort for SGPA
void Student::quickSort(Student students[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(students, low, high);
        quickSort(students, low, pi - 1);
        quickSort(students, pi + 1, high);
    }
}

// Linear Search for SGPA
void Student::linearSearch(int size, Student students[])
{
    float searchSGPA;
    cout << "Enter SGPA to search: ";
    cin >> searchSGPA;

    bool found = false;
    for (int i = 0; i < size; i++)
    {
        if (students[i].getSgpa() == searchSGPA)
        {
            if (!found)
            {
                cout << "Students with SGPA " << searchSGPA << ":\n";
                found = true;
            }
            cout << students[i].getName() << " (Roll No: " << students[i].getRollNo() << ")\n";
        }
    }

    if (!found)
    {
        cout << "No students found with SGPA " << searchSGPA << ".\n";
    }
}

// Binary Search for student by name
void Student::binarySearch(int size, Student students[])
{
    string searchName;
    cout << "Enter name to search: ";
    cin.ignore();
    getline(cin, searchName);

    int low = 0, high = size - 1;
    bool found = false;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (students[mid].getName() == searchName)
        {
            cout << "Student found: " << students[mid].getName() << "\n";
            cout << "Roll No: " << students[mid].getRollNo() << ", SGPA: " << students[mid].getSgpa()
                 << ", Branch: " << students[mid].getBranch() << "\n";
            found = true;
            break;
        }

        if (students[mid].getName() < searchName)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    if (!found)
    {
        cout << "Student with name " << searchName << " not found.\n";
    }
}

// Fibonacci Search for branch
void Student::fibonacciSearch(Student students[], int size)
{
    string searchBranch = "Computer";
    int fibM2 = 0, fibM1 = 1, fibM = fibM2 + fibM1;

    while (fibM < size)
    {
        fibM2 = fibM1;
        fibM1 = fibM;
        fibM = fibM1 + fibM2;
    }

    int offset = -1;
    while (fibM > 1)
    {
        int i = min(offset + fibM2, size - 1);

        if (students[i].getBranch() == searchBranch)
        {
            cout << "Student in Computer department: " << students[i].getName() << "\n";
            cout << "Roll No: " << students[i].getRollNo() << ", SGPA: " << students[i].getSgpa() << "\n";
            return;
        }

        if (students[i].getBranch() < searchBranch)
        {
            fibM = fibM1;
            fibM1 = fibM2;
            fibM2 = fibM - fibM1;
            offset = i;
        }
        else
        {
            fibM = fibM2;
            fibM1 = fibM1 - fibM2;
            fibM2 = fibM - fibM1;
        }
    }

    cout << "No students found in Computer department.\n";
}

int main()
{
    const int maxSize = 20;
    int size = 0;
    Student students[maxSize];
    int choice;

    do
    {
        cout << "\n1. Add Student Details\n2. Search\n3. Sort\n4. Display\n5. Exit\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            size = students[0].input(size, maxSize, students);
            break;
        case 2:
            cout << "1. Linear Search\n2. Binary Search\n3. Fibonacci Search\nEnter search choice: ";
            int searchChoice;
            cin >> searchChoice;

            if (searchChoice == 1)
                students[0].linearSearch(size, students);
            else if (searchChoice == 2)
                students[0].binarySearch(size, students);
            else if (searchChoice == 3)
                students[0].fibonacciSearch(students, size);
            break;
        case 3:
            cout << "1. Bubble Sort (Roll No)\n2. Insertion Sort (Names)\n3. Quick Sort (SGPA)\nEnter sort choice: ";
            int sortChoice;
            cin >> sortChoice;

            if (sortChoice == 1)
                students[0].bubbleSort(size, students);
            else if (sortChoice == 2)
                students[0].insertionSort(size, students);
            else if (sortChoice == 3)
                students[0].quickSort(students, 0, size - 1);
            break;
        case 4:
            students[0].display(size, students);
            break;
        case 5:
            cout << "Exiting program.\n";
            break;
        default:
            cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 5);

    return 0;
}