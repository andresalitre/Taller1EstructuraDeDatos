#pragma once

#include <string>
#include "Patient.h"
#include "../containers/list.h" // Usar la clase List para almacenar los pacientes atendidos en el servicio

using namespace std;

class Service // Clase para representar un servicio del hospital
{
    private:
        string name;
        List<Patient*> patients; // Lista de pacientes atendidos en el servicio

    public:
        Service(string name);

        string getName();
        void addPatient(Patient* p);
        List<Patient*> getPatients();
        int patientsCount();

        ~Service();
};