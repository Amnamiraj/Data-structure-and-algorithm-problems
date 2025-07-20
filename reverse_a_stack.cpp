#include <iostream>
using namespace std;

int const N = 20; // Stack size
char stack[N];
int top = -1;

// Push a character onto the stack
void push(char c) {
    if (top == N - 1) {
        cout << "The stack is full!" << endl;
        return;
    }
    top++;
    stack[top] = c;
}

// Pop a character from the stack
char pop() {
    if (top == -1) {
        cout << "The stack is empty!" << endl;
        return;
    }
    char c = stack[top];
    top--;
    return c;
}

// Return the current size of the stack
int length() {
    return top + 1;
}

// Reverse the stack and display elements
void reverse_a_stack() {
    if (top == -1) {
        cout << "The stack is empty! Nothing to reverse." << endl;
        return;
    }

    cout << "Reversed stack elements: ";
    while (top != -1) {
        cout << pop() << " "; // Pop and display elements
    }
    cout << endl;
}

int main() {
    // Example usage
    string input;
    cout << "Enter a string to push onto the stack: ";
    cin >> input;

    // Push all characters of the string onto the stack
    for (int i = 0; i < input.length(); i++) {
        push(input[i]);
    }

    // Reverse and display the stack
    reverse_a_stack();

    return 0;
}
