#include "heap.h"

#include <iostream>
#include <vector>

using std::cout, std::endl, std::vector, std::string;

template<class Comparable>
void printVector(vector<Comparable>& vec) {
    if (vec.empty()) {
        cout << "[]" << endl;
        return;
    }

    cout << "[";
    for (size_t i = 0; i < vec.size()-1; ++i)
        cout << vec.at(i) << ", ";
    cout << vec.at(vec.size()-1) << "]" << endl;
}

template <class Container, class Compare=std::less<typename Container::value_type>>
void checkHeap(Container& vec, Compare lessThan =std::less<typename Container::value_type>{}) {
    bool good = true;
    for (size_t i = 1; i < vec.size(); ++i) {
        size_t j = i*2, k = i*2+1;
        if (j < vec.size() && vec[j] < vec[i]) {
            good = false;
            break;
        }
        if (k < vec.size() && vec[k] < vec[i]) {
            good = false;
            break;
        }
    }
    cout << (good ? "Heap Order Satisfied" : "ISSUE: Heap Order Not Satisfied.") << endl;
}

int main() {
    vector<int> A = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};

    cout << "Before Heapify: ";
    printVector(A);
    cout << "After Heapify: ";
    heapify(&A);
    printVector(A);
    checkHeap(A);
    cout << endl;

    A = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    cout << "Before Heapify: ";
    printVector(A);
    cout << "After Heapify: ";
    heapify(&A);
    printVector(A);
    checkHeap(A);
    cout << endl;

    A = {5, 1, 2, 1, 5, 3, 4, 2, 9, 10};

    cout << "Before Heapify: ";
    printVector(A);
    cout << "After Heapify: ";
    heapify(&A);
    printVector(A);
    checkHeap(A);
    cout << endl;

    A = {2, 1};

    cout << "Before Heapify: ";
    printVector(A);
    cout << "After Heapify: ";
    heapify(&A);
    printVector(A);
    checkHeap(A);
    cout << endl;

    A = {1};

    cout << "Before Heapify: ";
    printVector(A);
    cout << "After Heapify: ";
    heapify(&A);
    printVector(A);
    checkHeap(A);
    cout << endl;

    A = {};

    cout << "Before Heapify: ";
    printVector(A);
    cout << "After Heapify: ";
    heapify(&A);
    printVector(A);
    checkHeap(A);
    cout << endl;

    A = {1, 1, 1, 1};

    cout << "Before Heapify: ";
    printVector(A);
    cout << "After Heapify: ";
    heapify(&A);
    printVector(A);
    checkHeap(A);
    cout << endl;

    A = {4, 4, 4, 4, 2, 1, 2, 1, 3, 3, 3};

    cout << "Before Heapify: ";
    printVector(A);
    cout << "After Heapify: ";
    heapify(&A);
    printVector(A);
    checkHeap(A);
    cout << endl;

    A = {10, 10, 5, 1, 1, 1, 4, 3, 9, 8, 17, 19, 19};

    cout << "Before Heapify: ";
    printVector(A);
    cout << "After Heapify: ";
    heapify(&A);
    printVector(A);
    checkHeap(A);
    cout << endl;

    A = {-4, -1, -2, -6, -3, -1, -6, -8};

    cout << "Before Heapify: ";
    printVector(A);
    cout << "After Heapify: ";
    heapify(&A);
    printVector(A);
    checkHeap(A);
    cout << endl;

    vector<string> B = {"A", "B", "C", "D"};

    cout << "Before Heapify: ";
    printVector(B);
    cout << "After Heapify: ";
    heapify(&B);
    printVector(B);
    checkHeap(B);
    cout << endl;

    B = {"D", "C", "B", "A"};

    cout << "Before Heapify: ";
    printVector(B);
    cout << "After Heapify: ";
    heapify(&B);
    printVector(B);
    checkHeap(B);
    cout << endl;

    A.clear();
    for (int i = 0; i < 101; ++i)
        A.push_back((i * i) % 201);

    cout << "Before Heapify: ";
    printVector(A);
    cout << "After Heapify: ";
    heapify(&A);
    printVector(A);
    checkHeap(A);
    cout << endl;


    // --------------------------------------------------------------------
    // Insert Tests

    A.clear();
    cout << "Heap after various inserts: ";
    heapify(&A);
    heap_insert(&A, 1);
    heap_insert(&A, 2);
    heap_insert(&A, 3);
    heap_insert(&A, 4);
    heap_insert(&A, 5);
    heap_insert(&A, -2);
    heap_insert(&A, -1);
    heap_insert(&A, 0);
    heap_insert(&A, 1);
    printVector(A);
    checkHeap(A);

    cout << "Heap after inserting at root: ";
    heap_insert(&A, -10);
    printVector(A);
    checkHeap(A);

    cout << "Heap after inserting in the middle: ";
    heap_insert(&A, -2);
    printVector(A);
    checkHeap(A);

    cout << "Heap after inserting at the end: ";
    heap_insert(&A, 10);
    printVector(A);
    checkHeap(A);


    // --------------------------------------------------------------------
    // Remove Tests

    A = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    heapify(&A);

    cout << "Before Removing: ";
    printVector(A);
    cout << endl;

    cout << "Heap Status: ";
    heap_delete_min(&A);
    printVector(A);
    checkHeap(A);
    cout << endl;

    cout << "Heap Status: ";
    heap_delete_min(&A);
    printVector(A);
    checkHeap(A);
    cout << endl;

    cout << "Heap Status: ";
    heap_delete_min(&A);
    printVector(A);
    checkHeap(A);
    cout << endl;

    cout << "Heap Status: ";
    heap_delete_min(&A);
    printVector(A);
    checkHeap(A);
    cout << endl;

    cout << "Heap Status: ";
    heap_delete_min(&A);
    printVector(A);
    checkHeap(A);
    cout << endl;

    cout << "Heap Status: ";
    heap_delete_min(&A);
    printVector(A);
    checkHeap(A);
    cout << endl;

    // ------------------------------------------------
    // Other Tests

    A = {};
    heapify(&A);

    try {
        heap_get_min(A);
        cout << "Did not catch exception." << endl;
    } catch (std::invalid_argument& e) {
        cout << "Successfully caught exception." << endl;
    }

    try {
        heap_delete_min(&A);
        cout << "Did not catch exception." << endl;
    } catch (std::invalid_argument& e) {
        cout << "Successfully caught exception." << endl;
    }

    heap_insert(&A, 1);
    cout << "Min: " << heap_get_min(A) << endl;
    heap_delete_min(&A);

    try {
        heap_get_min(A);
        cout << "Did not catch exception." << endl;
    } catch (std::invalid_argument& e) {
        cout << "Successfully caught exception." << endl;
    }

    try {
        heap_delete_min(&A);
        cout << "Did not catch exception." << endl;
    } catch (std::invalid_argument& e) {
        cout << "Successfully caught exception." << endl;
    }

    cout << "Current Heap: ";
    printVector(A);

    heap_insert(&A, 4);
    heap_insert(&A, 3);
    heap_insert(&A, 1);
    heap_insert(&A, 0);
    heap_delete_min(&A);
    heap_delete_min(&A);
    heap_insert(&A, 4);
    heap_insert(&A, 3);
    heap_insert(&A, 1);
    heap_insert(&A, 0);
    heap_delete_min(&A);
    heap_delete_min(&A);
    heap_delete_min(&A);

    cout << "Current Heap: ";
    printVector(A);
    checkHeap(A);



    // -------------------------------------------------
    // Teacher Given Tests

    cout << endl << endl << "Teacher Given Tests" << endl;

    std::vector<int> heap{150,80,40,30,10,70,110,100,20,90,60,50,120,140,130};

    std::cout << "before heapify: ";
    for (int i : heap) { std::cout << i << " "; }
    std::cout << std::endl;

    heapify(&heap);

    std::cout << "after heapify: ";
    for (int i : heap) { std::cout << i << " "; }
    std::cout << std::endl;

    for (unsigned j = 0; j < 4; j++) {
        std::cout << "minimum is " << heap_get_min(heap) << std::endl;

        std::cout << "delete min" << std::endl;
        heap_delete_min(&heap);

        std::cout << "heap: ";
        for (int i : heap) { std::cout << i << " "; }
        std::cout << std::endl;
    }

    int values[] = {47,54,57,43,120,3};
    for (unsigned j = 0; j < 6; j++) {
        std::cout << "insert " << values[j] << std::endl;
        heap_insert(&heap, values[j]);

        std::cout << "heap: ";
        for (int i : heap) { std::cout << i << " "; }
        std::cout << std::endl;
    }


    return 0;
}
