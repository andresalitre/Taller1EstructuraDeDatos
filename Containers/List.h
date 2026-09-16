#pragma once
#include "Node.h"

template <class T>
class List {
private:
    Node<T>* start;
public:
    List() {
        this->start = nullptr;
    }

    bool isEmpty() {
        return this->start == nullptr;
    }

    void insertFirst(T value) {
        Node<T>* nuevo = new Node<T>(value);
        nuevo->setNext(this->start);
        this->start = nuevo;
    }

    void insertLast(T value) {
        if (this->start == nullptr) {
            this->start = new Node<T>(value);
            return;
        }
        Node<T>* cursor = this->start;
        while (cursor->getNext() != nullptr) {
            cursor = cursor->getNext();
        }
        cursor->setNext(new Node<T>(value));
    }

    void insert(T value, int index) {
        if (index < 0) throw 0;
        if (index == 0) {
            this->insertFirst(value);
            return;
        }
        Node<T>* cursor = this->start;
        for (int i = 0; i < index - 1; i++) {
            cursor = cursor->getNext();
            if (!cursor) throw 0;
        }
        Node<T>* nuevo = new Node<T>(value);
        nuevo->setNext(cursor->getNext());
        cursor->setNext(nuevo);
    }

    T getFirst() {
        if (this->start == nullptr) throw 0;
        return this->start->getValue();
    }

    T getLast() {
        if (this->start == nullptr) throw 0;
        Node<T>* cursor = this->start;
        while (cursor->getNext() != nullptr) {
            cursor = cursor->getNext();
        }
        return cursor->getValue();
    }

    T get(int index) {
        if (!this->start || index < 0) throw 0;
        Node<T>* cursor = this->start;
        for (int i = 0; i < index; i++) {
            cursor = cursor->getNext();
            if (!cursor) throw 0;
        }
        return cursor->getValue();
    }

    void remove(int index) {
        if (!this->start || index < 0) throw 0;
        if (index == 0) {
            Node<T>* toDel = this->start;
            this->start = toDel->getNext();
            delete toDel;
            return;
        }
        Node<T>* cursor = this->start;
        for (int i = 0; i < index - 1; i++) {
            cursor = cursor->getNext();
            if (!cursor) throw 0;
        }
        Node<T>* toDelete = cursor->getNext();
        cursor->setNext(toDelete ? toDelete->getNext() : nullptr);
        delete toDelete;
    }

    void clear() {
        while (this->start != nullptr) {
            Node<T>* temp = this->start->getNext();
            delete this->start;
            this->start = temp;
        }
    }

    int size() {
    int count = 0;
    Node<T>* cursor = this->start;
    while (cursor != nullptr) {
        count++;
        cursor = cursor->getNext();
    }
    return count;

    }

};