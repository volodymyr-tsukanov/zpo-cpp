#ifndef LIST_H
#define LIST_H
#include <iostream>
#include <memory>

using namespace std;


template <typename T>
class Node {
public:
    T data;
    shared_ptr<Node<T>> next;
    weak_ptr<Node<T>> prev;

    Node(const T& value) : data(value), next(nullptr), prev() {}
};

template <typename T>
class DoublyLinkedList {
private:
    shared_ptr<Node<T>> head;
    shared_ptr<Node<T>> tail;

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr) {
        cout << "Konstruktor listy" << endl;
    }
    ~DoublyLinkedList() {
        while (!isEmpty()) {
            removeFront();
        }
        cout << "Destruktor listy" << endl;
    }

    bool isEmpty() const {
        return head == nullptr; // Lista jest pusta, jeśli head jest nullptr
    }

    void addFront(const T& value) {
        auto newNode = make_shared<Node<T>>(value);
        if (isEmpty()) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        cout << "Dodano na początek: " << value << endl;
    }
    void addBack(const T& value) {
        auto newNode = make_shared<Node<T>>(value);
        if (isEmpty()) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        cout << "Dodano na koniec: " << value << endl;
    }

    void removeFront() {
        if (isEmpty()) {
            cout << "Lista jest pusta, nie można usunąć elementu z przodu." << endl;
            return;
        }
        cout << "Usunięto z przodu: " << head->data << endl;

        if (head == tail) { // If there's only one element
            head.reset();
            tail.reset();
        } else {
            head = head->next;
            head->prev.reset(); // Resetting weak_ptr
        }
    }
    void removeBack() {
        if (isEmpty()) {
            cout << "Lista jest pusta, nie można usunąć elementu z tyłu." << endl;
            return;
        }
        cout << "Usunięto z tyłu: " << tail->data << endl;

        if (head == tail) { // If there's only one element
            head.reset();
            tail.reset();
        } else {
            tail = tail->prev.lock(); // Locking weak_ptr to get shared_ptr
            if (tail) { // Check if tail is not null after locking
                tail->next.reset(); // Resetting next pointer of new tail
            }
        }
    }

    void display() const {
        if (isEmpty()) {
            cout << "Lista jest pusta." << endl;
            return;
        }

        auto current = head;
        cout << "Zawartość listy: ";
        while (current) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

#endif // LIST_H
