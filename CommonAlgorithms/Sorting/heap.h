#ifndef HEAP_H
#define HEAP_H

#include <functional>
#include <iostream>

template <class Container, class Compare=std::less<typename Container::value_type>>
void heapify(Container* list, Compare lessThan = std::less<typename Container::value_type>{}) {
    // make first element null.  If there is a first element, move it to the end.
    const typename Container::value_type nothing{};
    if (list->empty()) {
        list->push_back(nothing);
        return;
    }
    list->insert(list->begin(), nothing);
    //list->push_back((*list)[0]);
    //(*list)[0] = nothing;

    // heapify
    for (size_t i = list->size() - 1; i >= 1; --i) {
        typename Container::value_type item = (*list)[i];
        size_t cIndex = i;
        while (true) {
            size_t aIndex = cIndex * 2, bIndex = cIndex * 2 + 1;
            if (bIndex < list->size()) {
                //std::cout << "Comparing: " << (*list)[cIndex] << " with " << (*list)[aIndex] << " and " << (*list)[bIndex] << std::endl;
                if (! lessThan((*list)[bIndex], (*list)[aIndex])) {
                    if (lessThan((*list)[aIndex], item)) {
                        //std::cout << "Swapping " << (*list)[cIndex] << " and " << (*list)[aIndex] << std::endl;
                        (*list)[cIndex] = (*list)[aIndex];
                        cIndex = aIndex;
                    }
                    else break;
                } else {
                    if (lessThan((*list)[bIndex], item)) {
                        //std::cout << "Swapping " << (*list)[cIndex] << " and " << (*list)[bIndex] << std::endl;
                        (*list)[cIndex] = (*list)[bIndex];
                        cIndex = bIndex;
                    }
                    else break;
                }
            }
            else if (aIndex < list->size()) {
                //std::cout << "Comparing: " << (*list)[cIndex] << " with " << (*list)[aIndex] << std::endl;
                if (lessThan((*list)[aIndex], item)) {
                    //std::cout << "Swapping " << (*list)[cIndex] << " and " << (*list)[aIndex] << std::endl;
                    (*list)[cIndex] = (*list)[aIndex];
                    cIndex = aIndex;
                }
                else break;
            }
            else break;
        }
        (*list)[cIndex] = item;
    }

}

template <class Container, class Compare=std::less<typename Container::value_type>>
void heap_delete_min(Container* list, Compare lessThan =std::less<typename Container::value_type>{}) {
    if (list->size() <= 1)
        throw std::invalid_argument("Heap is empty! :O");
    (*list)[1] = (*list)[list->size() - 1];
    list->pop_back();
    if (list->size() == 1)
        return;

    typename Container::value_type item = (*list)[1];
    size_t cIndex = 1;
    while (true) {
        size_t aIndex = cIndex * 2, bIndex = cIndex * 2 + 1;
        if (bIndex < list->size()) {
            //std::cout << "Comparing: " << (*list)[cIndex] << " with " << (*list)[aIndex] << " and " << (*list)[bIndex] << std::endl;
            if (! lessThan((*list)[bIndex], (*list)[aIndex])) {
                if (lessThan((*list)[aIndex], item)) {
                    //std::cout << "Swapping " << (*list)[cIndex] << " and " << (*list)[aIndex] << std::endl;
                    (*list)[cIndex] = (*list)[aIndex];
                    cIndex = aIndex;
                }
                else break;
            } else {
                if (lessThan((*list)[bIndex], item)) {
                    //std::cout << "Swapping " << (*list)[cIndex] << " and " << (*list)[bIndex] << std::endl;
                    (*list)[cIndex] = (*list)[bIndex];
                    cIndex = bIndex;
                }
                else break;
            }
        }
        else if (aIndex < list->size()) {
            //std::cout << "Comparing: " << (*list)[cIndex] << " with " << (*list)[aIndex] << std::endl;
            if (lessThan((*list)[aIndex], item)) {
                //std::cout << "Swapping " << (*list)[cIndex] << " and " << (*list)[aIndex] << std::endl;
                (*list)[cIndex] = (*list)[aIndex];
                cIndex = aIndex;
            }
            else break;
        }
        else break;
    }
    (*list)[cIndex] = item;
}

#endif  // HEAP_H