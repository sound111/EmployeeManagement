#include"Manager.h"

Manager::Manager(string id, string name, string departmentId)
{
    ID = id;
    Name = name;
    DepartmentID = departmentId;
}

void Manager::showInfo()
{
    cout << "ְ�����: " << ID << "  ְ�������� " << Name << "  ���ű�ţ� " << DepartmentID << "  ��λְ�� ����ϰ彻�������񣬲��·������Ա��" << endl;

}

string Manager::returnPosition()
{
    return "����";
}