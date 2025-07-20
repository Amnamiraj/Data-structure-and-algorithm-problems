#include <iostream>
using namespace std;

int queue[5]; // Fixed size queue
int front = -1, rear = -1;

// Enqueue function to add elements to the queue
void enqueue(int x) {
    if (rear == 4) {
        cout << "Queue is full!" << endl;
        return; // Stop further execution
    }
    if (front == -1 && rear == -1) {
        front = rear = 0;
    }
    else {
        rear++;
    }
    queue[rear] = x; // Add element
}

// Dequeue function to remove elements from the queue
void dequeue() {
    if (front == -1 && rear == -1) {
        cout << "Queue is empty!" << endl;
        return;
    }
    cout << "Dequeued: " << queue[front] << endl;
    if (front == rear) {
        // Reset the queue if it becomes empty
        front = rear = -1;
    }
    else {
        front++;
    }
}

// Display function to show elements of the queue
void display() {
    if (front == -1 && rear == -1) {
        cout << "Queue is empty!" << endl;
        return;
    }
    cout << "Queue elements: ";
    for (int i = front; i <= rear; i++) { // Iterate from front to rear
        cout << queue[i] << " ";
    }
    cout << endl;
}

int main() {
    enqueue(5);
    enqueue(6);
    enqueue(8);
    display();

    dequeue();
    dequeue();
    display();

    return 0;
}
