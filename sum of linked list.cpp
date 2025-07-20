#include <iostream>
#include <climits>
using namespace std;
class node {
public:
    int data;
    node* next;
    node(int data) {
        this->data = data;
        this->next = NULL;
    }
};
void insertathead(node*& head, int d) {
    node* temp = new node(d);
    temp->next = head;
    head = temp;

}
void insertattail(node*& tail, int d) {
    node* temp = new node(d);
    tail->next = temp;
    tail = temp;
}
void print(node*& head) {
    node* temp = head;
    while (temp != NULL) {  // Traverse and print all nodes
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void insertanewnode(node*& head, node*& tail, int position, int d) {
    if (position == 1) {
        insertathead(head, d);
        return;
    }
    node* temp = head;
    int count = 1;
    if (count < position - 1) {
        temp = temp->next;
        count++;
    }
    if (temp->next == NULL) {
        insertattail(tail, d);
        return;
    }
    node* nodetoinsert = new node(d);
    nodetoinsert->next = temp->next;
    temp->next = nodetoinsert;
}
//overall sum of the linked list
void sum(node*& head) {
    node* temp = head;
    int sum = 0;
    while (temp) {
        sum = sum + temp->data;
        temp = temp->next;
    }
    cout << "The total sum of linked list is:" << sum << endl;
}
// to find the maximum of linked list
void maximum(node*& head) {
    node* temp = head;
    int m = INT_MIN;
    while (temp) {
        if (temp->data > m) {
            m = temp->data;
        }
            temp = temp->next;
        }
    
    cout << "The maximum element in linked list is:" << m << endl;
}
// to find the minimum in linked list 
void minimum(node*& head) {
    node* temp = head;
    int m = INT_MAX;
    while (temp) {
        if (temp->data < m) {
            m = temp->data;
        }
        temp = temp->next;
    }
    cout << "The minimum element in linked list is:" << m << endl;
}
node* search(node*& head, int key) {
    node* temp = head;
    while (temp != NULL) {
        if (key == temp->data) {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

int main()
{
    node* node1 = new node(10);
    node* head = node1;
    node* tail = node1;
    insertattail(tail, 5);
    insertattail(tail, 7);
    insertattail(tail, 6);
    insertanewnode(head, tail, 3, 22);
    sum(head);
   
    print(head);
    maximum(head);
    minimum(head);
    int key = 7;
    node* result = search(head, key);
    if (result != NULL) {
        cout << "Node with data " << key << " found." << endl;
    }
    else {
        cout << "Node with data " << key << " not found." << endl;
    }
    
}

