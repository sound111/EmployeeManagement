#include"Manager.h"

Manager::Manager(string id, string name, string departmentId)
{
    ID = id;
    Name = name;
    DepartmentID = departmentId;
}

void Manager::showInfo()
{
    cout << "职工编号: " << ID << "  职工姓名： " << Name << "  部门编号： " << DepartmentID << "  岗位职责： 完成老板交给的任务，并下发任务给员工" << endl;

}

string Manager::returnPosition()
{
    return "经理";
}