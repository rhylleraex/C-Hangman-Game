#ifndef STACKS_H
#define STACKS_H

#include "LinkedList.h"

class Stack {
private:
    LinkedList list;

public:
    Stack();

    void push(char value);
    bool pop(char &removedValue);
    bool peek(char &topValue) const;
    bool isEmpty() const;
    void display() const;
};

#endif
