#pragma once

#include <iostream>

#include "identity.h"

class Teacher : public Identity {
public:

    Teacher();
    Teacher(int id, std::string name, std::string pwd);
    

    virtual void operMenu();

    void showAllOrder(); //查看所有预约
    void validOrder();   //审核预约

    int m_EmpId; //职工号
};