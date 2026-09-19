#pragma once

#include <string>

using namespace std;


class Attention 
{

private: // Atributos para almacenar la informacion de los pacientes atendidos
    string name;
    int edad;
    string departamento;

    public:
        Attention(string name, int edad, string departamento);

        string getName();
        int getAge();  
        string getDepartamento();

        ~Attention();

};