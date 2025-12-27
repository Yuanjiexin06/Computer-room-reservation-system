#pragma once
#include "identity.h"

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
};