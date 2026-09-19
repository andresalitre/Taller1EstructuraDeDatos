#include "Attention.h"

// Constructor
Attention::Attention(string name, int edad, string departamento) {
    this->name = name;
    this->edad = edad;
    this->departamento = departamento;
}

// Getters
string Attention::getName() {
    return name;
}

int Attention::getAge() {
    return edad;
}

string Attention::getDepartamento() {
    return departamento;
}

// Destructor
Attention::~Attention() {}