#ifndef ALGORITHMS_LSET_H
#define ALGORITHMS_LSET_H

#include "llist.h"
#include <iostream>

class Set {
public:
    Set() : start(nullptr), size(0) { }

    /**
     * Copy constructor
     * @param set
     */
    Set(const Set& set) : start(nullptr), size(0) {
        for (L* l = set.start; l != nullptr; l = l->getNext()) {
            add(l->getData());
        }
        size = set.size;
    }

    /**
     * Returns the size of the set.
     */
    int Size() const {
        return size;
    }

    /**
     * Resets the whole set (deletes every element).
     */
    void reset() {
        L* l = nullptr;
        while (start != nullptr) {
            l = start->getNext();
            start->setNext(nullptr);
            delete start;
            start = l;
        }
        start = nullptr;
        size = 0;
    }

    /**
     * Adds a new element to the set
     */
    void add(int e) {
        if (!contains(e)) {
            start = new L(start, e);
            size += 1;
        }
    }

    /**
     * Returns an element from the set.
     */
    int pop() {
        if (start == nullptr) {
            // error
            throw -1;
        }
        int d = start->getData();
        L* next = start->getNext();
        start->setNext(nullptr);
        delete start;
        start = next;
        size -= 1;
        return d;
    }

    /**
     * Returns true iff the set is empty.
     */
    bool isEmpty() const {
        return start == nullptr;
    }

    /**
     * Returns true iff the given element is inside the set.
     * @param e
     */
    bool contains(int e) const {
        for (L* l = start; l != nullptr; l = l->getNext()) {
            if (l->getData() == e) {
                return true;
            }
        }
        return false;
    }

    friend std::ostream& operator<<(std::ostream& o, const Set& set) {
        o << set.start;
        return o;
    }

private:
    L* start;
    int size;
};

#endif //ALGORITHMS_LSET_H
