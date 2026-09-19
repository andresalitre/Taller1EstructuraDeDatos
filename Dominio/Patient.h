#pragma once

#include <string>
#include "Person.h"

using namespace std;

class Patient : public Person { // Clase para representar a un paciente, hereda de Person
private:
    string id;
    string service;

public:
    Patient(string id, string name, int age, string service);

    string getService();
    string getId();

    ~Patient();
};