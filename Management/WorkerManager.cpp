#include"WorkerManager.h"

workerManager::workerManager()
{
    ifstream ifs;
    ifs.open(FILENAME, ios::in);

    if (!ifs.is_open())
    {
        cout << "文件不存在" << endl;
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
        cout << "文件为空" << endl;
        this->Num = 0;
        this->Array = NULL;
        this->FileIsEmpty = true;
        ifs.close();
        return;
    }

    int num = this->getNum();
    //cout << "职工数量为：" << num << endl;
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
    cout << "请输入想要删除职工的编号：" << endl;
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
        cout << "删除成功" << endl;
    }
    else
    {
        cout << "未找到该职工！" << endl;
    }

    system("pause");
    system("cls");
}

void workerManager::show()
{
    if (this->FileIsEmpty)
    {
        cout << "文件不存在或记录为空" << endl;
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
    cout << "职工管理系统" << endl;
    cout << "1.退出管理系统" << endl;
    cout << "2.增加职工信息" << endl;
    cout << "3.显示职工信息" << endl;
    cout << "4.删除离职员工" << endl;
    cout << "5.修改职工信息" << endl;
    cout << "6.查找员工信息" << endl;
    cout << "7.按照编号排序" << endl;
    cout << "8.清空所有文档" << endl;
    cout << "请输入要实现的功能（输入对应序号）：";

}

void workerManager::add()
{
    cout << "请输入要增加的职工数量：" << endl;

    int num = 0;
    cin >> num;

    if (num <= 0)
    {
        cout << "输入有误" << endl;
    }
    else
    {
        int newSize = num + this->Num;

        //新空间
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

            cout << "请输入第" << i + 1 << "个职工的ID：";
            cin >> id;

            cout << "请输入第" << i + 1 << "个职工的名字：";
            cin >> name;

            cout << "请选择该职工的职位：" << endl;
            cout << "1.普通职工" << endl;
            cout << "2.经理" << endl;
            cout << "3.老板" << endl;

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

        cout << "成功添加" << num << "个职工信息" << endl;
    }

    this->save();
    this->FileIsEmpty = false;

    system("pause");
    system("cls");
}

void workerManager::exitManagement()
{
    cout << "欢迎下次使用" << endl;

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
        cout << "文件打开失败" << endl;
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
    cout << "请输入要修改的职工ID：" << endl;
    string id;
    cin >> id;

    cout << "请输入要修改的内容：" << endl;
    cout << "1.ID" << endl;
    cout << "2.姓名" << endl;
    cout << "3.部门编号" << endl;

    int choice=0;
    cin >> choice;

    switch (choice)
    {
    case 1:
    {
        cout << "请输入修改后的ID："<<endl;
        string changedID;
        cin >> changedID;
        int index = employeeIsExist(id);
        this->Array[index]->ID = changedID;
        this->save();
        cout << "修改成功!" << endl;
        break;
    }
    case 2:
    {
        cout << "请输入修改后的姓名：" << endl;
        string changedName;
        cin >> changedName;
        int index = employeeIsExist(id);
        this->Array[index]->Name = changedName;
        this->save();
        cout << "修改成功!" << endl;
        break;
    }
    case 3:
    {
        cout << "请输入修改后的部门编号：" << endl;
        string changedDepartmentID;
        cin >> changedDepartmentID;
        int index = employeeIsExist(id);
        this->Array[index]->DepartmentID = changedDepartmentID;
        this->save();
        cout << "修改成功!" << endl;
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
    cout << "请输入要查找职工的ID：" << endl;
    string id;
    cin >> id;

    int index=employeeIsExist(id);
    if ( index!= -1)
    {
        this->Array[index]->showInfo();
    }
    else
    {
        cout << "未查找到该职工！" << endl;
    }

    system("pause");
    system("cls");
}

void workerManager::orderByID()
{
    cout << "按编号排序后的职工信息为:" << endl;

    //冒泡排序
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
    cout << "是否要清空所有文档？" << endl;
    string answer;
    cin >> answer;
    if (answer == "是")
    {
        ifstream ifs(FILENAME, ios::trunc);
        this->FileIsEmpty = true;
        cout << "已清空所有文档！" << endl;
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