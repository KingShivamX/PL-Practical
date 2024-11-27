#include <iostream>

class Deque {
    struct Node {
        char data;
        Node* next;
        Node* prev;
        Node(char value) : data(value), next(nullptr), prev(nullptr) {}
    };

    Node* front;
    Node* back;

public:
    Deque() : front(nullptr), back(nullptr) {}

    // Adds a character to the back of the deque
    void push_back(char ch) {
        Node* newNode = new Node(ch);
        if (!back) {
            front = back = newNode;
        } else {
            back->next = newNode;
            newNode->prev = back;
            back = newNode;
        }
    }

    // Removes and returns the character from the front of the deque
    char pop_front() {
        if (!front) return '\0';
        char data = front->data;
        Node* temp = front;
        front = front->next;
        if (front) front->prev = nullptr;
        else back = nullptr;
        delete temp;
        return data;
    }

    // Removes and returns the character from the back of the deque
    char pop_back() {
        if (!back) return '\0';
        char data = back->data;
        Node* temp = back;
        back = back->prev;
        if (back) back->next = nullptr;
        else front = nullptr;
        delete temp;
        return data;
    }

    // Checks if the deque is empty
    bool isEmpty() const {
        return front == nullptr;
    }
};

bool isPalindrome(const char* str) {
    Deque deque;
    
    // Insert characters into the deque
    for (int i = 0; str[i] != '\0'; ++i) {
        deque.push_back(str[i]);
    }

    // Check palindrome by comparing characters from front and back
    while (!deque.isEmpty()) {
        char frontChar = deque.pop_front();
        if (deque.isEmpty()) break;  // If there's only one character left
        char backChar = deque.pop_back();

        if (frontChar != backChar) {
            return false;
        }
    }
    return true;
}

int main() {
    const char* str = "racecar";
    if (isPalindrome(str)) {
        std::cout << "\"" << str << "\" is a palindrome.\n";
    } else {
        std::cout << "\"" << str << "\" is not a palindrome.\n";
    }
    return 0;
}
