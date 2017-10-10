#include <iostream>
#include "llist.h"
#include "lset.h"

L<>* filter_negative_elements(L<>*& l1) {
    // filter out the negative elements to l2
    L<>* l2 = nullptr;
    L<>* s = l1;
    L<>* q = nullptr;
    while (s != nullptr && s->getData() < 0) {
        if (l2 == nullptr) {
            l2 = s;
        }
        q = s;
        s = s->getNext();
    }
    l1 = s;
    L<>* t = s;
    // filter out the rest
    while (t != nullptr) {
        if (t->getData() < 0) {
            if (l2 == nullptr) {
                l2 = q = t;
            }
            else {
                q->setNext(t);
                q = t;
            }
            s->setNext(t->getNext());
            t = t->getNext();
        }
        else {
            s = t, t = t->getNext();
        }
    }
    if (l2 != nullptr) {
        q->setNext(nullptr);
    }
    return l2;
}



void demonstrate_class04() {
    std::cout << "####################################" << std::endl;
    std::cout << "######Demonstrate Class04###########" << std::endl;
    std::cout << "####################################" << std::endl;
    L<>* l = new L<>(new L<>(new L<>(new L<>(new L<>(new L<>(11), -10), 0), -4), -1), -1);
    std::cout << "original list:" << l << std::endl;
    L<>* l2 = filter_negative_elements(l);
    std::cout << "filtered original list: " << l << std::endl;
    std::cout << "negative list: " << l2 << std::endl;

    std::cout << std::endl;
    L<>* l3 = new L<>(new L<>(new L<>(new L<>(new L<>(new L<>(-110), -10), 0), 7), 6), 5);
    std::cout << "original list2: " << l3 << std::endl;
    L<>* l4 = filter_negative_elements(l3);
    std::cout << "filtered original list2: " << l3 << std::endl;
    std::cout << "negative list2: " << l4 << std::endl;
    delete l;
    delete l2;
    delete l3;
    delete l4;

    std::cout << std::endl << "Create a new set..." << std::endl;
    Set<> s;
    std::cout << "The set is empty: " << s.isEmpty() << std::endl;
    s.add(3);
    s.add(3);
    s.add(3);
    s.add(4);
    s.add(5);
    s.add(3);
    std::cout << "The set: " << s << std::endl;
    std::cout << "Size of the set: " << s.Size() << std::endl;
    std::cout << "Does it contain 3? " << (s.contains(3) ? "yes" : "no") << std::endl;
    std::cout << "Does it contain 65? " << (s.contains(65) ? "yes" : "no") << std::endl;
    std::cout << "Does it contain 5? " << (s.contains(5) ? "yes" : "no") << std::endl;
    std::cout << "Pop an element: " << s.pop() << std::endl;
    std::cout << "Pop an element: " << s.pop() << std::endl;
    std::cout << "Pop an element: " << s.pop() << std::endl;
    try {
        std::cout << "Pop an element: " << s.pop() << std::endl;
    }
    catch (int e) {
        if (e == -1) {
            std::cout << "Pop failed, the set is empty..." << std::endl;
        }
    }
    std::cout << "Size of the set: " << s.Size() << std::endl;
    s.add(1);
    s.add(-1);
    s.add(1);
    s.add(2);
    s.add(0);
    s.add(-1);
    std::cout << "The set: " << s << std::endl;
    std::cout << "Create a new set..." << std::endl;
    Set<> s2(s);
    std::cout << "Reset the old set..." << std::endl;
    s.reset();
    std::cout << "The old set: " << s << std::endl;
    std::cout << "The new set: " << s2 << std::endl;
}