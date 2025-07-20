#include <iostream>
using namespace std;
class Stack {
    int* arr;
    int top;
    int size;
public:
    //constructor
    Stack(int size) {
        this->size = size;
        top = -1;
        arr = new int[size];
    }
    //destructor
    ~Stack() {
        delete[] arr;
    }
    //push function
    void push(int element) {
        if (top<size-1) {
            top++;
            arr[top] = element;
        }
        else {
            cout << "Stack is overflow!" << endl;
        }
    }
    //pop function
    void pop() {
        if (top >= 0) {
            top--;
        }
        else {
            cout << "Stack is empty!" << endl;
        }
    }
    //peek function
    int peek() {
        if (top >= 0) {
            return arr[top];
        }
        else {
            cout << "Stack is empty!" << endl;
            return -1;
        }
    }
    //empty function
    bool empty() {
        if (top == -1) {
            return true;
        }
        else {
            return false;
        }
    }
    //sorting algorithim
    void sortedinsert(Stack& inputstack, int num) {
        if (inputstack.empty() || inputstack.peek() < num) {
            inputstack.push(num);
            return;
        }
        int n = inputstack.peek();
        inputstack.pop();
        sortedinsert(inputstack, num);
        inputstack.push(n);

    }
    void sortedstack(Stack& inputstack) {
        if (inputstack.empty()) {
            return;
        }
        int num = inputstack.peek();
        inputstack.pop();
        //recursive call
        sortedstack(inputstack);
        sortedinsert(inputstack, num);
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
    int size = 11;
    Stack s(size);
    for (int i = 0; i < size; i++) {
        if (i % 2 == 0)
            s.push(i * 3);
        else
            s.push(i + 8); 
    }
    cout << "UN-SORTED STACK" << endl;
    s.display();
    s.sortedstack(s);
    cout << "SORTED STACK" << endl;
    s.display();


}