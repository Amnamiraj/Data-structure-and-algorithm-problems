#include <iostream>
#include<stack>
using namespace std;
bool validparanthesis(string expression) {
	stack<char> s;
	for (int i = 0; i < expression.length(); i++) {
		char ch = expression[i];
		if (ch == '(' || ch == '{' || ch == '[') {
			s.push(ch);
		}
		else {
			if (!s.empty()) {
				char top = s.top();
				if ((ch == ')' && top == '(') || (ch == '}' && top == '{') || (ch == ']' && top == '[')) {
					s.pop();
				}
				else {
					return false;
				}
			}
			else {
				return false;
			}
		}
	}
	if (s.empty()) {
		return true;
	}
	else {
		return false;
	}

}
int main()
{
	string expression;
	cout << "Enter a expression for paranthesis: ";
	cin >> expression;
	bool ans = validparanthesis(expression);
	if (ans == true) {
		cout << "This is a balanced expression!";
	}
	else {
		cout << "This is a unbalanced expression!";
	}


}

