// Taller 1 estructura de datos | Integrante: Andrés Rojas Tejada | 22.065.446-k 

#include <iostream>
#include <string>
#include <fstream>
#include "Logica/PatientFactory.h"
#include "Containers/List.h"

using namespace std;

List<Patient> pacientes;

bool leerArchivo(string nombre) 
{
    ifstream Archivo(nombre);
    string linea;

    while (getline(Archivo, linea)) 
    {
        Patient p = PatientFactory::create(linea);
        pacientes.insertLast(p);
    }

    return true;
}

void menu() 
    {
    string opcion = "0";
    do {
            cout << "=== HOSPITAL MARMAJA ===\n1. Atender pacientes\n2. Ver departamento\n3. Revisar historial de atencion\n4. Salir\n\nSeleccionar opcion: ";
            cin >> opcion;


            if (opcion == "4") {
                cout << endl << "Saliendo del programa...\n";
            }

        } while (opcion != "4");
    }


int main() 
{
    leerArchivo("pacientes.txt");
    menu();
}

