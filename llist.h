#ifndef UNTITLED_LLIST_H
#define UNTITLED_LLIST_H

class L {
public:
    // constructors
    L() : data(0), next(nullptr) { }
    explicit L(int pdata) : data(pdata), next(nullptr) { }
    L(L* l, int pdata) : data(pdata), next(l) { }

    // getters, setters
    int getData() const {
        return data;
    }

    L *getNext() const {
        return next;
    }

    void setData(int pdata) {
        data = pdata;
    }

    void setNext(L *pnext) {
        next = pnext;
    }

private:
    int data;
    L* next;
};

#endif //UNTITLED_LLIST_H
