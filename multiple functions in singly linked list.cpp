#include <iostream>
using namespace std;
class node {
public:
	int data;
	node* next;
	node(int data) {
		this->data =data;
		this->next = NULL;
	}
};
class list {
public:
	node* head;
	node* tail;
	list() {
		this->head = NULL;
		this->tail = NULL;
}
	void insert_at_end(int data) {
		node* N = new node(data);
		if (head == NULL) {
			head = tail = N;
		}
		else {
			tail->next =N;
			tail = N;
		}
	}
	void insert_at_start(int data) {
		node* N = new node(data);
		if (head == NULL) {
			head = tail = N;
		}
		else {
			N->next = head;
			head= N;
		}
	}
	
	void display() {
		if (head == NULL) {
			cout << "The linked list is empty." << endl;
			return;
		}
		node* temp = head;
		while (temp != NULL) {
			cout << temp->data<< "  ";
			temp = temp->next;
		}
		cout << endl;
	}
	void findmin() {
		if (head == NULL) {
		cout << "The linked list is empty." << endl;
		return;
		}
		node* min = head;
		node* temp = head->next;
		while (temp != NULL) {
			if (temp->data < min->data) {
				min = temp;
			}
			temp = temp->next;
		}
		cout << "The minimum value of the linked list is:" << min->data << endl;
	}
	void findmax() {
		if (head == NULL) {
	    cout << "The linked list is empty." << endl;
		return;
		}
		node* max = head;
		node* temp = head->next;
		while (temp != NULL) {
			if (temp->data > max->data) {
				max = temp;
			}
			temp = temp->next;
		}
		cout << "The maximum value of the linked list is:" << max->data << endl;
	}
	void sum() {
		int sum = 0;
		node* temp = head;
		while (temp != NULL) {
			sum += temp->data;
			temp = temp->next;
		}
		cout << "The sum of all elements of linked list is:" << sum << endl;
	}
	void sort() {
		if (head == NULL) {
			cout << "The linked list is empty." << endl;
			return;
		}
		node* start = head;
		while(start!=NULL){
		node* min = start;
		node* temp = start->next;
		while (temp != NULL) {
			if (temp->data < min->data) {
				min = temp;
			}
			temp = temp->next;
		}
			if (min != head) {
				int tempData = start->data; // c=a
				start->data = min->data;   // a=b
				min->data = tempData;    // b=c
			}
			start= start->next;
		}
	}
	void search(int key) {
		if (head == NULL) {
			cout << "The list is empty" << endl;
			return;
		}
		node* temp = head;
		while (temp != NULL) {
			if (temp->data == key) {
				cout << "The value " << temp->data << " is found in linked list" << endl;
				return;
			}
			temp = temp->next;
		}
			cout << "The value " << key << " is not found in linked list" << endl;
	}
	void update(int position,int data) {
		node* temp = head;
		int count = 1;
		while (temp != NULL) {
			if (count==position) {
				temp->data = data;
				cout << "Node at position " << position << " updated to " << data << "." << endl;
				return;
			}
			temp = temp->next;
			count++;
		}
		cout << "The provided position was out of bound try again with a valid position!!" << endl;
	}
	void delete_all_nodes() {
		node* temp = head;
		while (temp != NULL) {
			head = head->next;
			delete temp;
			temp= head;
		}
	}
	void delete_at_start() {
		node* temp = head;
		head = head->next;
		delete temp;
	}
	void delete_at_end() {
		node* temp = head;
		while (temp->next != tail) {
			temp = temp->next;
		}
		delete tail;
		tail = temp;
		tail->next = NULL;
		cout << "The last node has been deleted." << endl;

	}
	void average() {
		double average = 0.0;
		int count = 0;
		int sum = 0;
		node* temp = head;
		while (temp != NULL) {
			sum += temp->data;
			count++;
			temp = temp->next;
		}
		average = sum / count;
		cout << "The average of all elements of linked list is:" <<average << endl;
	}

};
int main()
{
	list l;
	l.insert_at_end(7);
	l.insert_at_end(10);
	l.insert_at_end(8);
	l.insert_at_end(5);
	l.display();
	l.findmin();
	l.findmax();
	l.sum();
	l.sort();
	l.display();
	l.search(5);
	l.update(2, 99);
	l.display();
	l.delete_at_end();
	l.display();
	l.average();

   
}

