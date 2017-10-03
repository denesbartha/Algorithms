#include <iostream>
#include "llist.h"


void print_list(L* l) {
    for (; l != nullptr; l = l->getNext()) {
        std::cout << l->getData() << " ";
    }
    std::cout << std::endl;
}


void reverse(L*& l) {
    if (l != nullptr) {
        L* s = l;
        L* t = l->getNext();
        s->setNext(nullptr);
        while (t != nullptr) {
            L* p = t->getNext();
            t->setNext(s);
            s = t, t = p;
        }
        l = s;
    }
}


void remove_duplicates(L* l) {
    if (l != nullptr) {
        L* s = l;
        L* t = l->getNext();
        while (t != nullptr) {
            if (s->getData() == t->getData()) {
                L* p = t->getNext();
                t->setNext(nullptr);
                delete t;
                t = p;
            }
            else {
                s->setNext(t);
                s = t, t = t->getNext();
            }
        }
        s->setNext(nullptr);
    }
}


void demonstrate_class03() {
    L* l = new L(new L(new L(new L(new L(new L(5), 5), 5), 3), 1), 1);
    std::cout << "original order:" << std::endl;
    print_list(l);
    std::cout << "reversed order:" << std::endl;
    reverse(l);
    print_list(l);
    std::cout << "remove duplicates:" << std::endl;
    remove_duplicates(l);
    print_list(l);
    std::cout << "try to remove duplicates again:" << std::endl;
    remove_duplicates(l);
    print_list(l);
    std::cout << "reverse the list again:" << std::endl;
    reverse(l);
    print_list(l);

    delete l;
}
