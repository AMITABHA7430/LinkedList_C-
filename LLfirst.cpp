#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};

class List {
    Node* head;
    Node* tail;

public:
    List() : head(nullptr), tail(nullptr) {}

    ~List() {
        // delete all nodes
        Node* cur = head;
        while (cur) {
            Node* nxt = cur->next;
            delete cur;
            cur = nxt;
        }
    }

    void push_front(int val) {
        Node* n = new Node(val);
        if (head == nullptr) {
            head = tail = n;
            return;
        }
        n->next = head;
        head = n;
    }

    void insertEnd(int val) {
        Node* n = new Node(val);
        if (head == nullptr) {
            head = tail = n;
            return;
        }
        tail->next = n;
        tail = n;
    }

    void popfront() {
        if (head == nullptr) return;

        Node* temp = head;
        head = head->next;
        // if list becomes empty, update tail
        if (head == nullptr) tail = nullptr;
        delete temp;
    }

    void popback() {
        if (head == nullptr) return;         // empty list

        if (head == tail) {                 // single node
            delete head;
            head = tail = nullptr;
            return;
        }

        // more than one node: find node just before tail
        Node* temp = head;
        while (temp->next != tail) {
            temp = temp->next;
        }
        temp->next = nullptr;   // unlink last node
        delete tail;            // free old tail
        tail = temp;            // update tail
    }
    void insertAtpos(int val,int pos){
        if(pos<0){
            return;
        }
        if(pos==0){
           push_front(val) ;
           return;
        }
        Node* A=new Node(val);
        Node* temp=head;
        for(int i=0;i<pos-1;i++){
            temp=temp->next;
        }
        A->next=temp->next;
        temp->next=A;
        
    }
    void search(int val){
        if(head->next==NULL){
            return;
        }
        Node* temp=head;
        int cnt=0;
        while(temp->next!=NULL){
            if(temp->data==val){
                cout<<"value fount at";
                cout<<cnt<<endl;
            }
            temp=temp->next;
            cnt++;
            
        }
        
        
    }

    void Display() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    List ll;
    ll.push_front(10);
    ll.push_front(20);
    ll.insertEnd(40);
    ll.insertEnd(40);
    ll.insertAtpos(70,0);
    ll.popback();
    ll.Display();
    ll.search(20);
    ll.search(70);
    ll.search(10);
    ll.search(60);

    return 0;
}
