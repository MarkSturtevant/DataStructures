#include <iostream>
#include "doubly_linked_list.h"

using std::cout, std::endl;

int main() {
    DoublyLinkedList<int> list;

    cout << "- (1)" << endl << list.size() << endl;

    list.insert(0, 5);
    list.insert(0, 4);
    list.insert(0, 3);
    list.insert(1, 2);
    list.insert(1, 1);
    list.insert(5, 10);
    list.insert(6, 11);
    list.insert(6, 12);
    // list should be 3 1 2 4 5 10 12 11

    cout << "- (2)" << endl;
    for (size_t i = 0; i < 8; ++i)
        cout << list[i] << " ";
    cout << endl << list.size() << endl;

    list.remove(0);
    list.remove(6);
    list.remove(2);

    cout << "- (3)" << endl;
    for (size_t i = 0; i < 5; ++i)
        cout << list[i] << " ";
    cout << endl << list.size() << endl;

    DoublyLinkedList<int> list2(list);

    list2.remove(1);

    cout << "- (4)" << endl;
    for (size_t i = 0; i < 4; ++i)
        cout << list2[i] << " ";
    cout << endl << list2.size() << endl;

    list2 = list;

    cout << "- (5)" << endl;
    for (size_t i = 0; i < 5; ++i)
        cout << list[i] << " ";
    cout << endl << list.size() << endl;

    cout << "- (6)" << endl;

    DoublyLinkedList<int> test;
    test.insert(0, 1);
    test.insert(1, 2);
    list2 = test;
    test.insert(2, 3);
    list2.remove(1);

    cout << "- (7)" << endl;

    try {
        list[5];
        cout << "FAIL: did not catch exception on [] operation" << endl;
    } catch (std::out_of_range& e) {
        cout << "SUCCESS: caught exception on [] operation" << endl;
    }

    try {
        list.insert(6, 5);
        cout << "FAIL: did not catch exception on insert operation" << endl;
    } catch (std::out_of_range& e) {
        cout << "SUCCESS: caught exception on insert operation" << endl;
    }

    try {
        list.remove(5);
        cout << "FAIL: did not catch exception on remove operation" << endl;
    } catch (std::out_of_range& e) {
        cout << "SUCCESS: caught exception on remove operation" << endl;
    }
}