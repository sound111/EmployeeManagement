#pragma once
#include<iostream>
#include<string>
using namespace std;

class Employee
{
public:
    string ID;
    string Name;
    string DepartmentID;

    virtual void showInfo()=0;

    virtual string returnPosition()=0;
};
