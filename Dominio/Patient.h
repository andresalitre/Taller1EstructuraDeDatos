#pragma once

#include <string>

using namespace std;

// constructor
class Patient {
private:
    string id;
    string name;
    int age;
    string service;

// metodos (getters)
public:
    Patient(string id, string name, int age, string service);

    string getId();
    string getName();
    int getAge();
    string getService();
    
};