#ifndef ALGORITHMS_LSTACK_H
#define ALGORITHMS_LSTACK_H

#include "llist.h"

template<typename T = int>
class Stack {
public:
    Stack() : stack(nullptr), size(0) { }
    Stack(const Stack& s) : stack(nullptr), size(0) {
        for (L<T>* l = s.stack; l != nullptr; l = l->getNext()) {
            insert(l->getData());
        }
    }
    ~Stack() {
        if (stack != nullptr) {
            delete stack;
        }
        stack = nullptr;
    }

    /**
     * Adds an element to the stack.
     */
    void insert(T e) {
        L<T>* t = new L<T>(stack, e);
        stack = t;
        size++;
    }

    /**
     * Returns the top element of the stack.
     */
    T top() {
        // if the stack is empty => throw an error...
        if (size == 0) {
            throw -1;
        }
        return stack->getData();
    }

    /**
     * Pops an element from the stack.
     */
    T pop() {
        // if the stack is empty => throw an error...
        if (size == 0) {
            throw -1;
        }
        T d = stack->getData();
        L<T>* p = stack->getNext();
        stack->setNext(nullptr);
        delete stack;
        stack = p;
        size--;
        return d;
    }

    /**
     * Getter for the size of the stack.
     * @return size
     */
    int Size() const {
        return size;
    }

private:
    L<T>* stack;
    int size;
};

#endif //ALGORITHMS_LSTACK_H
