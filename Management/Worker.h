#pragma once
#include"Employee.h"

class Worker :public Employee
{
public:
    Worker(string id, string name, string departmentId);

    virtual void showInfo();

    virtual string returnPosition();
};