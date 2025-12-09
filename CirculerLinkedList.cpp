// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

class CirculerList {
    Node* head;
    Node* tail;

public:
    CirculerList() {
        head = tail = NULL;
    }
    
    void pushFront(int val) {
        Node* n = new Node(val);

        if (head == NULL) {
            head = tail = n;
            tail->next = head;
            return;
        }

        n->next = head;
        head = n;
        tail->next = head;
    }
    void pushBack(int val){
        Node* n= new Node(val);
        if (head == NULL) {
            head = tail = n;
            tail->next = head;
            return;
        }
        tail->next=n;
       tail=n;
        tail->next=head;
        
        
    }
    void popFront(){
        if (head == tail) {  
        delete head;
        head = tail = NULL;
        return;
    }
    
        Node* temp=head;
        head=head->next;
        tail->next=head;
        free(temp);
    }
    void popBack(){
        if (head == NULL) return;
        
        if (head == tail) {  
        delete head;
        head = tail = NULL;
        return;
    }
    
        Node* temp=head;
        while(temp->next!=tail){
            temp=temp->next;
        }
        Node* ami=tail;
        tail=temp;
        tail->next=head;
        free(ami);
        
        
    }

    void Display() {
        if (head == NULL) return;

        Node* temp = head;
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
    }
};

int main() {
    CirculerList cll;
   
    cll.pushFront(13);
    cll.pushFront(14);
    cll.pushBack(11);
    
    cll.popBack();
    cll.popFront();
    cll.Display();
    return 0;
}
