#include "student.h"

Student::Student()
{
}
Student::Student(int id, std::string name, std::string pwd)
    : Identity(std::move(name), std::move(pwd)), m_Id(id) {}
Student::~Student()
{
}
void Student::operMenu()
{
    std::cout << "欢迎学生代表：" << this->m_Name << "登录！" << std::endl;
    std::cout << "\t\t------------------学生菜单------------------\n";
    std::cout << "\t\t|                                        |\n";
    std::cout << "\t\t|            1.申请预约                  |\n";
    std::cout << "\t\t|            2.查看我的预约              |\n";
    std::cout << "\t\t|            3.查看所有预约              |\n";
    std::cout << "\t\t|            4.取消预约                  |\n";
    std::cout << "\t\t|            0.退出系统                  |\n";
    std::cout << "\t\t|                                        |\n";
    std::cout << "\t\t------------------------------------------\n";
}
void Student::applyOrder()
{
}
void Student::showMyOrder()
{
}
void Student::showAllOrder()
{
}
void Student::cancelOrder()
{
}