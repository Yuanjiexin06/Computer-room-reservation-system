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
    OrderFile of;
    if (of.m_Size == 0)
    {
        std::cout << "无预约记录！" << std::endl;
        std::cout << "输入任意键继续" << std::endl;
        std::cin.ignore();
        std::cin.get();
        system("clear");
        this->operMenu();
        return;
    }
    for (int i = 0; i < of.m_Size; ++i)
    {
        std::cout << "预约编号：" << i << "\t";
        std::cout << "预约日期：" << of.m_OrderData[i]["date"] << "\t";
        std::cout << "时间段：" << (of.m_OrderData[i]["interval"] == "1" ? "上午" : "下午") << "\t";
        std::cout << "机房号：" << of.m_OrderData[i]["roomId"] << "\t";
        std::string status;
        if (of.m_OrderData[i]["status"] == "0")
        {
            status = "审核中";
        }
        else if (of.m_OrderData[i]["status"] == "1")
        {
            status = "预约成功";
        }
        else if (of.m_OrderData[i]["status"] == "-1")
        {
            status = "预约失败";
        }else
        {
            status = "已取消";
        }
        std::cout << "预约状态：" << status << std::endl;
    }
    std::cout << "输入任意键继续" << std::endl;
    std::cin.ignore();
    std::cin.get();
    system("clear");
    this->operMenu();
    return;
}
void Teacher::validOrder()
{
    OrderFile of;
    if (of.m_Size == 0)
    {
        std::cout << "无预约记录！" << std::endl;
        std::cout << "输入任意键继续" << std::endl;
        std::cin.ignore();
        std::cin.get();
        system("clear");
        this->operMenu();
        return;
    }
    for (int i = 0; i < of.m_Size; ++i)
    {
        std::cout << "预约编号：" << i << "\t";
        std::cout << "预约日期：" << of.m_OrderData[i]["date"] << "\t";
        std::cout << "时间段：" << (of.m_OrderData[i]["interval"] == "1" ? "上午" : "下午") << "\t";
        std::cout << "机房号：" << of.m_OrderData[i]["roomId"] << "\t";
        std::string status;
        if (of.m_OrderData[i]["status"] == "0")
        {
            status = "审核中";
        }
        else if (of.m_OrderData[i]["status"] == "1")
        {
            status = "预约成功";
        }
        else if (of.m_OrderData[i]["status"] == "-1")
        {
            status = "预约失败";
        }else
        {
            status = "已取消";
        }
        std::cout << "预约状态：" << status << std::endl;
    }
    std::cout << "请输入需要审核的预约编号(-1表示返回)：";
    int orderNum = 0;
    std::cin >> orderNum;
    if (orderNum == -1)
    {
        system("clear");
        this->operMenu();
        return;
    }
    while (orderNum < 0 || orderNum >= of.m_Size)
    {
        std::cout << "输入有误，请重新输入预约编号(-1表示返回)：";
        std::cin >> orderNum;
        if (orderNum == -1)
        {
            system("clear");
            this->operMenu();
            return;
        }
    }
    std::cout << "1.通过  2.不通过 请选择审核结果：";
    int choice = 0;
    std::cin >> choice;
    while (choice != 1 && choice != 2)
    {
        std::cout << "输入有误，请重新选择审核结果：";
        std::cin >> choice;
    }
    if (choice == 1)
    {
        of.m_OrderData[orderNum]["status"] = "1";
    }
    else
    {
        of.m_OrderData[orderNum]["status"] = "-1";
    }
    of.updateOrder();
    std::cout << "审核完成！" << std::endl;
    std::cout << "输入任意键继续" << std::endl;
    std::cin.ignore();
    std::cin.get();
    system("clear");
    this->operMenu();
    return;
}  