// COMSC-210 | Lab 21 | Huiluan Yie

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cstring>
using namespace std;

const int MIN_LS = 5, MAX_LS = 20;

const int SIZE = 15, MAX_AGE = 20;

class Goat {
private:
    int age;
    string name;
    string color;
    string names[SIZE] = {
        "Alice", "Benjamin", "Chloe", "Daniel", "Emma",
        "Felix", "Grace", "Henry", "Isabella", "Jacob",
        "Kayla", "Liam", "Maya", "Noah", "Olivia"
    };
    string colors[SIZE] = {
        "Red", "Orange", "Yellow", "Green", "Blue",
        "Purple", "Pink", "Brown", "Black", "White",
        "Gray", "Teal", "Navy", "Gold", "Silver"
    };

public:
    // constructor
    Goat() {
        age = rand() % MAX_AGE + 1;
        int i = rand() % SIZE;
        name = names[i];
        color = colors[i];
    }
    Goat(int a, string n, string c) {
        age = a;
        name = n;
        color = c;
    }

    // destructor
    ~Goat() {}
};

class DoublyLinkedList {
private:
    struct Node {
        Goat object;
        Node* prev;
        Node* next;
        Node(Goat& g, Node* p = nullptr, Node* n = nullptr) {
            object = g; 
            prev = p;
            next = n;
        }
    };

    Node* head;
    Node* tail;

public:
    // constructor
    DoublyLinkedList() { head = nullptr; tail = nullptr; }

    void push_back(Goat& goat) {
        Node* newNode = new Node(goat);
        if (!tail)  // if there's no tail, the list is empty
            head = tail = newNode;
        else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void push_front(Goat& goat) {
        Node* newNode = new Node(goat);
        if (!head)  // if there's no head, the list is empty
            head = tail = newNode;
        else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    /*
    void insert_after(int value, int position) {
        if (position < 0) {
            cout << "Position must be >= 0." << endl;
            return;
        }

        Node* newNode = new Node(value);
        if (!head) {
            head = tail = newNode;
            return;
        }

        Node* temp = head;
        for (int i = 0; i < position && temp; ++i)
            temp = temp->next;

        if (!temp) {
            cout << "Position exceeds list size. Node not inserted.\n";
            delete newNode;
            return;
        }

        newNode->next = temp->next;
        newNode->prev = temp;
        if (temp->next)
            temp->next->prev = newNode;
        else
            tail = newNode; // Inserting at the end
        temp->next = newNode;
    }

    void delete_node(int value) {
        if (!head) return; // Empty list

        Node* temp = head;
        while (temp && temp->data != value)
            temp = temp->next;

        if (!temp) return; // Value not found

        if (temp->prev) {
            temp->prev->next = temp->next;
        } else {
            head = temp->next; // Deleting the head
        }

        if (temp->next) {
            temp->next->prev = temp->prev;
        } else {
            tail = temp->prev; // Deleting the tail
        }

        delete temp;
    }
    */

    void print() {
        Node* current = head;
        if (!current) return;
        while (current) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    void print_reverse() {
        Node* current = tail;
        if (!current) return;
        while (current) {
            cout << current->data << " ";
            current = current->prev;
        }
        cout << endl;
    }

    ~DoublyLinkedList() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

// Driver program
int main() {
    srand(time(0));
    DoublyLinkedList list;
    
    // Append a random number of Goat objects
    int size = rand() % (MAX_LS-MIN_LS+1) + MIN_LS;
    for (int i = 0; i < size; ++i)
        list.push_back(Goat());


    cout << "List forward: ";
    list.print();
    cout << "List backward: ";
    list.print_reverse();

    cout << "Deleting list, then trying to print.\n";
    list.~DoublyLinkedList();
    cout << "List forward: ";
    list.print();


    return 0;
}
