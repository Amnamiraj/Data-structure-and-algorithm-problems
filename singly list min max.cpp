#include <iostream>
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
class linkedlist {
public:
    node* head;
    node* tail;
    linkedlist() {
        this->head = NULL;
        this->tail = NULL;
    }
    void insert_at_start(int data) {
        node* N = new node(data);
        if (head == NULL) {
            head = tail = N;
        }
        else {
            N->next = head;
            head = N;
        }
    }
    void insert_at_last(int data) {
        node* N = new node(data);
        if (head == NULL) {
            head = tail = N;
        }
        else {
            node* temp = head;
            while (temp != NULL) {
                temp = temp->next;
            }
            tail->next = N;
            tail = N;
        }
    }
    void sort() {
        node* start = head;
        while (start != NULL) {
            node* min = start;
            node* temp = start->next;
            while (temp != NULL) {
                if (temp->data < min->data) {
                    min = temp;
                }
                temp = temp->next;
            }
            if (min != start) {
                int temp1 = start->data;
                start->data = min->data;
                min->data = temp1;
            }
            start = start->next;
        }
    }
    int find_min() {
        if (head == NULL) { 
            cout << "List is empty!" << endl;
            return -1; 
        }
        int min = head->data; 
        node* temp = head->next;

        while (temp != NULL) {
            if (temp->data < min) {
                min = temp->data; 
            }
            temp = temp->next;
        }
        return min; 
    }
    int find_max() {
        if (head == NULL) {
            cout << "List is empty!" << endl;
            return -1;
        }
        int max = head->data;
        node* temp = head->next;

        while (temp != NULL) {
            if (temp->data > max) {
                max= temp->data;
            }
            temp = temp->next;
        }
        return max;
    }

    void display() {
        node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};
int main()
{
    linkedlist l;
    l.insert_at_start(22);
    l.insert_at_last(7);
    l.insert_at_last(5);
    l.insert_at_last(34);
    l.insert_at_last(45);
    l.display();
    l.sort();
    l.display();
    cout << "The minimum value of linkedlist is:" << l.find_min()<<endl;
    cout << "The maximum value of linkedlist is:" << l.find_max() << endl;


}

