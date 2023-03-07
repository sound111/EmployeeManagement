#pragma once
#include<iostream>
#include<string>
#include<fstream>
#include"Employee.h"
#include"Employer.h"
#include"Worker.h"
#include"Manager.h"
#define FILENAME "employeeInfo.txt"
using namespace std;


class workerManager
{
public:
    workerManager();

    void showManu();

    void exitManagement();

    void add();

    void save();

    void show();

    void deleteEmployee();

    void initArray();

    int employeeIsExist(string id);

    void change();

    void find();

    void orderByID();

    void remove();

    ~workerManager();

    int Num;

    int getNum();

    Employee** Array;

    bool FileIsEmpty;
};
