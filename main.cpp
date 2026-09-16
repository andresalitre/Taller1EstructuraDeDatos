// Taller 1 estructura de datos | Integrante: Andrés Rojas Tejada | 22.065.446-k 

#include <iostream>
#include <string>
#include <fstream>
#include "Logica/PatientFactory.h"
#include "Containers/Queue.h"
#include "Dominio/Service.h"
#include <cctype>
#include "Containers/Stack.h"
#include "Dominio/Attention.h"

using namespace std;

Queue<Patient*> pacientes;
List<Service*> servicios;
Stack<Attention*> historialPacientes;

string upper(string texto) {
    string resultado = texto;
    for (int i = 0; i < resultado.length(); i++) {
        resultado[i] = toupper(resultado[i]);
    }
    return resultado;
}

bool leerArchivo(string nombre) 
{
    ifstream Archivo(nombre);
    string linea;

    while (getline(Archivo, linea)) 
    {
        Patient* p = new Patient(PatientFactory::create(linea));
        pacientes.push(p);
    }

    return true;
}

List<Service*> crearServicios() 
{
    List<Service*> temp;    

    temp.insertLast(new Service("Urgencias"));
    temp.insertLast(new Service("Medicina General"));
    temp.insertLast(new Service("Cardiologia"));
    temp.insertLast(new Service("Neurologia"));
    temp.insertLast(new Service("Traumatologia"));
    temp.insertLast(new Service("Cirugia"));
    temp.insertLast(new Service("Pediatria"));
    temp.insertLast(new Service("Hospitalizacion"));

    return temp;
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
        cout << "\n=== ATENDIENDO PACIENTES ===" << endl;
        for (int i = 0; i < numeroAtender; i++) 
        {
            for (int j = 0; j < servicios.size(); j++) 
            {
                Service* s = servicios.get(j);
                Patient* p = pacientes.front();
                if (p->getService() == s->getName()) 
                {
                    s->addPatient(p);
                    pacientes.pop();

                    historialPacientes.push(new Attention(p->getName(), p->getAge(), s->getName()));

                    cout << "ID: " << p->getId() << "\nNombre: " << p->getName() << "\nEdad: " << p->getAge() << "\nServicio: " << s->getName() << "\n" << endl;
                    cout << "Paciente enviado a " << s->getName() << ".\n" << endl;
                    break;
                }
            }
        }
    }
    else 
    {
        cout << "\nCantidad de pacientes a atender fuera de rango.\n\n";
    }
}

void espera()
{   
    Queue<Patient*> temp;

    cout << "\n=== PACIENTES EN ESPERA ===\n";
    int i = 1;
    while (!pacientes.empty())
    {
        Patient* p = pacientes.front();
        pacientes.pop();

        cout << i << ". " << p->getId() << " - " << p->getName() << endl;
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
    string opcion;
    cout << "\n=== DEPARTAMENTOS/SERVICIOS ===\n1. Urgencias\n2. Medicina General\n3. Cardiologia\n4. Neurologia\n5. Traumatologia\n6. Cirugia\n7. Pediatria\n8. Hospitalizacion";
    cout << "\n\nSeleccionar opcion: ";
    cin >> opcion; cout << endl;

    cout << "=== ESTADO "<< upper(servicios.get(stoi(opcion)-1)->getName()) <<" ===" <<endl;
    cout << "Pacientes en el departamento de " << servicios.get(stoi(opcion)-1)->getName() << ": " << servicios.get(stoi(opcion)-1)->patientsCount() << endl;

    for (int i = 0; i < servicios.get(stoi(opcion) -1)->patientsCount(); i++) 
    {
        Patient* p = servicios.get(stoi(opcion)-1)->getPatients().get(i);
        cout << p->getName() << "(" << p->getAge() << ")" << endl;
    }
    cout << endl;
}

void historial() 
{
    cout << "\n\n=== HISTORIAL DE ÚLTIMAS ATENCIONES DEL HOSPITAL ===\n" << endl;

    if (historialPacientes.empty())
    {
        cout << "No hay atenciones registradas todavia.\n" << endl;
        return;
    }

    Stack<Attention*> temp;

    while (!historialPacientes.empty())
    {
        Attention* a = historialPacientes.top();
        historialPacientes.pop();
        cout << "Nombre: " << a->getName() << " | Edad: " << a->getAge() << " | Departamento: " << a->getDepartamento() << endl;
        temp.push(a);
    }

    while (!temp.empty())
    {
        historialPacientes.push(temp.top());
        temp.pop();
    }

    cout << endl;
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

            if (opcion == "3")
            {
                historial();
            }

            if (opcion == "4") 
            {   
                pacientes.clear();
                servicios.clear();
                historialPacientes.clear();
                cout << endl << "Hasta luego :D.\n";
            }

        } while (opcion != "4");
    }

int main() 
{   
    servicios = crearServicios();
    leerArchivo("pacientes.txt");
    menu();
}

