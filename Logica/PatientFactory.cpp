#include "PatientFactory.h"
#include <sstream>

Patient PatientFactory::create(string line) {
    stringstream ss(line);
    string id, name, ageStr, service;

    getline(ss, id, ';');
    getline(ss, name, ';');
    getline(ss, ageStr, ';');
    getline(ss, service, ';');

    int age = stoi(ageStr);

    return Patient(id, name, age, service);
}