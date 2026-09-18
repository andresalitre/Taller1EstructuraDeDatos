#pragma once

#include <string>

using namespace std;

class Person {
protected:
    string name;
    int age;

public:
    Person(string name, int age);

    string getName();
    int getAge();

    ~Person();
};