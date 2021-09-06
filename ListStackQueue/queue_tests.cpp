#include <iostream>
#include "queue.h"

using std::cout, std::endl;

int main() {
    cout << "- (1)" << endl;

    Queue<int> queue;

    queue.enqueue(4);
    queue.enqueue(6);
    queue.enqueue(9);

    cout << queue.front() << endl << "- (2)" << endl;

    Queue<int> queue2(queue);

    queue2.dequeue();

    cout << queue.front() << endl << queue2.front() << endl << "- (3)" << endl;

    queue = queue2;

    queue.dequeue();

    cout << queue.front() << endl << queue2.front() << endl << "- (4)" << endl;

    queue.dequeue();

    try {
        queue.dequeue();
        cout << "Failed to throw exception for empty dequeue." << endl;
    } catch (std::out_of_range& e) {
        cout << "Caught exception on dequeue: " << e.what() << endl;
    }

    try {
        queue.front();
        cout << "Failed to throw exception for empty front." << endl;
    } catch (std::out_of_range& e) {
        cout << "Caught exception on front: " << e.what() << endl;
    }

}
