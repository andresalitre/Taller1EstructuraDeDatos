#pragma once

template <class T>
class Node {
private:
    T value; //Dato en el nodo
    Node<T>* next; // Puntero al siguiente nodo

public:
    Node(T value) { // Constructor: crea un nodo con el valor dado y sin siguiente
        this->value = value;
        this->next = nullptr;
    }

    T getValue() { // Devuelve el valor almacenado en el nodo
        return this->value;
    }

    Node<T>* getNext() { // Devuelve el puntero al siguiente nodo
        return this->next;
    }

    void setValue(T value) { // Modifica el valor almacenado en el nodo
        this->value = value;
    }

    void setNext(Node<T>* next) { // Enlaza este nodo con otro (o con nullptr para cortar el enlace) 
        this->next = next;
    }

    // Destructor
    ~Node() {}
};