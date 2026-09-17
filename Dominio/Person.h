#pragma once

#include <string>

using namespace std;

class Person {
protected:
    string id;
    string name;
    int age;

public:
    Person(string id, string name, int age);

    string getId();
    string getName();
    int getAge();

    ~Person();
};