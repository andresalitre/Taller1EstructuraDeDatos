// Taller 1 estructura de datos | Integrante: Andrés Rojas Tejada | 22.065.446-k 

#include <iostream> // Usar cout y cin
#include <string> // Usar strings
#include <fstream> // Usar archivos
#include "Logica/PatientFactory.h" // Usar la clase PatientFactory para crear pacientes a partir de un archivo
#include "Containers/Queue.h" // Usar la clase Queue para almacenar los pacientes en espera
#include "Dominio/Service.h" // Usar la clase Service para almacenar los servicios del hospital
#include <cctype> // Usar la funcion toupper para convertir a mayusculas
#include "Containers/Stack.h" // Usar la clase Stack para almacenar el historial de pacientes atendidos
#include "Dominio/Attention.h" // Usar la clase Attention para almacenar la informacion de los pacientes atendidos

using namespace std; // Evitar usar std::

Queue<Patient*> pacientes; // Cola de pacientes en espera
List<Service*> servicios; // Lista de servicios del hospital
Stack<Attention*> historialPacientes; // Pila para almacenar el historial de pacientes atendidos

string upper(string texto) { // Funcion para convertir a mayusculas
    string resultado = texto;
    char* cursor = &resultado[0]; // Obtener un puntero al primer caracter de la cadena
    char* fin = cursor + resultado.length(); // Calcular la dirección del ultimo carácter de la cadena

    while (cursor < fin) { // Recorrer la cadena hasta el final
        *cursor = toupper(*cursor); // Convertir el caracter actual a mayuscula
        cursor++; // Avanzar al siguiente caracter
    }

    return resultado; // Devolver la cadena convertida a mayusculas
}

bool pacienteDuplicado(string id) // Funcion para verificar si un paciente ya existe en la cola de espera
{
    Queue<Patient*> temp; // Cola temporal para almacenar los pacientes mientras se busca el duplicado
    bool encontrado = false; //Flag para indicar si ya encontamos al paciente duplicado

    while (!pacientes.empty()) // Mientras haya pacientes en la cola de espera
    {
        Patient* p = pacientes.front(); // Obtener el paciente al frente de la cola
        pacientes.pop(); // Sacar el paciente de la cola

        if (p->getId() == id) // Si el id del paciente coincide con el id que estamos buscando
        {
            encontrado = true; // Marcar que encontramos un paciente duplicado
        }

        temp.push(p); // Agregar el paciente a la cola temporal
    }

    while (!temp.empty()) // Restaurar los pacientes a la cola de espera original
    {
        pacientes.push(temp.front());
        temp.pop();
    }

    return encontrado; // Devolver true si se encontro un paciente duplicado, false en caso contrario
}

bool servicioValido(string servicio)  // Funcion para verificar si un servicio es valido
{
    for (int i = 0; i < servicios.size(); i++) // Recorrer la lista de servicios del hospital
    {
        if (servicios.get(i)->getName() == servicio) // Si el nombre del servicio coincide con el servicio que estamos buscando
        {
            return true; // Devolver true si el servicio es valido
        }
    }
    return false;// Devolver false si el servicio no es valido
}

bool leerArchivo(string nombre) // Funcion para leer el archivo de pacientes
{
    ifstream Archivo(nombre); // Abrir el archivo de pacientes

    if (!Archivo.is_open()) // Si no se pudo abrir el archivo, devolver false
    {
        return false;
    }

    string linea; // Variable para almacenar cada linea del archivo
    while (getline(Archivo, linea))  // Leer cada linea del archivo
    {
        Patient* p = new Patient(PatientFactory::create(linea)); // Crear un nuevo paciente a partir de la linea leida del archivo

        if (!servicioValido(p->getService())) // Si el servicio del paciente no es valido, mostrar un mensaje de error y continuar con la siguiente linea
        {
            cout << "Linea invalida (servicio no reconocido): " << linea << endl;
            delete p;
            continue;
        }

        if (pacienteDuplicado(p->getId())) // Si el paciente ya existe en la cola de espera, mostrar un mensaje de error y continuar con la siguiente linea
        {
            cout << "Linea invalida (paciente duplicado): " << linea << endl;
            delete p;
            continue;
        }

        pacientes.push(p);// Agregar el paciente a la cola de espera
    }

    return true;
}

List<Service*> crearServicios() // Funcion para crear la lista de servicios del hospital
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

bool comprobarRango(int numero) // Funcion para comprobar si el numero de pacientes a atender esta dentro del rango de pacientes en espera
{
    if (numero > 0 && numero <= pacientes.size()) 
    {
        return true;
    }
    return false;
}

void atender() // Funcion para atender a los pacientes en espera
{
    string cantidad;
    cout << "Indique la cantidad de pacientes a atender: ";
    cin >> cantidad;
    int numeroAtender = stoi(cantidad);
    if (comprobarRango(numeroAtender)) // Comprobar si el numero de pacientes a atender esta dentro del rango de pacientes en espera
    {
        cout << "\n=== ATENDIENDO PACIENTES ===" << endl;
        for (int i = 0; i < numeroAtender; i++) // Ciclo for para la cantidad de pacientes a atender
        {
            for (int j = 0; j < servicios.size(); j++) // Ciclo for para recorrer la lista de servicios del hospital
            {
                Service* s = servicios.get(j); // Obtener el servicio actual de la lista de servicios del hospital
                Patient* p = pacientes.front(); // Obtener el paciente al frente de la cola de espera
                if (p->getService() == s->getName())  // Si el servicio del paciente coincide con el servicio actual de la lista de servicios del hospital
                {
                    s->addPatient(p); // Agregar el paciente al servicio correspondiente
                    pacientes.pop(); // Sacar el paciente de la cola de espera

                    historialPacientes.push(new Attention(p->getName(), p->getAge(), s->getName())); // Agregar el paciente al historial de pacientes atendidos

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

void espera() // Funcion para mostrar la lista de pacientes en espera y atenderlos
{   
    Queue<Patient*> temp; // Cola temporal para almacenar los pacientes mientras se muestran en pantalla

    cout << "\n=== PACIENTES EN ESPERA ===\n";
    int i = 1;
    while (!pacientes.empty()) // Mientras haya pacientes en la cola de espera
    {
        Patient* p = pacientes.front(); // Obtener el paciente al frente de la cola de espera
        pacientes.pop(); // Sacar el paciente de la cola de espera

        cout << i << ". " << p->getId() << " - " << p->getName() << endl; // Mostrar el paciente en pantalla
        i++;

        temp.push(p);
    }
    while (!temp.empty()) // Restaurar los pacientes a la cola de espera original
    {
        pacientes.push(temp.front());
        temp.pop(); 
    }
    cout << endl;
    atender(); // Llamar a la funcion atender para atender a los pacientes en espera
}

void departamentos() // Funcion para mostrar la lista de departamentos y los pacientes atendidos en cada uno
{   
    string opcion;
    cout << "\n=== DEPARTAMENTOS/SERVICIOS ===\n1. Urgencias\n2. Medicina General\n3. Cardiologia\n4. Neurologia\n5. Traumatologia\n6. Cirugia\n7. Pediatria\n8. Hospitalizacion";
    cout << "\n\nSeleccionar opcion: ";
    cin >> opcion; cout << endl;

    cout << "=== ESTADO "<< upper(servicios.get(stoi(opcion)-1)->getName()) <<" ===" <<endl;
    cout << "Pacientes en el departamento de " << servicios.get(stoi(opcion)-1)->getName() << ": " << servicios.get(stoi(opcion)-1)->patientsCount() << endl;

    for (int i = 0; i < servicios.get(stoi(opcion) -1)->patientsCount(); i++) // Ciclo for para recorrer la lista de pacientes atendidos en el departamento seleccionado
    {
        Patient* p = servicios.get(stoi(opcion)-1)->getPatients().get(i); // Obtener el paciente atendido en el departamento seleccionado
        cout << p->getName() << "(" << p->getAge() << ")" << endl; // Mostrar el paciente atendido
    }
    cout << endl;
}

void historial() // Funcion para mostrar el historial de pacientes atendidos
{
    cout << "\n\n=== HISTORIAL DE ÚLTIMAS ATENCIONES DEL HOSPITAL ===\n" << endl;

    if (historialPacientes.empty()) // Si no hay pacientes atendidos, mostrar un mensaje de error
    {
        cout << "No hay atenciones registradas todavia.\n" << endl;
        return; // Retornar si no hay pacientes atendidos
    }

    Stack<Attention*> temp; // Pila temporal para almacenar los pacientes mientras se muestran en pantalla

    while (!historialPacientes.empty()) // Mientras haya pacientes en la pila de historial de pacientes atendidos
    {
        Attention* a = historialPacientes.top(); // Obtener el paciente al tope de la pila de historial de pacientes atendidos
        historialPacientes.pop(); // Sacar el paciente de la pila de historial de pacientes atendidos
        cout << "Nombre: " << a->getName() << " | Edad: " << a->getAge() << " | Departamento: " << a->getDepartamento() << endl;
        temp.push(a); // Agregar el paciente a la pila temporal
    }

    while (!temp.empty()) // Restaurar los pacientes a la pila de historial de pacientes atendidos original
    {
        historialPacientes.push(temp.top());
        temp.pop();
    }

    cout << endl;
}

void menu() // Funcion para mostrar el menu principal del hospital
    {
    string opcion = "0";
    do {
            cout << "=== HOSPITAL MARMAJA ===\n1. Atender pacientes\n2. Ver departamento\n3. Revisar historial de atencion\n4. Salir\n\nSeleccionar opcion: ";
            cin >> opcion;

            if (opcion == "1") // Opcion para atender pacientes
            {
                if (pacientes.empty()) 
                {
                    cout << "No hay pacientes en espera.\n";
                    break;
                } 
                espera();
            }

            if (opcion == "2") // Opcion para ver los departamentos y los pacientes atendidos en cada uno
            {
                departamentos();
            }

            if (opcion == "3") // Opcion para revisar el historial de atencion
            {
                historial();
            }

            if (opcion == "4") // Opcion para salir del programa
            {   
                while (!pacientes.empty()) // Mientras haya pacientes en la cola de espera
                {
                    delete pacientes.front(); // Liberar la memoria del paciente al frente de la cola de espera
                    pacientes.pop(); // Sacar el paciente de la cola de espera
                }

                for (int i = 0; i < servicios.size(); i++) // Ciclo for para recorrer la lista de servicios del hospital
                {
                    delete servicios.get(i); // Liberar la memoria del servicio
                }
                servicios.clear(); // Limpiar la lista de servicios del hospital

                while (!historialPacientes.empty())  // Mientras haya pacientes en la pila de historial de pacientes atendidos
                {
                    delete historialPacientes.top(); // Liberar la memoria del paciente al tope de la pila de historial de pacientes atendidos
                    historialPacientes.pop(); // Sacar el paciente de la pila de historial de pacientes atendidos
                }

                cout << endl << "Hasta luego :D.\n";
            }

        } while (opcion != "4");
    }

int main() 
{   
    servicios = crearServicios(); // Crear la lista de servicios del hospital

    if (!leerArchivo("pacientes.txt")) // Si no se pudo leer el archivo de pacientes, mostrar un mensaje de error y salir del programa
    {
        cout << "Error: no se pudo abrir el archivo de pacientes.\n";
        return 1;
    }

    menu(); // Llamar a la funcion menu para mostrar el menu principal del hospital
}
