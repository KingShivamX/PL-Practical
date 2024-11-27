#include <iostream>
using namespace std;

class Node {
public:
    int coeff;
    int exp;
    Node* next;
    Node(int c, int e) : coeff(c), exp(e), next(nullptr) {}
};

class Polynomial {
public:
    Node* head;
    Polynomial() : head(nullptr) {}

    void append(int coeff, int exp) {
        Node* newNode = new Node(coeff, exp);
        if (!head) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    void printPoly() {
        Node* temp = head;
        while (temp) {
            if (temp != head && temp->coeff > 0) {
                std::cout << " + ";
            }
            if (temp->exp == 0) {
                std::cout << temp->coeff;
            } else if (temp->exp == 1) {
                std::cout << temp->coeff << "x";
            } else {
                std::cout << temp->coeff << "x^" << temp->exp;
            }
            temp = temp->next;
        }
        std::cout << std::endl;
    }

    Polynomial addPoly(Polynomial& poly2) {
        Polynomial result;
        Node* p1 = head;
        Node* p2 = poly2.head;

        while (p1 && p2) {
            if (p1->exp > p2->exp) {
                result.append(p1->coeff, p1->exp);
                p1 = p1->next;
            } else if (p1->exp < p2->exp) {
                result.append(p2->coeff, p2->exp);
                p2 = p2->next;
            } else {
                int newCoeff = p1->coeff + p2->coeff;
                if (newCoeff != 0) {
                    result.append(newCoeff, p1->exp);
                }
                p1 = p1->next;
                p2 = p2->next;
            }
        }

        while (p1) {
            result.append(p1->coeff, p1->exp);
            p1 = p1->next;
        }

        while (p2) {
            result.append(p2->coeff, p2->exp);
            p2 = p2->next;
        }

        return result;
    }
};

int main() {
    Polynomial poly1, poly2;
    int n1, n2;

    std::cout << "Enter number of terms for polynomial 1: ";
    std::cin >> n1;
    std::cout << "Enter terms for polynomial 1 (coefficient exponent):\n";
    for (int i = 0; i < n1; ++i) {
        int coeff, exp;
        std::cin >> coeff >> exp;
        poly1.append(coeff, exp);
    }

    std::cout << "Enter number of terms for polynomial 2: ";
    std::cin >> n2;
    std::cout << "Enter terms for polynomial 2 (coefficient exponent):\n";
    for (int i = 0; i < n2; ++i) {
        int coeff, exp;
        std::cin >> coeff >> exp;
        poly2.append(coeff, exp);
    }

    std::cout << "Polynomial 1: ";
    poly1.printPoly();

    std::cout << "Polynomial 2: ";
    poly2.printPoly();

    Polynomial sumPoly = poly1.addPoly(poly2);
    std::cout << "Sum of Polynomials: ";
    sumPoly.printPoly();

    return 0;
}
