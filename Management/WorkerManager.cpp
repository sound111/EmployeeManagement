#include"WorkerManager.h"

workerManager::workerManager()
{
    ifstream ifs;
    ifs.open(FILENAME, ios::in);

    if (!ifs.is_open())
    {
        cout << "�ļ�������" << endl;
        this->Num = 0;
        this->Array = NULL;
        this->FileIsEmpty = true;
        ifs.close();
        return;
    }
    
    char ch;
    ifs >> ch;
    if (ifs.eof())
    {
        cout << "�ļ�Ϊ��" << endl;
        this->Num = 0;
        this->Array = NULL;
        this->FileIsEmpty = true;
        ifs.close();
        return;
    }

    int num = this->getNum();
    //cout << "ְ������Ϊ��" << num << endl;
    this->Num = num;

    this->Array = new Employee * [this->Num];
    initArray();
}

int workerManager:: employeeIsExist(string id)
{
    int index = -1;

    for (int i = 0; i < this->Num; i++)
    {
        if (this->Array[i]->ID == id)
        {
            index = i;
            break;
        }
    }

    return index;
}

void workerManager::deleteEmployee()
{
    cout << "��������Ҫɾ��ְ���ı�ţ�" << endl;
    string id;
    cin >> id;

    int index;
    index = employeeIsExist(id);
    if (index != -1)
    {
        for (int i = index; i < this->Num - 1; i++)
        {
            this->Array[i] = this->Array[i + 1];
        }

        this->Num--;
        this->save();
        cout << "ɾ���ɹ�" << endl;
    }
    else
    {
        cout << "δ�ҵ���ְ����" << endl;
    }

    system("pause");
    system("cls");
}

void workerManager::show()
{
    if (this->FileIsEmpty)
    {
        cout << "�ļ������ڻ��¼Ϊ��" << endl;
    }
    else
    {
        for (int i = 0; i < this->Num; i++)
        {
            this->Array[i]->showInfo();
        }
    }

    system("pause");
    system("cls");
}

void workerManager::initArray()
{
    ifstream ifs(FILENAME, ios::in);

    string id;
    string name;
    string department;

    int num = 0;

    while (ifs >> id && ifs >> name && ifs >> department)
    {
        Employee* e = NULL;

        if (department == "1")
        {
            e = new Worker(id, name, department);
        }
        else if (department == "2")
        {
            e = new Manager(id, name, department);
        }
        else if (department == "3")
        {
            e = new Employer(id, name, department);
        }

        this->Array[num++] = e;
    }
}

workerManager::~workerManager()
{
    if (this->Array != NULL)
    {
        delete[] this->Array;
    }

}

void workerManager::showManu()
{
    cout << "ְ������ϵͳ" << endl;
    cout << "1.�˳�����ϵͳ" << endl;
    cout << "2.����ְ����Ϣ" << endl;
    cout << "3.��ʾְ����Ϣ" << endl;
    cout << "4.ɾ����ְԱ��" << endl;
    cout << "5.�޸�ְ����Ϣ" << endl;
    cout << "6.����Ա����Ϣ" << endl;
    cout << "7.���ձ������" << endl;
    cout << "8.��������ĵ�" << endl;
    cout << "������Ҫʵ�ֵĹ��ܣ������Ӧ��ţ���";

}

void workerManager::add()
{
    cout << "������Ҫ���ӵ�ְ��������" << endl;

    int num = 0;
    cin >> num;

    if (num <= 0)
    {
        cout << "��������" << endl;
    }
    else
    {
        int newSize = num + this->Num;

        //�¿ռ�
        Employee** newSpace = new Employee * [newSize];

        if (this->Array != NULL)
        {
            for (int i = 0; i <this->Num; i++)
            {
                newSpace[i] = this->Array[i];
            }
        }

        for (int i = 0; i < num; i++)
        {
            string id;
            string name;
            int position;

            cout << "�������" << i + 1 << "��ְ����ID��";
            cin >> id;

            cout << "�������" << i + 1 << "��ְ�������֣�";
            cin >> name;

            cout << "��ѡ���ְ����ְλ��" << endl;
            cout << "1.��ְͨ��" << endl;
            cout << "2.����" << endl;
            cout << "3.�ϰ�" << endl;

            cin >> position;

            Employee* employee = NULL;
            switch (position)
            {
            case 1:
                employee = new Worker(id, name, to_string(position));
                break;
            case 2:
                employee = new Manager(id, name, to_string(position));
                break;
            case 3:
                employee = new Employer(id, name, to_string(position));
                break;
            default:
                break;
            }

            newSpace[this->Num + i] = employee;
        }

        delete[] this->Array;

        this->Array = newSpace;

        this->Num = newSize;

        cout << "�ɹ����" << num << "��ְ����Ϣ" << endl;
    }

    this->save();
    this->FileIsEmpty = false;

    system("pause");
    system("cls");
}

void workerManager::exitManagement()
{
    cout << "��ӭ�´�ʹ��" << endl;

    system("pause");

    exit(0);
}

int workerManager::getNum()
{
    ifstream ifs(FILENAME, ios::in);

    string id;
    string name;
    string department;

    int num = 0;

    while (ifs >> id && ifs >> name && ifs >> department)
    {
        num++;
    }

    ifs.close();

    return num;
}

void workerManager::save()
{
    ofstream ofs(FILENAME, ios::out);
    if (!ofs.is_open())
    {
        cout << "�ļ���ʧ��" << endl;
    }

    for (int i = 0; i < this->Num; i++)
    {
        ofs << this->Array[i]->ID << " "
            << this->Array[i]->Name << " "
            << this->Array[i]->DepartmentID << endl;
    }

    ofs.close();
}

void workerManager::change()
{
    cout << "������Ҫ�޸ĵ�ְ��ID��" << endl;
    string id;
    cin >> id;

    cout << "������Ҫ�޸ĵ����ݣ�" << endl;
    cout << "1.ID" << endl;
    cout << "2.����" << endl;
    cout << "3.���ű��" << endl;

    int choice=0;
    cin >> choice;

    switch (choice)
    {
    case 1:
    {
        cout << "�������޸ĺ��ID��"<<endl;
        string changedID;
        cin >> changedID;
        int index = employeeIsExist(id);
        this->Array[index]->ID = changedID;
        this->save();
        cout << "�޸ĳɹ�!" << endl;
        break;
    }
    case 2:
    {
        cout << "�������޸ĺ��������" << endl;
        string changedName;
        cin >> changedName;
        int index = employeeIsExist(id);
        this->Array[index]->Name = changedName;
        this->save();
        cout << "�޸ĳɹ�!" << endl;
        break;
    }
    case 3:
    {
        cout << "�������޸ĺ�Ĳ��ű�ţ�" << endl;
        string changedDepartmentID;
        cin >> changedDepartmentID;
        int index = employeeIsExist(id);
        this->Array[index]->DepartmentID = changedDepartmentID;
        this->save();
        cout << "�޸ĳɹ�!" << endl;
        break;
    }
    case 4:
        break;
    }

    system("pause");
    system("cls");
}

void workerManager::find()
{
    cout << "������Ҫ����ְ����ID��" << endl;
    string id;
    cin >> id;

    int index=employeeIsExist(id);
    if ( index!= -1)
    {
        this->Array[index]->showInfo();
    }
    else
    {
        cout << "δ���ҵ���ְ����" << endl;
    }

    system("pause");
    system("cls");
}

void workerManager::orderByID()
{
    cout << "�����������ְ����ϢΪ:" << endl;

    //ð������
    for (int i = 0; i < this->Num - 1; i++)
    {
        for (int j = 0; j < this->Num - i - 1; j++)
        {
            if (this->Array[i]->ID > this->Array[i + 1]->ID)
            {
                Employee* temp = this->Array[i];
                this->Array[i] = this->Array[i + 1];
                this->Array[i + 1] = temp;
            }
        }
    }

    this->show();
}

void workerManager::remove()
{
    cout << "�Ƿ�Ҫ��������ĵ���" << endl;
    string answer;
    cin >> answer;
    if (answer == "��")
    {
        ifstream ifs(FILENAME, ios::trunc);
        this->FileIsEmpty = true;
        cout << "����������ĵ���" << endl;
    }

    system("pause");
    system("cls");
}

int main()
{
    workerManager wm;
    int choice;
    while (true)
    {
        wm.showManu();
        cin >> choice;

        switch (choice)
        {
        case 1:
            wm.exitManagement();
            break;
        case 2:
            wm.add();
            break;
        case 3:
            wm.show();
            break;
        case 4:
            wm.deleteEmployee();
            break;
        case 5:
            wm.change();
            break;
        case 6:
            wm.find();
            break;
        case 7:
            wm.orderByID();
            break;
        case 8:
            wm.remove();
            break;
        };
    }

}