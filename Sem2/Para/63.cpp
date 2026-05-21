#include <iostream>
#include <string>

using namespace std;

template <typename T, int MAX_SIZE = 100>
class Stack {
private:
    T arr[MAX_SIZE];
    int topIndex;

public:
    Stack() {
        topIndex = -1;
    }

    bool isEmpty() const {
        return topIndex == -1;
    }

    void push(const T& value) {
        if (topIndex >= MAX_SIZE - 1) {
            cout << "Stack Overflow\n";
            return;
        }
        arr[++topIndex] = value;
    }

    void pop() {
        if (isEmpty()) {
            cout << "Error: Stack is empty\n";
            return;
        }
        topIndex--;
    }

    T top() const {
        if (isEmpty()) {
            cout << "Error: Stack is empty\n";
            return T();
        }
        return arr[topIndex];
    }

    void print() const {
        cout << "Stack: ";
        for (int i = 0; i <= topIndex; ++i) {
            cout << arr[i];
            if (i < topIndex) cout << " ";
        }
        cout << "\n";
    }
};

int main() {
    Stack<int> intStack;
    intStack.push(10);
    intStack.push(20);
    intStack.push(30);

    intStack.print();
    cout << "Popped: " << intStack.top() << "\n";
    intStack.pop();
    cout << "Top: " << intStack.top() << "\n\n";

    Stack<string> stringStack;
    stringStack.push("Hello");
    stringStack.push("World");

    stringStack.print();
    cout << "Popped: " << stringStack.top() << "\n";
    stringStack.pop();
    cout << "Top: " << stringStack.top() << "\n";

    stringStack.pop();
    stringStack.pop();

    return 0;
}