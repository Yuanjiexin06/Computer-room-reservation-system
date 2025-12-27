#include "teacher.h"

Teacher::Teacher()
{
}
Teacher::Teacher(int id, std::string name, std::string pwd)
    : Identity(std::move(name), std::move(pwd)), m_EmpId(id) {}
void Teacher::operMenu()
{
    std::cout << "欢迎老师：" << this->m_Name << "登录！" << std::endl;
    std::cout << "\t\t------------------教师菜单------------------\n";
    std::cout << "\t\t|                                        |\n";
    std::cout << "\t\t|            1.查看所有预约              |\n";
    std::cout << "\t\t|            2.审核预约                  |\n";
    std::cout << "\t\t|            0.退出系统                  |\n";
    std::cout << "\t\t|                                        |\n";
    std::cout << "\t\t------------------------------------------\n";
}
void Teacher::showAllOrder()
{
}
void Teacher::validOrder()
{
}  