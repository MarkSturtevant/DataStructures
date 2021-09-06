#include <iostream>
#include "binary_search_tree.h"

using std::cout, std::endl, std::boolalpha;

int main() {
    BinarySearchTree<int> tree1;

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
    tree1.insert(10);
    tree1.insert(7);
    tree1.insert(9);
    tree1.insert(8);
    tree1.insert(13);
    tree1.insert(15);
    tree1.insert(21);
    tree1.insert(5);
    tree1.insert(1);
    cout << "Tree Diagram: " << endl;
    tree1.print_tree();

    cout << "TESTS3 - OPERATIONS -----------------------------------" << endl;

    cout << "isEmpty: " << std::boolalpha << tree1.is_empty() << endl;

    cout << "contains 2: " << std::boolalpha << tree1.contains(2) << endl;
    cout << "contains 10: " << std::boolalpha << tree1.contains(10) << endl;
    cout << "contains 8: " << std::boolalpha << tree1.contains(8) << endl;
    cout << "contains 15: " << std::boolalpha << tree1.contains(15) << endl;

    cout << "Max: " << tree1.find_max() << endl;
    cout << "Min: " << tree1.find_min() << endl;

    cout << "TESTS4 - REMOVE [NOT ROOT] -----------------------------------" << endl;

    tree1.remove(8);
    tree1.remove(5);
    tree1.remove(15);
    tree1.remove(7);
    tree1.remove(6);

    cout << "Tree Diagram: " << endl;
    tree1.print_tree();

    cout << "TESTS5 - OPERATIONS -----------------------------------" << endl;

    cout << "isEmpty: " << std::boolalpha << tree1.is_empty() << endl;

    cout << "contains 2: " << std::boolalpha << tree1.contains(2) << endl;
    cout << "contains 10: " << std::boolalpha << tree1.contains(10) << endl;
    cout << "contains 8: " << std::boolalpha << tree1.contains(8) << endl;
    cout << "contains 15: " << std::boolalpha << tree1.contains(15) << endl;

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

    cout << "TESTS7 - Operators -----------------------------------" << endl;

    BinarySearchTree<int> tree2(tree1);
    tree2.remove(8);
    tree2.remove(1);

    cout << "Tree Diagram (original): " << endl;
    tree1.print_tree();
    cout << "Tree Diagram (copied and modified): " << endl;
    tree2.print_tree();

    tree2 = tree1;

    tree2.remove(8);
    tree2.remove(1);

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
    BinarySearchTree<int> tree3(tree1);

    tree3.insert(2);
    tree3.insert(4);

    cout << "Tree Diagram (original): " << endl;
    tree1.print_tree();
    cout << "Tree Diagram (copied and modified): " << endl;
    tree3.print_tree();
}
