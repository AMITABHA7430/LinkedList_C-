#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int val) {
        data = val;
        next = prev = NULL;
    }
};

class DoublyList {
    Node* head;
    Node* tail;

public:
    DoublyList() {
        head = tail = NULL;
    }

    void pushFront(int val) {
        Node* n = new Node(val);
        if (head == NULL) {
            head = tail = n;
            return;
        }
        n->next = head;
        head->prev = n;
        head = n;
    }

    void pushBack(int val) {
        Node* n = new Node(val);
        if (head == NULL) {
            head = tail = n;
            return;
        }
        tail->next = n;
        n->prev = tail;
        tail = n;
    }

    void pushPos(int val, int pos) {
        if (head == NULL || pos == 0) {
            pushFront(val);
            return;
        }

        Node* temp = head;
        for (int i = 0; i < pos - 1 && temp->next != NULL; i++) {
            temp = temp->next;
        }

        Node* n = new Node(val);
        n->next = temp->next;
        n->prev = temp;

        if (temp->next != NULL) {
            temp->next->prev = n;
        }

        temp->next = n;

        if (n->next == NULL) {
            tail = n;
        }
    }

    void popBack() {
        if (head == NULL) {
            return;
        }

        if (head == tail) {
            delete head;
            head = tail = NULL;
            return;
        }

        Node* temp = tail;
        tail = tail->prev;
        tail->next = NULL;
        delete temp;
    }

    void Display() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }
};

int main() {
    DoublyList dll;
    dll.pushFront(10);
    dll.pushFront(20);
    dll.pushFront(30);
    dll.pushBack(70);
    dll.pushPos(80, 2);
    dll.popBack();
    dll.Display();
    return 0;
}
