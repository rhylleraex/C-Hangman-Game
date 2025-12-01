#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
using namespace std;

// Node structure for Linked List
struct Node {
    char data;
    Node* next;

    Node(char d) : data(d), next(nullptr) {}
};

class LinkedList {
private:
    Node* head;

    Node* copyList(const Node* otherHead);

public:
    LinkedList();
    LinkedList(const LinkedList& other);            // Copy constructor
    LinkedList& operator=(const LinkedList& other); // Assignment operator
    ~LinkedList();

    void insertAtHead(char value);
    bool removeHead(char& removedValue);
    bool isEmpty() const;
    void display() const;
};

#endif
