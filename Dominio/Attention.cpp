#include "Attention.h"

Attention::Attention() {
    this->name = "";
    this->edad = 0;
    this->departamento = "";
}

Attention::Attention(string name, int edad, string departamento) {
    this->name = name;
    this->edad = edad;
    this->departamento = departamento;
}

string Attention::getName() {
    return name;
}

int Attention::getAge() {
    return edad;
}

string Attention::getDepartamento() {
    return departamento;
}

Attention::~Attention() {}