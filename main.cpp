// Taller 1 estructura de datos | Integrante: Andrés Rojas Tejada | 22.065.446-k 

#include <iostream>
#include <string>
#include <fstream>
#include "Logica/PatientFactory.h"

using namespace std;

bool leerArchivo(string nombre) {
    ifstream Archivo(nombre);
    string linea;
    while (getline(Archivo, linea)) {
        Patient paciente = PatientFactory::create(linea);
        cout << "Creado: " << paciente.getId() << " - " << paciente.getName() << endl;
    }
    return true;
}

int main() {
    leerArchivo("pacientes.txt");
}