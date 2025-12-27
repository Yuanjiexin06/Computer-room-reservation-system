#pragma once

#include <iostream>
#include <string>
#include <utility>

// 身份抽象类
class Identity
{
public:
    Identity() = default;
    Identity(std::string name, std::string pwd)
        : m_Name(std::move(name)), m_Pwd(std::move(pwd)) {}

    virtual void operMenu() = 0;

    std::string m_Name;
    std::string m_Pwd;
};