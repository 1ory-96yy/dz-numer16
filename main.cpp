#include <iostream>
#include <stack>
#include <string>
#include <Windows.h>
using namespace std;

#define MAX_SIZE 100 

class Stack {
private:
    int top;
    char arr[MAX_SIZE];
public:
    Stack() {
        top = -1;
    }

    bool isEmpty() {
        return (top == -1);
    }

    bool isFull() {
        return (top == MAX_SIZE - 1);
    }

    void push(char value) {
        if (isFull()) {
            cout << "Стек переповнений\n";
            return;
        }
        arr[++top] = value;
    }

    char pop() {
        if (isEmpty()) {
            cout << "Стек порожній\n";
            return -1;
        }
        return arr[top--];
    }

    char peek() {
        if (isEmpty()) {
            cout << "Стек порожній\n";
            return -1;
        }
        return arr[top];
    }
};

bool checkBrackets(const string& str) {
    Stack bracketsStack;
    for (char bracket : str) {
        if (bracket == '(' || bracket == '[' || bracket == '{') {
            bracketsStack.push(bracket);
        }
        else if (bracket == ')' || bracket == ']' || bracket == '}') {
            if (bracketsStack.isEmpty()) {
                return false;
            }
            char top = bracketsStack.peek();
            if ((bracket == ')' && top != '(') || (bracket == ']' && top != '[') || (bracket == '}' && top != '{')) {
                return false;
            }
            bracketsStack.pop();
        }
    }
    return bracketsStack.isEmpty();
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    string str;
    cout << "Введіть рядок з дужками: ";
    getline(cin, str);

    if (checkBrackets(str)) {
        cout << "Всі дужки розташовані правильно." << endl;
    }
    else {
        cout << "Дужки розташовані неправильно." << endl;
    }

    return 0;
}
