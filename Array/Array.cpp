#include <iostream>
using namespace std;

// Class to represent a library system with book details
class library {
    string title;   // Stores book title
    string author;  // Stores book author
    int id;         // Stores unique book ID
    int year;       // Stores year of publication

public:
    void getdata();     // Method to input book details
    void display();     // Method to display book details
    int search(int);    // Method to search for a book by ID
    void update(int);   // Method to update specific book details
};

// Method to input book details
void library::getdata(){
    
    cout << "Enter Book Id: " << endl;
    cin >> id;
    cin.ignore();  // Clear the input buffer
    cout << "Enter Title: " << endl;
    getline(cin, title);
    cout << "Enter Author: " << endl;
    getline(cin, author);
    cout << "Enter Publishing Year: " << endl;
    cin >> year;
    cin.ignore();
}

// Method to display book details
void library::display()
{
    cout << "Book Id: " << id << endl;
    cout << "Title: " << title << endl;
    cout << "Author: " << author << endl;
    cout << "Year of Publication: " << year << endl;
}

// Method to search for a book by ID
int library::search(int book_id)
{
    return (book_id == id);  // Returns true if book ID matches
}

// Method to update specific book details based on choice
void library::update(int ch1)
{
    switch (ch1)
    {
    case 1: // Update title
        cout << "Enter New Title: " << endl;
        getline(cin, title);
        break;
    case 2: // Update author
        cout << "Enter New Author: " << endl;
        getline(cin, author);
        break;
    case 3: // Update publication year
        cout << "Enter New Year of Publication: " << endl;
        cin >> year;
        cin.ignore();
        break;
    default: // Invalid choice
        cout << "Invalid choice." << endl;
        break;
    }
}

int main()
{
    library lib[20]; // Array of up to 20 library objects
    int n = 0, choice, pos, book_id, pos1;
    char ch, ch1;

    do
    {
        // Display menu options
        cout << "Library Management System" << endl;
        cout << "1.Input" << endl;
        cout << "2.Display" << endl;
        cout << "3.Insert" << endl;
        cout << "4.Update" << endl;
        cout << "5.Delete" << endl;
        cout << "6.Exit" << endl;
        cout << "Enter Your Choice: " << endl;
        cin >> choice;
        cin.ignore();

        switch (choice)
        {
        case 1: // Input book data
            cout << "Enter The Number of Books to Add: " << endl;
            cin >> n;
            cin.ignore();
            for (int i = 0; i < n; i++)
            {
                lib[i].getdata(); // Input data for each book
            }
            break;

        case 2: // Display all books
            for (int i = 0; i < n; i++)
            {
                lib[i].display();
            }
            break;

        case 3: // Insert a new book at a specific position
            cout << "Enter the Position to Insert New Book: " << endl;
            cin >> pos;
            cin.ignore();
            if (pos < 0 || pos > n)
            {
                cout << "Invalid Position." << endl;
                break;
            }
            for (int i = n; i > pos; i--)
            {
                lib[i] = lib[i - 1]; // Shift books to make space
            }
            lib[pos].getdata(); // Input new book data
            n++; // Increase book count
            break;

        case 4: // Update book details by ID
            cout << "Enter Book Id to Update: " << endl;
            cin >> book_id;
            cin.ignore();
            {
                bool found = false;
                for (int i = 0; i < n; i++)
                {
                    if (lib[i].search(book_id))
                    {
                        found = true;
                        // Display update options
                        cout << "1.Title" << endl;
                        cout << "2.Author" << endl;
                        cout << "3.Year" << endl;
                        cout << "Enter Choice: " << endl;
                        cin >> ch1;
                        cin.ignore();
                        lib[i].update(ch1); // Update details
                        break;
                    }
                }
                if (!found)
                {
                    cout << "Book Id Not Found." << endl;
                }
            }
            break;

        case 5: // Delete a book by position
            cout << "Enter the Position to Delete Data: " << endl;
            cin >> pos1;
            cin.ignore();
            pos1 -= 1; // Adjust for 0-based index
            if (pos1 < 0 || pos1 >= n)
            {
                cout << "Invalid Position." << endl;
                break;
            }
            for (int i = pos1; i < n - 1; i++)
            {
                lib[i] = lib[i + 1]; // Shift books to remove entry
            }
            n--; // Decrease book count
            break;

        case 6: // Exit the program
            cout << "Exiting..." << endl;
            break;

        default: // Handle invalid menu choices
            cout << "Invalid Choice! Try again." << endl;
            break;
        }

        // Ask if the user wants to continue
        cout << "Do You Want to Continue? Y/N: " << endl;
        cin >> ch;
        cin.ignore();
    } while (ch == 'Y' || ch == 'y');

    return 0;
}
