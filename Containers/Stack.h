#pragma once
#include "List.h"

template <class T>
class Stack {
private:
    List<T> datos;
public:
    bool empty() { // Retorna True o False dependiendo si hay datos en la pila
        return datos.isEmpty();
    }

    void push(T value) { // Inserta un dato en la primera posición de la pila
        datos.insertFirst(value);
    }

    void pop() { // Remueve el dato de la primera posición de la pila
        datos.remove(0);
    }

    T top() { // Retorna el dato de la primera posición de la pila
        return datos.getFirst();
    }

    void clear() { // Elimina todos los datos de la pila
        datos.clear();
    }
};