// COMSC-210 | Lab 21 | Huiluan Yie

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>

using namespace std;

const int MIN_LS = 5, MAX_LS = 20;
const int SIZE = 15, MAX_AGE = 20;

class Goat {
private: 
    int age;
    string name;
    string color;
    string names[SIZE] = {
        "Alice",
        "Benjamin",
        "Chloe",
        "Daniel",
        "Emma",
        "Felix",
        "Grace",
        "Henry",
        "Isabella",
        "Jacob",
        "Kayla",
        "Liam",
        "Maya",
        "Noah",
        "Olivia"
    };
    string colors[SIZE] = {
        "Red",
        "Orange",
        "Yellow",
        "Green",
        "Blue",
        "Purple",
        "Pink",
        "Brown",
        "Black",
        "White",
        "Gray",
        "Teal",
        "Navy",
        "Gold",
        "Silver"
    };

public:
    // constructor
    Goat() {
        age = rand() % MAX_AGE + 1;
        int i = rand() % SIZE;
        name = names[i];
        i = rand() % SIZE;
        color = colors[i];
    }
    Goat(int a, string n, string c) {
        age = a;
        name = n;
        color = c;
    }

    // destructor
    ~Goat() {}

    // print function
    void print() {
        cout << name << " (" << color << ", " << age << ")\n";
    }
};

class DoublyLinkedList {
    private: struct Node {
        Goat object;
        Node * prev;
        Node * next;
        Node(Goat g, Node * p = nullptr, Node * n = nullptr) {
            object = g;
            prev = p;
            next = n;
        }
    };

    Node * head;
    Node * tail;

    public:
        // constructor
        DoublyLinkedList() {
            head = nullptr;
            tail = nullptr;
        }

    void push_back(Goat goat) {
        Node * newNode = new Node(goat);
        if (!tail) // if there's no tail, the list is empty
            head = tail = newNode;
        else {
            tail -> next = newNode;
            newNode -> prev = tail;
            tail = newNode;
        }
    }

    void push_front(Goat goat) {
        Node * newNode = new Node(goat);
        if (!head) // if there's no head, the list is empty
            head = tail = newNode;
        else {
            newNode -> next = head;
            head -> prev = newNode;
            head = newNode;
        }
    }

    void print() {
        Node * current = head;
        if (!current) cout << "List is empty";
        while (current) {
            cout << "\t";
            current -> object.print();
            current = current -> next;
        }
        cout << endl;
    }

    void print_reverse() {
        Node * current = tail;
        if (!current) cout << "List is empty";
        while (current) {
            cout << "\t";
            current -> object.print();
            current = current -> prev;
        }
        cout << endl;
    }

    ~DoublyLinkedList() {
        while (head) {
            Node * temp = head;
            head = head -> next;
            delete temp;
        }
    }
};

// Driver program
int main() {
    srand(time(0));
    DoublyLinkedList list;

    // Append a random number of Goat objects
    int size = rand() % (MAX_LS - MIN_LS + 1) + MIN_LS;
    for (int i = 0; i < size; ++i)
        list.push_back(Goat());

    cout << "List forward: \n";
    list.print();
    cout << "List backward: \n";
    list.print_reverse();

    cout << "Deleting list, then trying to print.\n";
    list.~DoublyLinkedList();
    cout << "List forward: ";
    list.print();

    return 0;
}