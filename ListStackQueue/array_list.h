#ifndef ARRAY_LIST_H
#define ARRAY_LIST_H

#include <stdexcept>
#include <cstddef>

template <typename Object>
class ArrayList {
private:
    size_t capacity, length;
    Object* arr;

public:
    ArrayList();
    explicit ArrayList(size_t arrSize);
    ~ArrayList();
    ArrayList(const ArrayList& other);
    ArrayList& operator=(const ArrayList& other);

    size_t size();
    Object& operator[](size_t index);
    void insert(size_t index, const Object& obj);
    void remove(size_t index);
};

template <typename Object>
ArrayList<Object>::ArrayList() : capacity(1), length(0), arr(new Object[capacity]) {}

template <typename Object>
ArrayList<Object>::ArrayList(size_t arrSize) : capacity(arrSize), length(0), arr(new Object[capacity]) {}

template <typename Object>
ArrayList<Object>::~ArrayList() {
    delete [] arr;
}

template <typename Object>
ArrayList<Object>& ArrayList<Object>::operator=(const ArrayList& other) {
    if (this == &other)
        return *this;
    delete [] this->arr;
    this->capacity = other.capacity;
    this->length = other.length;
    this->arr = new Object[capacity];
    for (unsigned int i = 0; i < length; ++i)
        this->arr[i] = other.arr[i];
    return *this;
}

template <typename Object>
ArrayList<Object>::ArrayList(const ArrayList& other) : capacity(other.capacity), length(other.length),
    arr(new Object[capacity]) {
    for (unsigned int i = 0; i < length; ++i)
        this->arr[i] = other.arr[i];
}

template <typename Object>
size_t ArrayList<Object>::size() {
    return length;
}

template <typename Object>
Object& ArrayList<Object>::operator[](size_t index) {
    if (index >= length)
        throw std::out_of_range("Get out of range! (index >= size)");
    return arr[index];
}

template <typename Object>
void ArrayList<Object>::insert(size_t index, const Object& obj) {
    if (index > length)
        throw std::out_of_range("Insertion out of range! (index > size)");
    if (length == capacity) {
        Object* expansion = new Object[capacity * 2];
        for (unsigned int i = 0; i < length; ++i)
            expansion[i] = arr[i];
        delete [] arr;
        this->arr = expansion;
        capacity *= 2;
    }
    for (size_t i = length - 1; i >= index && i < length; --i)
        arr[i+1] = arr[i];
    arr[index] = obj;
    length++;
}

template <typename Object>
void ArrayList<Object>::remove(size_t index) {
    if (index >= length)
        throw std::out_of_range("Removal out of range! (index >= size)");
    for (size_t i = index; i < length-1; ++i)
        arr[i] = arr[i+1];
    length--;
}



#endif  // ARRAY_LIST_H