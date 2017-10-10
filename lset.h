#ifndef ALGORITHMS_LSET_H
#define ALGORITHMS_LSET_H

#include "llist.h"
#include <iostream>

template <typename T = int>
class Set {
public:
    Set() : start(nullptr), size(0) { }

    /**
     * Copy constructor
     * @param set
     */
    Set(const Set& set) : start(nullptr), size(0) {
        for (L<T>* l = set.start; l != nullptr; l = l->getNext()) {
            add(l->getData());
        }
        size = set.size;
    }

    ~Set() {
        if (start != nullptr) {
            delete start;
        }
        start = nullptr;
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
        L<T>* l = nullptr;
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
    void add(T e) {
        if (!contains(e)) {
            start = new L<T>(start, e);
            size += 1;
        }
    }

    /**
     * Returns an element from the set.
     */
    T pop() {
        if (start == nullptr) {
            // error
            throw -1;
        }
        T d = start->getData();
        L<T>* next = start->getNext();
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
    bool contains(T e) const {
        for (L<T>* l = start; l != nullptr; l = l->getNext()) {
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
    L<T>* start;
    int size;
};

#endif //ALGORITHMS_LSET_H
