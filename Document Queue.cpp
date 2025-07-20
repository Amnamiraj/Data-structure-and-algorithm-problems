#include <iostream>
using namespace std;
class Node {
public:
    int jobID;
    string DocumentName;
    int pages;
    Node* next;
    Node(int jobID,string DocumentName,int pages) {
        this->jobID = jobID;
        this->DocumentName = DocumentName;
        this->pages = pages;
        this->next = NULL;
    }


};
Node* head = NULL;
void Insert_at_end(Node* &head,int jobID, string DocumentName, int pages) {
    Node* N = new Node(jobID, DocumentName,pages);
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
void display(Node*& head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << "job ID:" << temp->jobID << "  " << "Document Name:" << temp->DocumentName << "  " << "Pages:" << temp->pages << endl;
        temp = temp->next;
    }
}
int main()
{
    cout << "Printing Queue:" << endl;
    Insert_at_end(head,455, "Presentation_Slides", 300);
    Insert_at_end(head, 678, "Contract_Agreement", 10);
    Insert_at_end(head, 320, "Marketing_Brochure",50);
    display(head);
}
