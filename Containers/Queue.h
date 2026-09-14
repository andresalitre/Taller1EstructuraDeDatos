#pragma once
#include "List.h"

template <class T>
class Queue {
private:
    List<T> datos;
public:
    bool empty() {
        return datos.isEmpty();
    }

    void push(T value) {
        datos.insertLast(value);
    }

    void pop() {
        datos.remove(0);
    }

    T front() {
        return datos.getFirst();
    }

    void clear() {
        datos.clear();
    }
};