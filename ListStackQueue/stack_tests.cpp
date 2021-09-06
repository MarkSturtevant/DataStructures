#include <iostream>
#include "stack.h"

using std::cout, std::endl;

int main() {
    cout << "- (1)" << endl;

    Stack<int> stack;

    stack.push(4);
    stack.push(6);
    stack.push(9);

    cout << stack.top() << endl << "- (2)" << endl;

    Stack<int> stack2(stack);

    stack2.pop();

    cout << stack.top() << endl << "- (3)" << endl;

    stack = stack2;

    stack.pop();

    cout << stack.top() << endl << "- (4)" << endl;

    stack.pop();

    try {
        stack.pop();
        cout << "Failed to throw exception for empty pop." << endl;
    } catch (std::out_of_range& e) {
        cout << "Caught exception on pop: " << e.what() << endl;
    }

    try {
        stack.top();
        cout << "Failed to throw exception for empty top." << endl;
    } catch (std::out_of_range& e) {
        cout << "Caught exception on top: " << e.what() << endl;
    }

}

/* --- CASE 1 -------------------------------------------------------------------------------
 *
 * Stack<SpecialClass> stack;
 *
 * SpecialClass sc = new SpecialClass;
 * SpecialClass sc2 = new SpecialClass;
 *
 * stack.push(sc);
 * stack.push(sc2);
 *
 * delete sc;
 * delete sc2;
 *
 * end function.  what happens when the stack deletes the array?
 *
 * --- CASE 2 -------------------------------------------------------------------------------
 *
 * int globalInt1; // global variable outside of the function
 *
 * Stack<int> stack;
 * stack.add(globalInt1);
 *
 * end function. what happens when the stack deletes the array?  Can globalInt1 still be used?
 *
 * --- CASE 3 -------------------------------------------------------------------------------
 *
 * Stack<int> heapStack = new Stack;
 *
 * int toAdd = 2, toAdd2 = 4;
 *
 * heapStack.add(toAdd);
 * heapStack.add(toAdd2);
 *
 * delete heapStack;
 *
 * int num = toAdd + toAdd2; // what happens here?
 *
 * end function.
 *
 */