#include "manager.h"
#include "globaFile.h"
#include <fstream>

Manager::Manager()
{
}
Manager::Manager(std::string name, std::string pwd)
    : Identity(std::move(name), std::move(pwd))
{
    this->initVector();
    std::ifstream ifs;
    ifs.open(COMPUTER_FILE, std::ios::in);
    if (!ifs.is_open())
    {
        std::cout << "机房文件不存在或打开失败" << std::endl;
        ifs.close();
        return;
    }
    ComputerRoom c;
    while(ifs >> c.m_ComId && ifs >> c.m_MaxNum)
    {
        m_vCom.push_back(c);
    }
    std::cout << "当前的机房数量为：" << m_vCom.size() << std::endl;
    ifs.close();
}
void Manager::operMenu()
{
    std::cout << "欢迎管理员：" << this->m_Name << "登录！" << std::endl;
    std::cout << "\t\t---------------管理员菜单-----------------\n";
    std::cout << "\t\t|                                        |\n";
    std::cout << "\t\t|            1.添加账号                  |\n";
    std::cout << "\t\t|            2.查看账号                  |\n";
    std::cout << "\t\t|            3.查看机房信息              |\n";
    std::cout << "\t\t|            4.清空预约记录              |\n";
    std::cout << "\t\t|            0.注销登录                  |\n";
    std::cout << "\t\t|                                        |\n";
    std::cout << "\t\t------------------------------------------\n";
}
void Manager::addPerson()
{
    while(true){
    std::cout << "请选择添加的账号类型：" << std::endl;
    std::cout << "1.添加学生账号" << std::endl;
    std::cout << "2.添加教师账号" << std::endl;
    std::string fileName;
    std::string tip;
    std::string errorTip;
    std::ofstream ofs;
    int choice = 0;
    std::cin >> choice;
    if (choice == 1){
        fileName = STU_FILE;
        tip = "请输入学号";
        errorTip = "学号已存在，请重新输入！";
    }
    else if (choice == 2){
        fileName = TEA_FILE;
        tip = "请输入教师工号";
        errorTip = "工号已存在，请重新输入！";
    }
    else{
        std::cout << "输入有误，请重新输入！" << std::endl;
        continue;
    }
    ofs.open(fileName, std::ios::out | std::ios::app);
    int id;
    std::string name;
    std::string pwd;
    std::cout << tip << std::endl;
    while(true){
        std::cin >> id;
        if(this->checkRepeat(id, choice)){
            std::cout << errorTip << std::endl;
        }
        else{
            break;
        }
    }
    //std::cin >> id;
    std::cout << "请输入姓名" << std::endl;
    std::cin >> name;
    std::cout << "请输入密码" << std::endl;
    std::cin >> pwd;
    ofs << id << " " << name << " " << pwd << std::endl;
    std::cout << "添加成功！" << std::endl;
    ofs.close();
    std::cout << "输入任意键继续" << std::endl;
    std::cin.ignore();
    std::cin.get();
    system("clear");
    this->initVector();
    this->operMenu();
    return;
  }
    
}
void Manager::showPerson()
{
    while(true){
    std::cout << "请选择查看的账号类型：" << std::endl;
    std::cout << "1.查看学生账号" << std::endl;
    std::cout << "2.查看教师账号" << std::endl;
    int choice = 0;
    std::cin >> choice;
    if (choice == 1){
        for (auto it = m_vStu.begin(); it != m_vStu.end(); ++it){
            std::cout << "学号：" << it->m_Id << "\t姓名：" << it->m_Name << "\t密码：" << it->m_Pwd << std::endl;
        }
    }
    else if (choice == 2){
        for (auto it = m_vTea.begin(); it != m_vTea.end(); ++it){
            std::cout << "工号：" << it->m_EmpId << "\t姓名：" << it->m_Name << "\t密码：" << it->m_Pwd << std::endl;
        }
    }
    else{
        std::cout << "输入有误，请重新输入！" << std::endl;
        continue;
    }
    std::cout << "输入任意键继续" << std::endl;
    std::cin.ignore();
    std::cin.get();
    system("clear");
    this->operMenu();
    return;
  }
}
void Manager::showComputer()
{
    for (auto it = m_vCom.begin(); it != m_vCom.end(); ++it){
        std::cout << "机房编号：" << it->m_ComId << "\t机房最大容量：" << it->m_MaxNum << std::endl;
    }
    std::cout << "输入任意键继续" << std::endl;
    std::cin.ignore();
    std::cin.get();
    system("clear");
    this->operMenu();
    return;
}
void Manager::cleanFile()
{
    std::ofstream ofs;
    ofs.open(ORDER_FILE, std::ios::trunc);
    ofs.close();
    std::cout << "清空成功！" << std::endl;
    std::cout << "输入任意键继续" << std::endl;
    std::cin.ignore();
    std::cin.get();
    system("clear");
    this->operMenu();
    return;
}
void Manager::initVector()
{
    std::ifstream ifs;
    //初始化学生信息
    ifs.open(STU_FILE, std::ios::in);
    if (!ifs.is_open())
    {
        std::cout << "学生文件不存在或打开失败" << std::endl;
        ifs.close();
        return;
    }

    m_vStu.clear();
    m_vTea.clear();

    Student s;
    while(ifs >> s.m_Id && ifs >> s.m_Name && ifs >> s.m_Pwd)
    {
        m_vStu.push_back(s);
    }
    std::cout << "当前的学生人数为：" << m_vStu.size() << std::endl;
    ifs.close();
    //初始化教师信息
    ifs.open(TEA_FILE, std::ios::in);
    if (!ifs.is_open())
    {
        std::cout << "教师文件不存在或打开失败" << std::endl;
        ifs.close();
        return;
    }
    Teacher t;
    while(ifs >> t.m_EmpId && ifs >> t.m_Name && ifs >> t.m_Pwd)
    {
        m_vTea.push_back(t);
    }
    std::cout << "当前的教师人数为：" << m_vTea.size() << std::endl;
    ifs.close();
}
bool Manager::checkRepeat(int id, int type){
    if(type == 1){
        for (auto it = m_vStu.begin(); it != m_vStu.end(); ++it){
            if(it->m_Id == id){
                return true;
            }
        }
    }
    else if(type == 2){
        for (auto it = m_vTea.begin(); it != m_vTea.end(); ++it){
            if(it->m_EmpId == id){
                return true;
            }
        }
    }
    return false;
}