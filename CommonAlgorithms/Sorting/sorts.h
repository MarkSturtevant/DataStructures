#ifndef SORTS_H
#define SORTS_H

#include <iostream>
#include <vector>
#include "heap.h"

using std::cout, std::endl, std::vector, std::string;

// Pretty printing for vectors of Printable objects (have ostream operator<< defined)
// Be careful: modifications risk failing tests
template <class Printable>
std::ostream& operator<<(std::ostream& os, const std::vector<Printable>& container) {
    os << "[";
    bool first = false;
    for (const Printable& t : container) {
        if (first) {
            os << ", ";
        }
        if (typeid(t) == typeid(std::string)) {
            os << "\"" << t << "\"";
        } else {
            os << t;
        }
        first = true;
    }
    os << "]";
    return os;
}

// Selection sort (example of implementation expectations)
template <class Comparable>
void selection_sort(vector<Comparable>& container) {
    // print the initial container
    cout << container << endl;
    
    if (container.empty()) {
        return;
    }

    for (size_t index = 0; index < container.size()-1; index++) {
        // do 1 pass of selection sort: find the min and swap it to the front
        size_t index_min = index;
        for (size_t i = index+1; i < container.size(); i++) {
            if (container[i] < container[index_min]) {
                index_min = i;
            }
        }
        Comparable t = container[index];
        container[index] = container[index_min];
        container[index_min] = t;
        
        // print the container after each pass
        cout << container << endl;
    }
}

template <class Comparable>
void insertion_sort(vector<Comparable>& container) {
    // print the initial container
    cout << container << endl;

    if (container.empty()) {
        return;
    }

    for (size_t i = 1; i < container.size(); ++i) {
        Comparable val = container[i];
        size_t j;

        for (j = i; j > 0; --j) {
            if (container[j-1] > val)
                container[j] = container[j-1];
            else break;
        }

        container[j] = val;

        // print the container after each pass
        cout << container << endl;
    }
}

template <class Comparable>
void heap_sort(vector<Comparable>& container) {
    // print the initial container
    cout << container << endl;

    if (container.empty()) {
        return;
    }

    vector<Comparable> heap = container;
    heapify(&heap);
    cout << heap << endl;

    size_t size = container.size();
    container.clear();

    for (size_t i = 0; i < size; ++i) {
        container.push_back(heap[1]);
        heap_delete_min(&heap);
        cout << heap << endl;
        cout << container << endl;
    }
}

template <class Comparable>
void merge_sort_helper(vector<Comparable>& container, size_t begin, size_t end) {

    if (begin + 1 == end)
        return;

    size_t mid = (begin + end - 1) / 2 + 1;
    merge_sort_helper(container, begin, mid);
    merge_sort_helper(container, mid, end);

    size_t a = begin;
    size_t b = mid;
    vector<Comparable> temp;

    while (a < mid && b < end) {
        if (container[a] < container[b]) {
            temp.push_back(container[a]);
            a++;
        } else {
            temp.push_back(container[b]);
            b++;
        }
    }
    while (a < mid) {
        temp.push_back(container[a]);
        a++;
    }
    while (b < end) {
        temp.push_back(container[b]);
        b++;
    }
    for (size_t i = 0; i < end - begin; ++i)
        container[begin + i] = temp[i];
    cout << container << endl;
}

template <class Comparable>
void merge_sort(vector<Comparable>& container) {
    // print the initial container
    cout << container << endl;

    if (container.empty()) {
        return;
    }
    merge_sort_helper(container, 0, container.size());
}

template <class Comparable>
void radix_sort(vector<Comparable>& container) {
    // print the initial container
    cout << container << endl;

    if (container.empty()) {
        return;
    }

    bool shouldContinue = true;
    for (size_t i = 0; shouldContinue; ++i) {
        shouldContinue = false;
        vector<vector<Comparable>> buckets;
        for (size_t x = 0; x < 10; ++x) {
            vector<Comparable> vc;
            buckets.push_back(vc);
        }

        for (Comparable c : container) {
            Comparable copy = c;
            for (size_t j = 0; j < i; ++j)
                copy /= 10;
            buckets[copy % 10].push_back(c);
            if (copy >= 10)
                shouldContinue = true;
        }
        size_t m = 0;
        for (auto& bucket : buckets) {
            for (auto& k : bucket) {
                container[m] = k;
                m++;
            }
            cout << bucket << " ";
        }
        cout << endl << container << endl;
    }

}

void radix_sort(vector<string>& container) {
    // print the initial container
    cout << container << endl;

    if (container.empty()) {
        return;
    }

    size_t max_length = 0;
    for (const string& s : container)
        max_length = std::max(max_length, s.length());

    for (size_t i = 0; i < max_length; ++i) {
        vector<vector<string>> buckets;
        for (size_t x = 0; x < 128; ++x) {
            vector<string> vc;
            buckets.push_back(vc);
        }
        for (const string& s : container) {
            if (s.length() <= max_length - i - 1)
                buckets['\0'].push_back(s);
            else buckets[s.at(max_length - i - 1)].push_back(s);
        }

        size_t m = 0;
        for (auto & bucket : buckets) {
            for (auto& k : bucket) {
                container[m] = k;
                m++;
            }
            cout << bucket << " ";
        }
        cout << endl << container << endl;
    }

}

template <class Comparable>
void shell_sort(vector<Comparable>& container) {}

template <class Comparable>
void quick_sort(vector<Comparable>& container) {}

template <class Comparable>
void bucket_sort(vector<Comparable>& container) {}

#endif  // SORTS_H