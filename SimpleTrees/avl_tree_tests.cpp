#include <iostream>
#include "avl_tree.h"

using std::cout, std::endl, std::boolalpha;

int main() {
    AVLTree<int> tree1;

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
    tree1.insert(15);
    tree1.insert(18);
    tree1.insert(21);
    tree1.insert(20);
    tree1.insert(19);
    tree1.insert(12);
    tree1.insert(9);
    tree1.insert(17);
    tree1.insert(16);
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

    tree1.remove(16);
    tree1.remove(21);
    tree1.remove(20);
    tree1.remove(19);
    tree1.remove(6);

    cout << "Tree Diagram: " << endl;
    tree1.print_tree();

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

    cout << "TESTS7 - Operators -----------------------------------" << endl;

    AVLTree<int> tree2(tree1);
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
    AVLTree<int> tree3(tree1);

    tree3.insert(2);
    tree3.insert(4);

    cout << "Tree Diagram (original): " << endl;
    tree1.print_tree();
    cout << "Tree Diagram (copied and modified): " << endl;
    tree3.print_tree();

    cout << "TESTS10 - STRESS TEST -----------------------------------" << endl;
    tree1.make_empty();
    cout << "Stress Test Beginning" << endl;
    int stress = 32;
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
