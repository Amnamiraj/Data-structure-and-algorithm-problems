#include <iostream>
#include<string>
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
        return '\0'; // Return null character if the stack is empty
    }
    char c = stack[top];
    top--;
    return c;
}

// Reverse a string using the stack
void reverse(string s) {
    // Push all characters of the string onto the stack
    for (int i = 0; i < s.length(); i++) {
        push(s[i]);
    }

    // Pop all characters from the stack to print the reversed string
    cout << "Reversed string: ";
    while (top != -1) {
        cout << pop();
    }
    cout << endl;
}

int main() {
    string s;
    cout << "Enter a string: ";
    getline(cin, s); // Use getline to handle spaces in input
    reverse(s);

    return 0;
}
