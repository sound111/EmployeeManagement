#pragma once
#include"employee.h"

class Manager :public Employee
{
public:
    virtual void showInfo();

    virtual string returnPosition();

    Manager(string id, string name, string departmentId);
};