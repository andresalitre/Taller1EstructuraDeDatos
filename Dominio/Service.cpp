#include "Service.h"

Service::Service(string name) {
    this->name = name;
}

string Service::getName() {
    return name;
}

void Service::addPatient(Patient* p) {
    patients.insertLast(p);
}

List<Patient*> Service::getPatients() {
    return patients;
}

int Service::patientsCount() {
    return patients.size();
}

Service::~Service() 
{
    for (int i = 0; i < patients.size(); i++) 
    {
        delete patients.get(i);
    }
    patients.clear();
}