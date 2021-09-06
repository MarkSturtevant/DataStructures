#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

#include <vector>
#include "heap.h"

template <class Comparable, class Container=std::vector<Comparable>, class Compare=std::less<typename Container::value_type>>
class PriorityQueue {
private:
    Compare compare;
    Container container;
public:
    PriorityQueue();
    explicit PriorityQueue(const Compare& comparer);
    explicit PriorityQueue(const Container& container);
    PriorityQueue(const Compare& comparer, const Container& container);

    typename Container::const_reference top() const;
    bool empty() const;
    size_t size() const;

    void make_empty();
    void push(const typename Container::value_type& item);
    void pop();

    void print_queue(std::ostream& os = std::cout) const;
};

template <class Comparable, class Container, class Compare>
PriorityQueue<Comparable, Container, Compare>::PriorityQueue() :
        compare(Compare{}), container(Container{}) {
    heapify(&container, compare);
}

template <class Comparable, class Container, class Compare>
PriorityQueue<Comparable, Container, Compare>::PriorityQueue(const Compare& comparer) :
        compare(comparer), container(Container{}){
    heapify(&container, compare);
}

template <class Comparable, class Container, class Compare>
PriorityQueue<Comparable, Container, Compare>::PriorityQueue(const Container& container) :
        compare(Compare{}), container(container) {
    heapify(&(this->container), compare);
}

template <class Comparable, class Container, class Compare>
PriorityQueue<Comparable, Container, Compare>::PriorityQueue(const Compare& comparer, const Container& container) :
        compare(comparer), container(container) {
    heapify(&(this->container), compare);
}

template <class Comparable, class Container, class Compare>
typename Container::const_reference PriorityQueue<Comparable, Container, Compare>::top() const {
    return heap_get_min(container);
}

template <class Comparable, class Container, class Compare>
bool PriorityQueue<Comparable, Container, Compare>::empty() const {
    return container.size() == 1;
}

template <class Comparable, class Container, class Compare>
size_t PriorityQueue<Comparable, Container, Compare>::size() const {
    return container.size() - 1;
}

template <class Comparable, class Container, class Compare>
void PriorityQueue<Comparable, Container, Compare>::make_empty() {
    container.clear();
    heapify(&container, compare);
}

template <class Comparable, class Container, class Compare>
void PriorityQueue<Comparable, Container, Compare>::push(const typename Container::value_type &item) {
    heap_insert(&container, item, compare);
}

template <class Comparable, class Container, class Compare>
void PriorityQueue<Comparable, Container, Compare>::pop() {
    try {
        heap_delete_min(&container, compare);
    } catch (std::invalid_argument& e) {

    }

}

template <class Comparable, class Container, class Compare>
void PriorityQueue<Comparable, Container, Compare>::print_queue(std::ostream& os) const {
    if (this->empty()) {
        os << "<empty>" << std::endl;
        return;
    }
    size_t size = this->size();
    for (size_t i = 1; i < size; ++i)
        os << container[i] << ", ";
    os << container[size] << std::endl;
}

#endif  // PRIORITY_QUEUE_H