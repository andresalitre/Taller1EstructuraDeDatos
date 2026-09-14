// Taller 1 estructura de datos | Integrante: Andrés Rojas Tejada | 22.065.446-k 

#include <iostream>
#include <string>
#include <fstream>
#include "Logica/PatientFactory.h"
#include "Estructura/List.h"

using namespace std;

List<Patient> pacientes;

bool leerArchivo(string nombre) {
    ifstream Archivo(nombre);
    string linea;

    while (getline(Archivo, linea)) {
        Patient p = PatientFactory::create(linea);
        pacientes.insertLast(p);
    }

    return true;
}

int main() {
    leerArchivo("pacientes.txt");

    cout << pacientes.getFirst().getName() << endl;
    cout << pacientes.getLast().getName() << endl;
}

