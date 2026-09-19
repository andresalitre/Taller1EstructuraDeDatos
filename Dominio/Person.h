#pragma once

#include <string>

using namespace std;

class Person { // Clase para representar a una persona
protected:
    string name;
    int age;

public:
    Person(string name, int age);

    string getName();
    int getAge();

    ~Person();
};