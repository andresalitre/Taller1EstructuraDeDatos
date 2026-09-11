#include "Patient.h"

Patient::Patient(string id, string name, int age, string service) {
    this->id = id;
    this->name = name;
    this->age = age;
    this->service = service;
}

string Patient::getId() {
    return id;
}

string Patient::getName() {
    return name;
}

int Patient::getAge() {
    return age;
}

string Patient::getService() {
    return service;
}