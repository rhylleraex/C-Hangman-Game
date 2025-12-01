#include "LinkedList.h"

// Constructor
LinkedList::LinkedList() : head(nullptr) {}

// Helper to deep copy nodes
Node* LinkedList::copyList(const Node* otherHead) {
    if (!otherHead) return nullptr;

    Node* newHead = new Node(otherHead->data);
    Node* currNew = newHead;
    const Node* currOld = otherHead->next;

    while (currOld != nullptr) {
        currNew->next = new Node(currOld->data);
        currNew = currNew->next;
        currOld = currOld->next;
    }
    return newHead;
}

// Copy constructor
LinkedList::LinkedList(const LinkedList& other) {
    head = copyList(other.head);
}

// Assignment operator
LinkedList& LinkedList::operator=(const LinkedList& other) {
    if (this != &other) {
        // Delete existing list
        Node* temp;
        while (head != nullptr) {
            temp = head;
            head = head->next;
            delete temp;
        }
        // Copy new list
        head = copyList(other.head);
    }
    return *this;
}

// Destructor
LinkedList::~LinkedList() {
    Node* current = head;
    while (current != nullptr) {
        Node* temp = current;
        current = current->next;
        delete temp;
    }
}

void LinkedList::insertAtHead(char value) {
    Node* newNode = new Node(value);
    newNode->next = head;
    head = newNode;
}

bool LinkedList::removeHead(char& removedValue) {
    if (head == nullptr)
        return false;

    Node* temp = head;
    removedValue = temp->data;
    head = head->next;
    delete temp;
    return true;
}

bool LinkedList::isEmpty() const {
    return head == nullptr;
}

void LinkedList::display() const {
    Node* current = head;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
}
