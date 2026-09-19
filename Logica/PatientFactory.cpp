#include "PatientFactory.h"
#include <sstream> // Usar stringstream para separar los datos del paciente en la linea de texto

Patient PatientFactory::create(string line) { // Funcion para crear un paciente a partir de una linea de texto
    stringstream ss(line);
    string id, name, ageStr, service; // Variables para almacenar los datos del paciente

    getline(ss, id, ';');
    getline(ss, name, ';');
    getline(ss, ageStr, ';');
    getline(ss, service, ';');

    int age = stoi(ageStr); // Convertir la edad de string a int

    return Patient(id, name, age, service); // Retornar un objeto Patient
}