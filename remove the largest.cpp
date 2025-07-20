#include <iostream>
using namespace std;

class Stack {
    int* arr;
    int top;
    int size;

public:
    Stack(int size) {
        this->size = size;
        top = -1;
        arr = new int[size];
    }
    ~Stack() {
        delete[] arr;
    }
    void push(int element) {
        if (size - top > 1) {
            top++;
            arr[top] = element;
        }
        else {
            cout << "Stack overflow!" << endl;
        }
    }
    void pop() {
        if (top >= 0) {
            top--;
        }
        else {
            cout << "Stack is empty!" << endl;
        }
    }
    int peek() {
        if (top >= 0) {
            return arr[top];
        }
        else {
            cout << "Stack is empty!" << endl;
            return -1;
        }
    }
    bool empty() {
        return top == -1;
    }
    void display() {
        for (int i = top; i >= 0; i--) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    void removelargest() {
        if (empty()) {
            cout << "The stack is empty!" << endl;
            return;
        }

        int largest = peek();
        Stack tempStack(size);
        while (!empty()) {
            int topElement = peek();
            if (topElement > largest) {
                largest = topElement;
            }
            tempStack.push(topElement);
            pop();
        }
        while (!tempStack.empty()) {
            int topElement = tempStack.peek();
            if (topElement != largest) {
                push(topElement);
            }
            tempStack.pop();
        }
    }
};

int main() {
    int size = 7;
    Stack s(size);
    s.push(1);
    s.push(4);
    s.push(6);
    s.push(8);
    s.push(22);
    s.push(6);
    s.push(8);

    cout << "Before removing the largest element:" << endl;
    s.display();
    s.removelargest();
    cout << "After removing the largest element:" << endl;
    s.display();

    return 0;
}
