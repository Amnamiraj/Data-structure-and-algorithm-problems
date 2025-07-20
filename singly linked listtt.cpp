#include <iostream>
using namespace std;
// creation of class Node
class Node {
public:
    int data;
    Node* next;
    // constructor
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
    // destructor
    ~Node() {
        int value = this->data;
        if (this->next != NULL) {
            delete next;
            this->next = NULL;
        }
    }
};
// head declaration and initilization
Node* head = NULL;
// Creating a linked list
void createLinkList(int data) {
    Node* N = new Node(data);
    if (head == NULL) {
        head = N;
    }
    else {
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = N;
    }
}
// Insertion of a node at start
void insert_at_start(Node*& head, int d) {
    Node* temp = new Node(d);
    temp->next = head;
    head = temp;
}
// Insertion of a node at end
void insert_at_end(int d) {
    createLinkList(d);
}
// Insertion at a specific position
void insert_at_pos(Node*& head, int position, int d) {
    if (position == 1) {
        insert_at_start(head, d);
        return;
    }
    Node* temp = head;
    int count = 1;
    if (count < position - 1) {
        temp = temp->next;
        count++;
    }
    if (temp->next == NULL) {
        insert_at_end(d);
        return;
    }
    Node* Nodetoinsert = new Node(d);
    Nodetoinsert->next = temp->next;
    temp->next = Nodetoinsert;
}
// Deleting a node at start
void delete_at_start(Node*& head) {
    Node* temp = head;
    head = head->next;
    temp->next = NULL;
    delete temp;
}
// Deleting a node at a specific position
void delete_at_pos(Node*& head, int position) {
    Node* curr = head;
    Node* prev = NULL;

    int cnt = 1;
    while (cnt < position) {
        prev = curr;
        curr = curr->next;
        cnt++;
    }

    prev->next = curr->next;
    curr->next = NULL;
    delete curr;
}
// Returns the length of linked list
int length() {
    int count = 0;
    Node* temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}
// deleting the last node
void delete_at_end() {
    delete_at_pos(head, length());
}
// Displaying the linked list
void display(Node*& head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    createLinkList(5);
    createLinkList(10);
    createLinkList(15);
    createLinkList(20);
    cout << "Displaying linked list" << endl;
    display(head);
    cout << endl;
    cout << "Inserting a node at start" << endl;
    insert_at_start(head, 8);
    display(head);
    cout << endl;
    cout << "Inserting a node at 3rd position" << endl;
    insert_at_pos(head, 3, 6);
    display(head);
    cout << endl;
    cout << "Inserting a node at end" << endl;
    insert_at_end(25);
    display(head);
    cout << endl;
    cout << "The lenght of linked list is: " << length() << endl;
    cout << endl;
    cout << "Deleting a node at start" << endl;
    delete_at_start(head);
    display(head);
    cout << endl;
    cout << "Deleting a node from 2nd position" << endl;
    delete_at_pos(head, 2);
    display(head);
    cout << endl;
    cout << "Deleting the last node" << endl;
    delete_at_end();
    display(head);
    cout << endl;
    cout << "The lenght of linked list is: " << length() << endl;

    return 0;
}
