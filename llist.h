#ifndef UNTITLED_LLIST_H
#define UNTITLED_LLIST_H

class L {
public:
    // constructors
    L() : data(0), next(nullptr) { }
    explicit L(int pdata) : data(pdata), next(nullptr) { }
    L(L* l, int pdata) : data(pdata), next(l) { }
    ~L() { if (next != nullptr) delete next; }

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

    /*
     * prints out the list from the current element
     */
    friend std::ostream& operator<<(std::ostream& o, L* l) {
        for (; l != nullptr; l = l->getNext()) {
            o << l->getData() << " ";
        }
        return o;
    }

private:
    int data;
    L* next;
};

#endif //UNTITLED_LLIST_H
