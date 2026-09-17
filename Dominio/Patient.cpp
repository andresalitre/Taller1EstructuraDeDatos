#include "Patient.h"

Patient::Patient(string id, string name, int age, string service) : Person(id, name, age) {
    this->service = service;
}

string Patient::getService() {
    return service;
}

Patient::~Patient() {}