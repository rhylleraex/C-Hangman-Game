#include "Stacks.h"
#include <iostream>

// Constructor
Stack::Stack() {}

// Push a character onto the stack
void Stack::push(char value) {
    list.insertAtHead(value);
}

// Pop a character from the stack
bool Stack::pop(char &removedValue) {
    return list.removeHead(removedValue);
}

// Peek at the top character without removing it
bool Stack::peek(char &topValue) const {
    if (list.isEmpty())
        return false;

    // Peek by temporarily popping + restoring
    LinkedList tempList = list;  // Uses default copy (shallow)
    char temp;

    if (tempList.removeHead(temp)) {
        topValue = temp;
        return true;
    }
    return false;
}

// Check if stack is empty
bool Stack::isEmpty() const {
    return list.isEmpty();
}

// Display contents of stack
void Stack::display() const {
    list.display();
}
