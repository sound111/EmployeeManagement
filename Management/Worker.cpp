#include"Worker.h"

Worker::Worker(string id, string name, string departmentId)
{
    ID = id;
    Name = name;
    DepartmentID = departmentId;
}

string Worker::returnPosition()
{
    return "普通员工";
}

void Worker::showInfo()
{
    cout << "职工编号: " << ID << "  职工姓名： " << Name << "  部门编号： " << DepartmentID << "  岗位职责： 完成经理交给的任务" << endl;
}

