#pragma once
#include "Node.h"

template <class T>
class List {
private:
    Node<T>* start;  // Primer nodo de la lista (nullptr si está vacía)

public:
    // Constructor (crea lista vacia)
    List() {
        this->start = nullptr;
    }

    bool isEmpty() { // Devuelve true si la lista no tiene nodos
        return this->start == nullptr;
    }

    void insertFirst(T value) { // Inserta un valor al inicio de la lista
        Node<T>* nuevo = new Node<T>(value);
        nuevo->setNext(this->start); // El nuevo nodo apunta al antiguo primero
        this->start = nuevo; // Ahora el nuevo es el primero
    }

    void insertLast(T value) { // Inserta un valor al final de la lista
        if (this->start == nullptr) { // Lista vacía: el nuevo nodo pasa a ser el primero
            this->start = new Node<T>(value);
            return;
        }
        Node<T>* cursor = this->start; // Recorre hasta el último nodo (el que no tiene siguiente)
        while (cursor->getNext() != nullptr) {
            cursor = cursor->getNext();
        }
        cursor->setNext(new Node<T>(value));  // Lo enlaza al final
    }

    void insert(T value, int index) { // Inserta un valor en la posición "index" (0 = inicio)
        if (index < 0) throw 0; // Lanza excepción si el índice es inválido.
        if (index == 0) {
            this->insertFirst(value);
            return;
        }
        Node<T>* cursor = this->start; // Avanza hasta el nodo anterior a la posición deseada
        for (int i = 0; i < index - 1; i++) {
            cursor = cursor->getNext();
            if (!cursor) throw 0; // Índice fuera de rango
        }
        Node<T>* nuevo = new Node<T>(value); // Enlaza el nuevo nodo entre el "cursor" y su siguiente
        nuevo->setNext(cursor->getNext());
        cursor->setNext(nuevo);
    }


    T getFirst() { // Devuelve el primer valor. Lanza excepción si la lista está vacía
        if (this->start == nullptr) throw 0;
        return this->start->getValue();
    }

    T getLast() { // Devuelve el último valor. Lanza excepción si la lista está vacía
        if (this->start == nullptr) throw 0;
        Node<T>* cursor = this->start;
        while (cursor->getNext() != nullptr) {
            cursor = cursor->getNext();
        }
        return cursor->getValue();
    }

    T get(int index) { // Devuelve el valor en la posición "index"
        if (!this->start || index < 0) throw 0; // Lanza excepción si la lista está vacía o el índice es inválido
        Node<T>* cursor = this->start;
        for (int i = 0; i < index; i++) {
            cursor = cursor->getNext();
            if (!cursor) throw 0;  // Índice fuera de rango
        }
        return cursor->getValue();
    }

    void remove(int index) { // Elimina el nodo en la posición "index" y libera su memoria
        if (!this->start || index < 0) throw 0;
        if (index == 0) { // Caso especial: eliminar el primer nodo
            Node<T>* toDel = this->start;
            this->start = toDel->getNext();  // El segundo pasa a ser el primero
            delete toDel;
            return;
        }
        Node<T>* cursor = this->start; // Avanza hasta el nodo anterior al que se quiere eliminar
        for (int i = 0; i < index - 1; i++) {
            cursor = cursor->getNext();
            if (!cursor) throw 0;
        }
        Node<T>* toDelete = cursor->getNext(); // Salta el nodo a eliminar y lo libera
        cursor->setNext(toDelete ? toDelete->getNext() : nullptr);
        delete toDelete;
    }

    void clear() { // Elimina todos los nodos y deja la lista vacía
        while (this->start != nullptr) {
            Node<T>* temp = this->start->getNext();  // Guarda el siguiente antes de borrar
            delete this->start;
            this->start = temp;
        }
    }

    int size() { // Cuenta los nodos recorriendo la lista: O(n)
        int count = 0;
        Node<T>* cursor = this->start;
        while (cursor != nullptr) {
            count++;
            cursor = cursor->getNext();
        }
        return count;
    }


};