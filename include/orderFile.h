#pragma once
#include "globaFile.h"
#include <iostream>
#include <fstream>
#include <string>
#include <map>


class OrderFile
{
public:
    //构造函数
    OrderFile();
    //更新预约信息
    void updateOrder();
    std::map<int, std::map<std::string, std::string>> m_OrderData; //预约记录容器

    int m_Size; //记录预约信息的条数
};