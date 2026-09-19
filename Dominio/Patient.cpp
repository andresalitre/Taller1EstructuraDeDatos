#include "Patient.h"

Patient::Patient(string id, string name, int age, string service) : Person(name, age) { // Constructor
    this->id = id;
    this->service = service;
}

// Getters
string Patient::getService() {
    return service;
}

string Patient::getId() {
    return id;
}

// Destructor
Patient::~Patient() {}