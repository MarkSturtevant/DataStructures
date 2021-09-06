#ifndef STACK_H
#define STACK_H

#include <stdexcept>
#include "array_list.h"

template <typename Object>
class Stack {
private:
    ArrayList<Object>* arr;

public:
    Stack();
    ~Stack();
    Stack(const Stack& other);
    Stack& operator=(const Stack& other);

    unsigned int stackSize();
    void push(const Object& toAdd);
    void pop();
    Object& top();
};

template <typename Object>
Stack<Object>::Stack() {
    arr = new ArrayList<Object>;
}

template <typename Object>
Stack<Object>::~Stack() {
    delete arr;
}

template <typename Object>
Stack<Object>& Stack<Object>::operator=(const Stack& other) {
    if (this == &other)
        return *this;
    delete this->arr;
    this->arr = new ArrayList<Object>(*(other.arr));
    return *this;
}

template <typename Object>
Stack<Object>::Stack(const Stack& other) {
    this->arr = new ArrayList<Object>(*(other.arr));
}

template <typename Object>
void Stack<Object>::push(const Object& toAdd) {
    arr->insert(arr->size(), toAdd);
}

template <typename Object>
void Stack<Object>::pop() {
    if (arr->size() == 0)
        throw std::out_of_range("Stack is empty!");
    else arr->remove(arr->size()-1);
}

template <typename Object>
Object& Stack<Object>::top() {
    if (arr->size() == 0)
        throw std::out_of_range("Stack is empty!");
    return (*arr)[arr->size()-1];
}

template <typename Object>
unsigned int Stack<Object>::stackSize() {
    return arr->size();
}

#endif  // STACK_H