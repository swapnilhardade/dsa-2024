#include <iostream>
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

// Function to convert infix to postfix
string infixToPostfix(string infix) {
    Stack s;
    string postfix = "";

    for (char c : infix) {
        if (isalnum(c)) {
            postfix += c;
        } 
        else if (c == '(') {
            s.push(c);
        } 
        else if (c == ')') {
            while (!s.isEmpty() && s.peek() != '(') {
                postfix += s.pop();
            }
            s.pop(); // remove '('
        } 
        else if (isOperator(c)) {
            while (!s.isEmpty() && precedence(s.peek()) >= precedence(c)) {
                postfix += s.pop();
            }
            s.push(c);
        }
    }

    while (!s.isEmpty()) {
        postfix += s.pop();
    }

    return postfix;
}

// Main function
int main() {
    string infix;

    cout << "Enter an infix expression: ";
    cin >> infix;

    string postfix = infixToPostfix(infix);
    cout << "Equivalent postfix expression: " << postfix << endl;

    return 0;
}
