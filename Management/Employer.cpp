#include"Employer.h"

Employer::Employer(string id, string name, string departmentId)
{
    ID = id;
    Name = name;
    DepartmentID = departmentId;
}

void Employer::showInfo()
{
    cout << "ְ�����: " << ID << "  ְ�������� " << Name << "  ���ű�ţ� " << DepartmentID << "  ��λְ�� ����ϰ彻�������񣬲��·������Ա��" << endl;

}

string Employer::returnPosition()
{
    return "�ϰ�";
}
