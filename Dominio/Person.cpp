#include "Person.h"

Person::Person(string id, string name, int age) {
    this->id = id;
    this->name = name;
    this->age = age;
}

string Person::getId() {
    return id;
}

string Person::getName() {
    return name;
}

int Person::getAge() {
    return age;
}

Person::~Person() {}