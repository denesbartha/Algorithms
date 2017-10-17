#include <iostream>
#include "lstack.h"

/**
 * Defines the queue data structure using 2 stacks.
 */
class Queue2 {
public:
    /**
     * Appends an element to the queue.
     * @param e
     */
    void append(int e) {
        s1.insert(e);
    }

    /**
     * Pops the first element of the queue.
     * @return
     */
    int pop() {
        // if the size is empty => throw an error
        if (s1.isEmpty()) {
            throw -1;
        }

        // take out every element from s1 to s2
        while (!s1.isEmpty()) {
            s2.insert(s1.pop());
        }
        int d = s2.pop();
        // take out every element from s2 to s1
        while (!s2.isEmpty()) {
            s1.insert(s2.pop());
        }
        return d;
    }

    /**
     * @return the last element of the queue.
     */
    int last() {
        // if the size is empty => throw an error
        if (s1.isEmpty()) {
            throw -1;
        }
        return s1.top();
    }

    /**
     * @return the first element of the queue.
     */
    int first() {
        // if the size is empty => throw an error
        if (s1.isEmpty()) {
            throw -1;
        }

        // take out every element from s1 to s2
        while (!s1.isEmpty()) {
            s2.insert(s1.pop());
        }
        int d = s2.top();
        // take out every element from s2 to s1
        while (!s2.isEmpty()) {
            s1.insert(s2.pop());
        }
        return d;
    }

    /**
     * @return the size of the queue.
     */
    int Size() const {
        return s1.Size();
    }
private:
    Stack<int> s1;
    Stack<int> s2;
};

void demonstrate_class06() {
    std::cout << "####################################" << std::endl;
    std::cout << "######Demonstrate Class06###########" << std::endl;
    std::cout << "####################################" << std::endl;
    std::cout << "Create queue..." << std::endl;
    Queue2 q;
    q.append(1);
    q.append(2);
    q.append(3);
    std::cout << "Size of the queue: " << q.Size() << std::endl;
    std::cout << "The first element: " << q.first() << std::endl;
    std::cout << "The last element: " << q.last() << std::endl;
    std::cout << "Pop out an element: " << q.pop() << std::endl;
    std::cout << "Size of the queue: " << q.Size() << std::endl;
    std::cout << "Pop out an element: " << q.pop() << std::endl;
    std::cout << "Size of the queue: " << q.Size() << std::endl;
    std::cout << "Pop out an element: " << q.pop() << std::endl;
    std::cout << "Size of the queue: " << q.Size() << std::endl;
    try {
        std::cout << "Pop out an element: " << q.pop() << std::endl;
    }
    catch (int e) {
        if (e == -1) {
            std::cout << "The pop operation failed for the empty queue..." << std::endl;
            std::cout << "Size of the queue: " << q.Size() << std::endl;
        }
    }
}