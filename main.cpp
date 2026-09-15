// Taller 1 estructura de datos | Integrante: Andrés Rojas Tejada | 22.065.446-k 

#include <iostream>
#include <string>
#include <fstream>
#include "Logica/PatientFactory.h"
#include "Containers/Queue.h"

using namespace std;

Queue<Patient> pacientes;

bool leerArchivo(string nombre) 
{
    ifstream Archivo(nombre);
    string linea;

    while (getline(Archivo, linea)) 
    {
        Patient p = PatientFactory::create(linea);
        pacientes.push(p);
    }

    return true;
}

bool comprobarRango(int numero) 
{
    if (numero > 0 && numero <= pacientes.size()) 
    {
        return true;
    }
    return false;
}

void atender() 
{
    string cantidad;
    cout << "Indique la cantidad de pacientes a atender: ";
    cin >> cantidad;
    int numeroAtender = stoi(cantidad);
    if (comprobarRango(numeroAtender)) 
    {
        for (int i = 0; i < numeroAtender; i++) 
        {
            
        }
    }
    else 
    {
        cout << "\nCantidad de pacientes a atender fuera de rango.\n\n";
    }

}

void espera()
{   
    Queue<Patient> temp;

    cout << "\n=== PACIENTES EN ESPERA ===\n";
    int i = 1;
    while (!pacientes.empty())
    {
        Patient p = pacientes.front();
        pacientes.pop();

        cout << i << ". " << p.getId() << " - " << p.getName() << endl;
        i++;

        temp.push(p);
    }
    while (!temp.empty())
    {
        pacientes.push(temp.front());
        temp.pop();
    }
    cout << endl;
    atender();
}

void departamentos() 
{
    cout << "\n=== DEPARTAMENTOS/SERVICIOS ===\n" << endl;
    cout << "=== DEPARTAMENTOS/SERVICIOS ===\n1. Urgencias\n2. Medicina General\n3. Cardiologia\n4. Neurologia\n5. Traumatologia\n6. Cirugia\n7. Pediatria\n8. Hospitalizacion";
    cout << "\n\nSeleccionar opcion: ";

}

void menu() 
    {
    string opcion = "0";
    do {
            cout << "=== HOSPITAL MARMAJA ===\n1. Atender pacientes\n2. Ver departamento\n3. Revisar historial de atencion\n4. Salir\n\nSeleccionar opcion: ";
            cin >> opcion;

            if (opcion == "1")
            {
                if (pacientes.empty()) 
                {
                    cout << "No hay pacientes en espera.\n";
                    break;
                } 
                espera();
            }

            if (opcion == "2") 
            {
                departamentos();
            }


            if (opcion == "4") 
            {
                cout << endl << "Saliendo del programa...\n";
            }

        } while (opcion != "4");
    }


int main() 
{
    leerArchivo("pacientes.txt");
    menu();
}

