#include "Patient.h"

Patient::Patient(string id, string name, int age, string service) : Person(name, age) {
    this->id = id;
    this->service = service;
}

string Patient::getService() {
    return service;
}

string Patient::getId() {
    return id;
}


Patient::~Patient() {}