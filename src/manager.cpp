#include "manager.h"

Manager::Manager()
{
}
Manager::Manager(std::string name, std::string pwd)
    : Identity(std::move(name), std::move(pwd))
{
}
void Manager::operMenu()
{
    std::cout << "欢迎管理员：" << this->m_Name << "登录！" << std::endl;
    std::cout << "\t\t------------------管理员菜单------------------\n";
    std::cout << "\t\t|                                        |\n";
    std::cout << "\t\t|            1.添加账号                  |\n";
    std::cout << "\t\t|            2.查看账号                  |\n";
    std::cout << "\t\t|            3.查看机房信息              |\n";
    std::cout << "\t\t|            4.清空预约记录              |\n";
    std::cout << "\t\t|            0.退出系统                  |\n";
    std::cout << "\t\t|                                        |\n";
    std::cout << "\t\t------------------------------------------\n";
}
void Manager::addPerson()
{
}
void Manager::showPerson()
{
}
void Manager::showComputer()
{
}
void Manager::cleanFile()
{
}