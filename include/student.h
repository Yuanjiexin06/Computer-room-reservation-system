#pragma once

#include <iostream>
#include <string>
#include "identity.h"

class Student : public Identity {
public:
    Student();
    Student(int id, std::string name, std::string pwd);
    ~Student();

    virtual void operMenu();

    void applyOrder(); //申请预约
    void showMyOrder(); //查看自己的预约
    void showAllOrder(); //查看所有预约
    void cancelOrder(); //取消预约

    int m_Id; //学号
};