#include <iostream>
using namespace std;
class Node {
public:
    int EmailID;
    string Sender;
    string ImportanceLevel;
    Node* next;
    Node(int EmailID, string Sender, string ImportanceLevel) {
        this->EmailID = EmailID;
        this->Sender = Sender;
        this->ImportanceLevel = ImportanceLevel;
        this->next = NULL;
    }
};
Node* head = NULL;
void Insert_at_front(Node*& head, int EmailID, string Sender, string ImportanceLevel) {
    Node* N = new Node(EmailID, Sender, ImportanceLevel);
    N->next = head;
    head = N; 
}
void Insert_at_rear(Node*& head, int EmailID, string Sender, string ImportanceLevel) {
    Node* N = new Node(EmailID, Sender, ImportanceLevel);
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
void Insert_email(Node*& head, int EmailID, string Sender, string ImportanceLevel) {
    if (ImportanceLevel == "High") {
        Insert_at_front(head, EmailID, Sender, ImportanceLevel);
    }
    else {
        Insert_at_rear(head, EmailID, Sender, ImportanceLevel);
    }
}
void display(Node*& head) {
    if (head == NULL) {
        cout << "The inbox is empty!" << endl;
        return;
    }
    Node* temp = head;
    cout << "Inbox:" << endl;
    while (temp != NULL) {
        cout << "Email ID: " << temp->EmailID << ", Sender: " << temp->Sender << ", Importance Level: " << temp->ImportanceLevel << endl;
        temp = temp->next;
    }
}

int main() {
    // Emails with high importance level will be added at the front and other will be added at the rear
    Insert_email(head, 110, "amnamiraj@gmail.com", "High");
    Insert_email(head, 111, "mahadkhan@gmail.com", "Low");
    Insert_email(head, 112, "ayeshaali@gmail.com", "High");
    Insert_email(head, 113, "zahrsaeed@gmail.com", "Medium");
    display(head);

    return 0;
}


