#ifndef UNTITLED_LLIST_H
#define UNTITLED_LLIST_H

template <typename T = int>
class L {
public:
    // constructors
    L() : data(T(0)), next(nullptr) { }
    explicit L(T pdata) : data(pdata), next(nullptr) { }
    L(L* l, T pdata) : data(pdata), next(l) { }
    ~L() { if (next != nullptr) delete next; }

    // getters, setters
    T getData() const {
        return data;
    }

    L *getNext() const {
        return next;
    }

    void setData(T pdata) {
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
    T data;
    L* next;
};

#endif //UNTITLED_LLIST_H
