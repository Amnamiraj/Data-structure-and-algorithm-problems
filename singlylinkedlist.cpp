#include <iostream>
using namespace std;
class node {
public:
	int data;
	node* next;
	//constructor 
	node(int data) {
		this->data = data;
		this->next = NULL;

	}
	// destructor
	~node() {
		int value=this->data;
		if (this->next != NULL) {
			delete next;
			this->next = NULL;
		}
		cout << "The memory is free for the node with data " << value << endl;

	}
};
// insert a node at the start of linkedlist
void insertatnode(node*& head, int d) {
	node* temp = new node(d);
	temp->next = head;
	head = temp;
}
// insert a node at the end of linkedlist
void insertatnode1(node*& tail, int d) {
	node* temp = new node(d);
	tail->next = temp;
	tail = temp;

}
// printing the linkedlist
void print(node*& head) {
	node* temp = head;
	while (temp != NULL) {
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}
// insert new node in the linked list
void insertnewnode(node*& head, node*& tail, int position, int d) {
	// inserting node at the first position
	if (position == 1) {
		insertatnode(head, d);
		return;
	}
	node* temp = head;
	int count = 1;
	while (count < position - 1) {
		temp = temp->next;
		count++;
	}
	// inserting node at the end position
	if (temp->next == NULL) {
		insertatnode1(tail, d);
		return;
	}
	node* nodetoinsert = new node(d);
	nodetoinsert->next = temp->next;
	temp->next = nodetoinsert;
}
// deleting the node of linked list
void deletenode(node* &head, node*& tail, int position) {
	// deleting the first node 
	if (position==1) {
		node* temp = head;
		head = head->next;
		temp->next = NULL;
		delete temp;
	}
	// deleting any middle or last node
	else {
		node* prev=NULL;
		node* curr=head;
		int count = 1;
		while (count < position) {
			prev = curr;
			curr = curr->next;
			count++;
		}
		prev->next = curr->next;
		curr->next = NULL;
		tail = prev;
		delete curr;

	}

}
int main()
{
	node* node1 = new node(10);
	node* head = node1;
	node* tail = node1;
	print(head);
	insertatnode1(tail, 12);
	print(head);
	insertatnode1(tail, 15);
	print(head);
	insertnewnode(head, tail, 4, 22);
	print(head);
	cout << "The value of head is " << head->data << endl;
	cout << "The value of tail is " << tail->data << endl;
	deletenode(head,tail, 4);
	print(head);
	cout << "The value of head is " << head->data << endl;
	cout << "The value of tail is " << tail->data << endl;
}