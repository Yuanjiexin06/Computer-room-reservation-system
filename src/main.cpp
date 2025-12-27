#include <iostream>
#include <fstream>
#include <string>

using namespace std;

#include "identity.h"
#include "student.h"
#include "teacher.h"
#include "manager.h"
#include "globaFile.h"

void managerMenu(Identity *&manager)
{
    manager->operMenu();
    Manager *man = (Manager *)manager;
    while (true)
    {
        //man->operMenu();
        std::cout << "请输入您的选择：" << std::endl;
        int choice;
        std::cin >> choice;
        switch (choice)
        {
        case 1:
            std::cout << "添加账号" << std::endl;
            man->addPerson();
            break;
        case 2:
            std::cout << "查看账号" << std::endl;
            man->showPerson();
            break;
        case 3:
            std::cout << "查看机房信息" << std::endl;
            man->showComputer();
            break;
        case 4:
            std::cout << "清空预约记录" << std::endl;
            man->cleanFile();
            break;
        case 0:
            delete manager;
            std::cout << "注销成功" << std::endl;
            return;
        default:
            std::cout << "输入有误，请重新输入！" << std::endl;
            break;
        }
    }
}
void LoginIn(string Filename, int type){
    //type 1学生 2老师 3管理员
    Identity * person = nullptr; //父类指针指向子类对象
    ifstream ifs;
    ifs.open(Filename, ios::in);
    if(!ifs.is_open()){
        cout << "文件不存在或打开失败" << endl;
        ifs.close();
        return;
    }
    //准备接收用户信息
    string name;
    string pwd;
    int id;
    if(type == 1){
        cout << "请输入你的学号" << endl;
        cin >> id;
    }else if(type == 2){
        cout << "请输入你的工号" << endl;
        cin >> id;
    }
    cout << "请输入用户名" << endl;
    cin >> name;
    cout << "请输入密码" << endl;
    cin >> pwd;
    //验证用户信息
    if(type == 1){
        int fId;
        string fName;
        string fPwd;
        while(ifs >> fId && ifs >> fName && ifs >> fPwd){

            if(id == fId && name == fName && pwd == fPwd){
                cout << "欢迎学生代表" << name << "登录成功！" << endl;
                cout << "按任意键继续..." << endl;
                cin.ignore();
                cin.get();
                system("clear");
                person = new Student(fId, fName, fPwd);

                return;
            }
        }
    }
    else if(type == 2){
        int fId;
        string fName;
        string fPwd;
        while (ifs >> fId && ifs >> fName && ifs >> fPwd)
        {

            if (id == fId && name == fName && pwd == fPwd)
            {
                cout << "欢迎老师" << name << "登录成功！" << endl;
                cout << "按任意键继续..." << endl;
                cin.ignore();
                cin.get();
                system("clear");
                person = new Teacher(fId, fName, fPwd);

                return;
            }
        }
    }
    else{
        string fName;
        string fPwd;
        while (ifs >> fName && ifs >> fPwd)
        {
            if (name == fName && pwd == fPwd)
            {
                cout << "欢迎管理员" << name << "登录成功！" << endl;
                cout << "按任意键继续..." << endl;
                cin.ignore();
                cin.get();
                system("clear");
                person = new Manager(fName, fPwd);
                managerMenu(person);
                return;
            }
        }
        
    }
    cout << "验证失败，用户名或密码错误！" << endl;
    cout << "按任意键继续..." << endl;
    cin.ignore();
    cin.get();
    system("clear");
    return;
}


int main(){

    while(true){

        cout << "=====================  欢迎来到机房预约系统  ============" << endl;
        cout << "=======================  请选择您的身份  ===============" << endl;
        cout << "|                         1.学生代表                    |" << endl;
        cout << "|                         2.老师                        |" << endl;
        cout << "|                         3.管理员                      |" << endl;
        cout << "|                         0.退出                        |" << endl;
        cout << "=========================================================" << endl;
        cout << "请输入您的选择（0-3）：";
        int choice;
        cin >> choice;
        switch (choice)
        {
        case 1:
            LoginIn(STU_FILE, 1);
            // 调用学生代表相关功能
            break;
        case 2:
            LoginIn(TEA_FILE, 2);
            // 调用老师相关功能
            break;
        case 3:
            LoginIn(ADMIN_FILE, 3);
            // 调用管理员相关功能
            break;
        case 0:
            cout << "感谢使用机房预约系统，程序已退出。" << endl;
            return 0;
            break;
        default:
            cout << "无效的选择，请重新运行程序并选择0-3之间的数字。" << endl;
            cout << "按任意键继续..." << endl;
            cin.ignore();
            cin.get();
            system("clear");
            break;
        }
    }
}