#include "student.h"
#include "globaFile.h"
#include <fstream>
#include "orderFile.h"

Student::Student()
{
}
Student::Student(int id, std::string name, std::string pwd)
    : Identity(std::move(name), std::move(pwd)), m_Id(id) {
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
    ifs.close();
}
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
    std::cout << "\t\t|            0.注销登录                  |\n";
    std::cout << "\t\t|                                        |\n";
    std::cout << "\t\t------------------------------------------\n";
}
void Student::applyOrder()
{
    std::cout << "机房开放时间为周一至周五" << std::endl;
    std::cout << "请输入申请预约的时间：" << std::endl;
    std::cout << "1.周一" << std::endl;
    std::cout << "2.周二" << std::endl;
    std::cout << "3.周三" << std::endl;
    std::cout << "4.周四" << std::endl;
    std::cout << "5.周五" << std::endl;
    int date = 0;
    int interval = 0;
    int room = 0;
    while(true){
        std::cin >> date;
        if(date >=1 && date <=5){
            break;
        }
        else{
            std::cout << "输入有误，请重新输入预约时间！" << std::endl;
        }
    }
    std::cout << "请输入申请预约的时间段：" << std::endl;
    std::cout << "1.上午" << std::endl;
    std::cout << "2.下午" << std::endl;
    while(true){
        std::cin >> interval;
        if(interval == 1 || interval == 2){
            break;
        }
        else{
            std::cout << "输入有误，请重新输入预约时间段！" << std::endl;
        }
    }
    std::cout << "请输入申请预约的机房编号：" << std::endl;
    std::cout << "1号机房容量：" << m_vCom[0].m_MaxNum << std::endl;
    std::cout << "2号机房容量：" << m_vCom[1].m_MaxNum << std::endl;
    std::cout << "3号机房容量：" << m_vCom[2].m_MaxNum << std::endl;
    while(true){
        std::cin >> room;
        if(room >=1 && room <=3){
            break;
        }
        else{
            std::cout << "输入有误，请重新输入预约机房编号！" << std::endl;
        }
    }
    std::cout << "预约申请成功，等待管理员审核！" << std::endl;
    std::ofstream ofs;
    ofs.open(ORDER_FILE, std::ios::app);
    ofs << "date:" << date << " "
        << "interval:" << interval << " "
        << "stuId:" << this->m_Id << " "
        << "stuName:" << this->m_Name << " "
        << "roomId:" << room << " "
        << "status:" << 0 << std::endl;
    ofs.close();
    std::cout << "输入任意键继续" << std::endl;
    std::cin.ignore();
    std::cin.get();
    system("clear");
    this->operMenu();
    return;
}
void Student::showMyOrder()
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
        if (of.m_OrderData[i]["stuId"] == std::to_string(this->m_Id))
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
    }
    std::cout << "输入任意键继续" << std::endl;
    std::cin.ignore();
    std::cin.get();
    system("clear");
    this->operMenu();
    return;
}
void Student::showAllOrder()
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
void Student::cancelOrder()
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
    int num = -1;
    std::cout << "请输入要取消的预约编号：" << std::endl;
    while(true){
        std::cin >> num;
        if(num >=0 && num < of.m_Size){
            if(of.m_OrderData[num]["stuId"] != std::to_string(this->m_Id)){
                std::cout << "该预约编号不属于您，请重新输入！" << std::endl;
                continue;
            }
            break;
        }
        else{
            std::cout << "输入有误，请重新输入预约编号！" << std::endl;
        }
    }
    of.m_OrderData[num]["status"] = "-2";
    of.updateOrder();
    std::cout << "取消预约成功！" << std::endl;
    std::cout << "输入任意键继续" << std::endl;
    std::cin.ignore();
    std::cin.get();
    system("clear");
    this->operMenu();
    return;
}