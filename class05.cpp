#include <iostream>
#include "lstack.h"

void reverse2(L<>*& l) {
    if (l != nullptr) {
        Stack<L<>*> stack;
        for (L<> *s = l; s != nullptr; s = s->getNext()) {
            stack.insert(s);
        }
        L<>* q = stack.pop();
        l = q;
        L<>* p;
        while (stack.Size() > 0) {
            p = stack.pop();
            q->setNext(p);
            q = p;
        }
        q->setNext(nullptr);
    }
}

void demonstrate_class05() {
    std::cout << "####################################" << std::endl;
    std::cout << "######Demonstrate Class05###########" << std::endl;
    std::cout << "####################################" << std::endl;
    std::cout << "Create stack..." << std::endl;
    Stack<> s;
    s.insert(1);
    s.insert(2);
    s.insert(-1);
    std::cout << "Size of the stack: " << s.Size() << std::endl;
    std::cout << "The top element: " << s.top() << std::endl;
    std::cout << "Pop out an element: " << s.pop() << std::endl;
    std::cout << "Size of the stack: " << s.Size() << std::endl;
    std::cout << "Pop out an element: " << s.pop() << std::endl;
    std::cout << "Size of the stack: " << s.Size() << std::endl;
    std::cout << "Pop out an element: " << s.pop() << std::endl;
    std::cout << "Size of the stack: " << s.Size() << std::endl;
    try {
        std::cout << "Pop out an element: " << s.pop() << std::endl;
    }
    catch (int e) {
        if (e == -1) {
            std::cout << "The pop operation failed for the empty stack..." << std::endl;
            std::cout << "Size of the stack: " << s.Size() << std::endl;
        }
    }

    std::cout << std::endl << "Create a list..." << std::endl;
    L<>* l = new L<>(new L<>(new L<>(new L<>(new L<>(new L<>(11), 3), 2), 1), 0), -1);
    std::cout << "List created: " << l << std::endl;
    reverse2(l);
    std::cout << "Reverse list created: " << l << std::endl;
}