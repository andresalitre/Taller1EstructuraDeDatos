#pragma once
#include "List.h"

template <class T>
class Stack {
private:
    List<T> datos;
public:
    bool empty() {
        return datos.isEmpty();
    }

    void push(T value) {
        datos.insertFirst(value);
    }

    void pop() {
        datos.remove(0);
    }

    T top() {
        return datos.getFirst();
    }

    void clear() {
        datos.clear();
    }
};