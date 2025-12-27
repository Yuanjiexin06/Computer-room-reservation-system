#pragma once
#include "identity.h"
#include "student.h"
#include "teacher.h"
#include "computerRoom.h"
#include <string>
#include <vector>

class Manager : public Identity
{
public:
    Manager();
    Manager(std::string name, std::string pwd);

    virtual void operMenu();
    void addPerson();
    void showPerson();
    void showComputer();
    void cleanFile();

    void initVector();
    std::vector <Student> m_vStu;
    std::vector <Teacher> m_vTea;
    std::vector <ComputerRoom> m_vCom;
    bool checkRepeat(int id, int type);
};