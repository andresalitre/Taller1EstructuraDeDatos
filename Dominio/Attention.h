#pragma once

#include <string>

using namespace std;


class Attention 
{

private:
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