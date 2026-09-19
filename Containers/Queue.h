#pragma once
#include "List.h"

template <class T>
class Queue {
private:
    List<T> datos;
public:
    bool empty() { // Retorna True o False dependiendo si la cola tiene datos almacenados
        return datos.isEmpty();
    }

    void push(T value) { // Coloca el dato al final de la cola
        datos.insertLast(value);
    }

    void pop() { // Remueve el dato de la primera posición de la cola
        datos.remove(0);
    }

    T front() { // Retorna el dato de la primera posición de la cola
        return datos.getFirst();
    }

    void clear() { // Limpiar la cola
        datos.clear();
    }

    int size() { // Devuelve el tamaño de la cola
        return datos.size();
    }
};