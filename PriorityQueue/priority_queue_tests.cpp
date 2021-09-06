#include "priority_queue.h"
#include <iostream>
#include <vector>
#include <deque>

using std::cout, std::endl, std::vector, std::string;

int main() {
    /*
    vector<int> thing = {150, 80, 40, 30, 10 ,70 ,110 ,100, 20 ,90, 60 ,50 ,120 ,140, 130};
    heapify(&thing);
    heap_delete_min(&thing);
    heap_delete_min(&thing);
    heap_delete_min(&thing);
    heap_delete_min(&thing);
    for (int i = 0; i < thing.size(); ++i)
        cout << thing[i] << " ";
    */

    PriorityQueue<int, vector<int>, std::less<int>> queue;

    cout << "Queue: "; queue.print_queue();
    cout << "Size: " << queue.size() << endl;
    cout << "Is Empty? " << queue.empty() << endl;

    cout << "Catches Exceptions? ";
    try {
        queue.pop();
        cout << "No ";
    } catch (std::invalid_argument& e) {
        cout << "Yes ";
    }
    try {
        queue.top();
        cout << "No " << endl;
    } catch (std::invalid_argument& e) {
        cout << "Yes " << endl;
    }


    cout << "\nAdding 5, 9, 1, and 3\n" << endl;
    queue.push(5);
    queue.push(9);
    queue.push(1);
    queue.push(3);

    cout << "Queue: "; queue.print_queue();
    cout << "Size: " << queue.size() << endl;
    cout << "Is Empty? " << queue.empty() << endl;
    cout << "Top: " << queue.top() << endl;

    cout << "\nRemoving the min twice\n" << endl;
    queue.pop();
    queue.pop();

    cout << "Queue: "; queue.print_queue();
    cout << "Size: " << queue.size() << endl;
    cout << "Is Empty? " << queue.empty() << endl;
    cout << "Top: " << queue.top() << endl;

    cout << "\nMaking the queue empty" << endl;
    queue.make_empty();

    cout << "Queue: "; queue.print_queue();
    cout << "Size: " << queue.size() << endl;
    cout << "Is Empty? " << queue.empty() << endl;

    queue.push(5);
    queue.push(2);

    cout << "\nCopying the Queue." << endl;
    PriorityQueue<int> queue2(queue);
    queue2.pop();

    cout << "Queue1: "; queue.print_queue();
    cout << "Queue2: "; queue2.print_queue();

    cout << "\nUsing the = operator" << endl;
    PriorityQueue<int> queue3;
    queue3.push(8);
    queue3 = queue2;
    queue3.pop();

    cout << "Queue1: "; queue.print_queue();
    cout << "Queue2: "; queue2.print_queue();
    cout << "Queue3: "; queue3.print_queue();

    cout << "\nCreating a queue with a list" << endl;
    vector<int> vec = {5, 1, 2, 0, 9, 10, 6};
    PriorityQueue<int> queue4(vec);

    cout << "Queue: "; queue4.print_queue();
    cout << "Size: " << queue4.size() << endl;
    cout << "Is Empty? " << queue4.empty() << endl;
    cout << "Top: " << queue4.top() << endl;

    cout << "\nCreating a queue with a comparator" << endl;

    auto cmp = std::greater<std::string>();
    PriorityQueue<std::string, std::vector<std::string>, decltype(cmp)> pq(cmp);

    pq.push("A");
    pq.push("B");

    cout << "Queue: "; pq.print_queue();
    cout << "Size: " << pq.size() << endl;
    cout << "Is Empty? " << pq.empty() << endl;
    cout << "Top: " << pq.top() << endl;

    cout << "\nCreating a queue with a comparator AND an initial list" << endl;
    vector<string> vec2 = {"a", "b", "c", "d", "e"};
    PriorityQueue<std::string, std::vector<std::string>, decltype(cmp)> pq2(cmp, vec2);

    cout << "Queue: "; pq2.print_queue();
    cout << "Size: " << pq2.size() << endl;
    cout << "Is Empty? " << pq2.empty() << endl;
    cout << "Top: " << pq2.top() << endl;

    return 0;
}
