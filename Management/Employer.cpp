#include"Employer.h"

Employer::Employer(string id, string name, string departmentId)
{
    ID = id;
    Name = name;
    DepartmentID = departmentId;
}

void Employer::showInfo()
{
    cout << "职工编号: " << ID << "  职工姓名： " << Name << "  部门编号： " << DepartmentID << "  岗位职责： 完成老板交给的任务，并下发任务给员工" << endl;

}

string Employer::returnPosition()
{
    return "老板";
}
