#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

// Node structure for stack
struct Node {
    char data;
    Node* next;
};

// Stack class using singly linked list
class Stack {
private:
    Node* top;

public:
    Stack() { top = nullptr; }

    void push(char x) {
        Node* temp = new Node;
        temp->data = x;
        temp->next = top;
        top = temp;
    }

    char pop() {
        if (isEmpty()) {
            cout << "Stack Underflow\n";
            return '\0';
        }
        Node* temp = top;
        char x = temp->data;
        top = top->next;
        delete temp;
        return x;
    }

    char peek() {
        if (!isEmpty())
            return top->data;
        else
            return '\0';
    }

    bool isEmpty() {
        return top == nullptr;
    }
};

// Function to define operator precedence
int precedence(char op) {
    if (op == '^')
        return 3;
    else if (op == '*' || op == '/')
        return 2;
    else if (op == '+' || op == '-')
        return 1;
    else
        return 0;
}

// Function to check if character is operator
bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

// Function to convert infix to prefix
string infixToPrefix(string infix) {
    Stack s;
    string prefix = "";

    // Step 1: Reverse the infix expression
    reverse(infix.begin(), infix.end());

    // Step 2: Replace '(' with ')' and vice versa
    for (int i = 0; i < infix.length(); i++) {
        if (infix[i] == '(')
            infix[i] = ')';
        else if (infix[i] == ')')
            infix[i] = '(';
    }

    // Step 3: Convert reversed infix to postfix
    for (char c : infix) {
        if (isalnum(c)) {
            prefix += c;
        }
        else if (c == '(') {
            s.push(c);
        }
        else if (c == ')') {
            while (!s.isEmpty() && s.peek() != '(') {
                prefix += s.pop();
            }
            s.pop();
        }
        else if (isOperator(c)) {
            while (!s.isEmpty() && precedence(s.peek()) > precedence(c)) {
                prefix += s.pop();
            }
            s.push(c);
        }
    }

    while (!s.isEmpty()) {
        prefix += s.pop();
    }

    // Step 4: Reverse the result to get prefix
    reverse(prefix.begin(), prefix.end());
    return prefix;
}

// Main function
int main() {
    string infix;

    cout << "Enter an infix expression: ";
    cin >> infix;

    string prefix = infixToPrefix(infix);
    cout << "Equivalent prefix expression: " << prefix << endl;

    return 0;
}
