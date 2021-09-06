#include <iostream>
#include "array_list.h"

using std::cout, std::endl;

int main() {
    ArrayList<int> list;

    cout << "- (1)" << endl << list.size() << endl;

    list.insert(0, 1);
    list.insert(1, 4);
    list.insert(1, 5);
    list.insert(3, 9);

    cout << "- (2)" << endl << list[0] << " " << list[1] << " " << list[2] << " " << list[3] << endl;
    cout << list.size() << endl;

    list.remove(0);
    cout << "- (3)" << endl << list[0] << " " << list[1] << " " << list[2]  << endl;
    cout << list.size() << endl;

    list.remove(1);
    cout << "- (4)" << endl << list[0] << " " << list[1]  << endl;
    cout << list.size() << endl;

    ArrayList<int> list2(100);
    ArrayList<int> list3(list);

    cout << "- (5)" << endl << list3[0] << endl;

    list.remove(0);

    cout << "- (6)" << endl << list[0] << endl << list3[0] << endl;

    list = list3;

    cout << "- (7)" << endl << list[0] << endl << list3[0] << endl;

    cout << "- (8)" << endl;

    try {
        list[2];
        cout << "FAIL: did not catch exception on [] operation" << endl;
    } catch (std::out_of_range& e) {
        cout << "SUCCESS: caught exception on [] operation" << endl;
    }

    try {
        list.insert(3, 5);
        cout << "FAIL: did not catch exception on insert operation" << endl;
    } catch (std::out_of_range& e) {
        cout << "SUCCESS: caught exception on insert operation" << endl;
    }

    try {
        list.remove(2);
        cout << "FAIL: did not catch exception on remove operation" << endl;
    } catch (std::out_of_range& e) {
        cout << "SUCCESS: caught exception on remove operation" << endl;
    }

}
