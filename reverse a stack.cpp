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
            cout << "Stack is overflow!" << endl;
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
        if (top == -1) {
            return true;
        }
        else {
            return false;
        }
    }
    void add_at_bottom(Stack& inputstack, int x) {
        if (inputstack.empty()) {
            inputstack.push(x);
        }
        else {
            int num = inputstack.peek();
            inputstack.pop();
            add_at_bottom(inputstack, x);
            inputstack.push(num);
        }
    }
    void reverse(Stack& inputstack) {
        if (inputstack.empty()) {
            return;
        }
        else {
            int num = inputstack.peek();
            inputstack.pop();
            reverse(inputstack);
            add_at_bottom(inputstack, num);
       
        }
    }

    void display() {
        for (int i = top; i >= 0; i--) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};
int main()
{
    int size = 10;
    Stack s(size);
    for (int i = 0; i < size; i++) {
        s.push(2 * i);
    }
    cout << "Before adding at the bottom:" << endl;
    s.display();
    s.add_at_bottom(s, 50);
    cout << "After adding at the bottom:" << endl;
    s.display();
    s.reverse(s);
    cout << "After reversing the stack:" << endl;
    s.display();


}



