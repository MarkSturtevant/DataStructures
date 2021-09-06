#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

#include <stdexcept>
#include <cstddef>

template<typename Object>
struct Node {
    Node* next;
    Node* previous;
    Object data;
};

template <typename Object>
class DoublyLinkedList {
private:
    size_t length;
    Node<Object>* startingNode;
    void clear();
    void copy(const DoublyLinkedList& other);

public:
    DoublyLinkedList();
    ~DoublyLinkedList();
    DoublyLinkedList(const DoublyLinkedList& other);
    DoublyLinkedList& operator=(const DoublyLinkedList& other);

    size_t size();
    Object& operator[](size_t index);
    void insert(size_t index, const Object& obj);
    void remove(size_t index);
};

template <typename Object>
void DoublyLinkedList<Object>::clear() {
    for (size_t i = 0; i < length; ++i) {
        Node<Object>* next = startingNode->next;
        delete startingNode;
        startingNode = next;
    }
}

template <typename Object>
void DoublyLinkedList<Object>::copy(const DoublyLinkedList<Object> &other) {
    if (other.length == 0) {
        startingNode = nullptr;
        return;
    }
    this->length = other.length;
    startingNode = new Node<Object>;
    startingNode->previous = nullptr;
    startingNode->next = nullptr;
    startingNode->data = other.startingNode->data;

    Node<Object>* traveler1 = startingNode; // used to build this list
    Node<Object>* traveler2 = other.startingNode; // used to get values from other list
    for (size_t i = 0; i < length-1; ++i) {
        traveler2 = traveler2->next;

        Node<Object>* toAdd = new Node<Object>;
        // setting toAdd data
        toAdd->data = traveler2->data;
        toAdd->previous = traveler1;
        toAdd->next = nullptr;
        // updating next of previous node in list
        traveler1->next = toAdd;

        traveler1 = traveler1->next;
    }
}

template <typename Object>
DoublyLinkedList<Object>::DoublyLinkedList() : length(0), startingNode(nullptr) {}

template <typename Object>
DoublyLinkedList<Object>::~DoublyLinkedList() {
    this->clear();
}

template <typename Object>
DoublyLinkedList<Object>::DoublyLinkedList(const DoublyLinkedList& other) : length(other.length),
    startingNode(nullptr) {

    this->copy(other);
}

template <typename Object>
DoublyLinkedList<Object>& DoublyLinkedList<Object>::operator=(const DoublyLinkedList& other) {
    // check for equivalence
    if (this == &other)
        return *this;
    // clear list
    this->clear();
    // form new list
    this->copy(other);
    // return
    return *this;
}

template <typename Object>
size_t DoublyLinkedList<Object>::size() {
    return length;
}

template <typename Object>
Object& DoublyLinkedList<Object>::operator[](size_t index) {
    if (index >= length)
        throw std::out_of_range("Get out of range!  index >= size");
    Node<Object>* temp = startingNode;
    for (size_t i = 0; i < index; ++i)
        temp = temp->next;
    return temp->data;
}

template <typename Object>
void DoublyLinkedList<Object>::insert(size_t index, const Object& obj) {
    if (index > length)
        throw std::out_of_range("Insert out of range!  index > size");
    Node<Object>* toAdd = new Node<Object>;
    toAdd->data = obj;
    if (index == 0) { // node is at beginning
        toAdd->previous = nullptr;
        toAdd->next = startingNode;
        if (startingNode != nullptr)
            startingNode->previous = toAdd;
        startingNode = toAdd;
    } else { // node is in middle / at end
        Node<Object>* temp = startingNode;
        // moving temp to the node directly behind the one to add
        for (size_t i = 0; i < index-1; ++i)
            temp = temp->next;
        // setting toAdd's next/prev
        toAdd->next = temp->next;
        toAdd->previous = temp;
        // updating list next/prev
        if (temp->next != nullptr) // node is not at end
            temp->next->previous = toAdd;
        temp->next = toAdd;
    }
    length++;
}

template <typename Object>
void DoublyLinkedList<Object>::remove(size_t index) {
    if (index >= length)
        throw std::out_of_range("Removal out of range!  index >= size");
    if (index == 0) {
        Node<Object>* temp = startingNode->next;
        if (temp != nullptr)
            temp->previous = nullptr;
        delete startingNode;
        startingNode = temp;
    } else {
        Node<Object>* temp = startingNode;
        // moving temp to the node to delete
        for (size_t i = 0; i < index; ++i)
            temp = temp->next;
        // deleting temp
        temp->previous->next = temp->next;
        if (temp->next != nullptr) // node is not at end
            temp->next->previous = temp->previous;
        delete temp;
    }
    length--;
}

#endif  // DOUBLY_LINKED_LIST_H
