#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool findRedundantBrackets(string expression) {
    stack<char> s;
    for (int i = 0; i < expression.length(); i++) {
        char ch = expression[i];
        if (ch == '(' || ch == '+' || ch == '-' || ch == '*' || ch == '/') {
            s.push(ch);
        }
        else if (ch == ')') {
            bool isRedundant = true;
            while (!s.empty() && s.top() != '(') { 
                char top = s.top();
                if (top == '+' || top == '-' || top == '*' || top == '/') {
                    isRedundant = false;
                }
                s.pop();
            }
            if (!s.empty()) {
                s.pop();
            }
            if (isRedundant) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    string expression;
    cout << "Enter an expression: ";
    cin >> expression;

    if (findRedundantBrackets(expression)) {
        cout << "The expression has redundant brackets." << endl;
    }
    else {
        cout << "The expression does not have redundant brackets." << endl;
    }

    return 0;
}
