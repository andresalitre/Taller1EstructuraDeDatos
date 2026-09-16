#pragma once

#include <string>
#include "Patient.h"
#include "../containers/list.h"

using namespace std;

class Service 
{
    private:
        string name;
        List<Patient*> patients;     

    public:
        Service(string name);

        string getName();
        void addPatient(Patient* p);
        List<Patient*> getPatients();
        int patientsCount();

        ~Service();
};