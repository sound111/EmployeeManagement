#include"Worker.h"

Worker::Worker(string id, string name, string departmentId)
{
    ID = id;
    Name = name;
    DepartmentID = departmentId;
}

string Worker::returnPosition()
{
    return "��ͨԱ��";
}

void Worker::showInfo()
{
    cout << "ְ�����: " << ID << "  ְ�������� " << Name << "  ���ű�ţ� " << DepartmentID << "  ��λְ�� ��ɾ�����������" << endl;
}

