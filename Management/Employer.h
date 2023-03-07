#pragma once
#include"employee.h"

class Employer :public Employee
{
public:
    virtual void showInfo();

    virtual string returnPosition();

    Employer(string id, string name, string departmentId);
};