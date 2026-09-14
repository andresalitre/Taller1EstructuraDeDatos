#pragma once

#include <string>
#include "../Dominio/Patient.h"

using namespace std;

class PatientFactory {
public:
    static Patient create(string line);
};

