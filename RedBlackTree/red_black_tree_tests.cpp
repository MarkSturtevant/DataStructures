#include <iostream>
#include "red_black_tree.h"

using std::cout, std::endl, std::boolalpha;

int main() {
    RedBlackTree<int> tree1;

    cout << "TESTS1 - EMPTY TREE -----------------------------------" << endl;

    cout << "isEmpty: " << std::boolalpha << tree1.is_empty() << endl;
    cout << "contains 2: " << std::boolalpha << tree1.contains(2) << endl;
    tree1.remove(2);
    tree1.make_empty();
    try {
        tree1.find_min();
        cout << "!!! ISSUE: did not throw error on find_min" << endl;
    } catch (std::invalid_argument& e) {
        cout << "Caught exception on find_min()" << endl;
    }

    try {
        tree1.find_max();
        cout << "!!! ISSUE: did not throw error on find_min" << endl;
    } catch (std::invalid_argument& e) {
        cout << "Caught exception on find_max()" << endl;
    }
    cout << "Tree Diagram: " << endl;
    tree1.print_tree();

    cout << "TESTS2 - INSERTION -----------------------------------" << endl;
    int nums[100] = {185, 160, 58, 97, 170, 26, 67, 173, 45, 27, 30, 170, 168, 151, 40, 136, 149, 120, 27, 42, 155,
                     124, 11, 57, 124, 141, 86, 188, 41, 120, 183, 31, 47, 128, 101, 188, 188, 151, 52, 158, 9, 188,
                     173, 87, 116, 104, 149, 129, 12, 7, 161, 68, 0, 64, 153, 81, 155, 66, 67, 70, 47, 149, 41, 188,
                     168, 104, 190, 30, 59, 154, 21, 136, 126, 31, 162, 83, 48, 49, 152, 184, 15, 141, 102, 35, 48,
                     70, 119, 121, 116, 70, 133, 52, 189, 64, 124, 167, 36, 57, 117, 35};
    for (int i = 0; i < 100; ++i) {
        //cout << "Tree Diagram (adding " << i << "): " << endl;
        tree1.insert(nums[i]);
        //tree1.print_tree();
    }
    cout << "Tree Diagram: " << endl;
    tree1.print_tree();

    cout << "TESTS3 - OPERATIONS -----------------------------------" << endl;

    cout << "isEmpty: " << std::boolalpha << tree1.is_empty() << endl;

    cout << "contains 2: " << std::boolalpha << tree1.contains(2) << endl;
    cout << "contains 9: " << std::boolalpha << tree1.contains(9) << endl;
    cout << "contains 21: " << std::boolalpha << tree1.contains(21) << endl;
    cout << "contains 18: " << std::boolalpha << tree1.contains(18) << endl;

    cout << "Max: " << tree1.find_max() << endl;
    cout << "Min: " << tree1.find_min() << endl;

    cout << "TESTS4 - REMOVE [NOT ROOT] -----------------------------------" << endl;

    for (int i = 0; i < 94; ++i) {
        //cout << "Tree Diagram (adding " << i << "): " << endl;
        tree1.remove(nums[i]);
        //tree1.print_tree();
    }
    cout << "Tree Diagram: " << endl;
    tree1.print_tree();
    cout << std::endl;

    cout << "TESTS5 - OPERATIONS -----------------------------------" << endl;

    cout << "isEmpty: " << std::boolalpha << tree1.is_empty() << endl;

    cout << "contains 2: " << std::boolalpha << tree1.contains(2) << endl;
    cout << "contains 9: " << std::boolalpha << tree1.contains(9) << endl;
    cout << "contains 21: " << std::boolalpha << tree1.contains(21) << endl;
    cout << "contains 18: " << std::boolalpha << tree1.contains(18) << endl;

    cout << "Max: " << tree1.find_max() << endl;
    cout << "Min: " << tree1.find_min() << endl;

    cout << "TESTS6 - ADD BACK TEST -----------------------------------" << endl;

    tree1.insert(8);
    tree1.insert(8);
    tree1.insert(2);
    tree1.insert(16);
    tree1.insert(12);
    tree1.insert(1);
    tree1.insert(15);

    cout << "Tree Diagram: " << endl;
    tree1.print_tree();
    cout << endl;


    cout << "TESTS7 - Operators -----------------------------------" << endl;

    RedBlackTree<int> tree2(tree1);
    tree2.remove(20);
    tree2.remove(16);

    cout << "Tree Diagram (original): " << endl;
    tree1.print_tree();
    cout << "Tree Diagram (copied and modified): " << endl;
    tree2.print_tree();

    tree2 = tree1;

    tree2.remove(20);
    tree2.remove(16);

    cout << "Tree Diagram (original): " << endl;
    tree1.print_tree();
    cout << "Tree Diagram (copied and modified): " << endl;
    tree2.print_tree();

    cout << "TESTS8 - REMOVE [ROOT] -----------------------------------" << endl;

    tree2.make_empty();
    tree1 = tree2;
    tree1.insert(5);
    tree1.insert(6);
    tree1.remove(5);
    tree1.insert(4);
    tree1.insert(8);
    tree1.remove(6);
    tree1.remove(8);
    tree1.remove(4);

    cout << "Tree Diagram: " << endl;
    tree1.print_tree();

    cout << "TESTS9 - COPY CONSTRUCTOR: CLEARED -----------------------------------" << endl;
    RedBlackTree<int> tree3(tree1);

    tree3.insert(2);
    tree3.insert(4);

    cout << "Tree Diagram (original): " << endl;
    tree1.print_tree();
    cout << "Tree Diagram (copied and modified): " << endl;
    tree3.print_tree();

    cout << "TESTS10 - STRESS TEST -----------------------------------" << endl;
    tree1.make_empty();
    cout << "Stress Test Beginning" << endl;
    int stress = 100000;
    for (int i = 0; i < stress; ++i)
        tree1.insert(i);

    for (int i = stress-1; i >= 0; --i)
        tree1.remove(i);

    for (int i = stress-1; i >= 0; --i)
        tree1.insert(i);

    for (int i = 0; i < stress; ++i)
        tree1.remove(i);
    cout << "Stress Test Finished" << endl;

    cout << "Tree Diagram (should be empty): " << endl;
    tree1.print_tree();
}
