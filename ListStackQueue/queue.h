#ifndef QUEUE_H
#define QUEUE_H

#include <stdexcept>
#include "doubly_linked_list.h"

template <typename Object>
class Queue {
private:
    DoublyLinkedList<Object>* arr;

public:
    Queue();
    ~Queue();
    Queue(const Queue& other);
    Queue& operator=(const Queue& other);

    void enqueue(const Object& toAdd);
    Object dequeue();
    Object& front();
};

template <typename Object>
Queue<Object>::Queue() {
    arr = new DoublyLinkedList<Object>;
}

template <typename Object>
Queue<Object>::~Queue() {
    delete arr;
}

template <typename Object>
Queue<Object>& Queue<Object>::operator=(const Queue& other) {
    if (this == &other)
        return *this;
    delete this->arr;
    this->arr = new DoublyLinkedList<Object>(*(other.arr));
    return *this;
}

template <typename Object>
Queue<Object>::Queue(const Queue& other) {
    this->arr = new DoublyLinkedList<Object>(*(other.arr));
}

template <typename Object>
void Queue<Object>::enqueue(const Object& toAdd) {
    arr->insert(arr->size(), toAdd);
}

template <typename Object>
Object Queue<Object>::dequeue() {
    if (arr->size() == 0)
        throw std::out_of_range("Queue is empty!");
    Object output = (*arr)[0];
    arr->remove(0);
    return output;
}

template <typename Object>
Object& Queue<Object>::front() {
    if (arr->size() == 0)
        throw std::out_of_range("Queue is empty!");
    return (*arr)[0];
}

#endif  // QUEUE_H
