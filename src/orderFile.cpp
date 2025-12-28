
#include "orderFile.h"

OrderFile::OrderFile()
{
    std::ifstream ifs;
    ifs.open(ORDER_FILE, std::ios::in);
    if (!ifs.is_open())
    {
        std::cout << "预约记录文件不存在或打开失败" << std::endl;
        ifs.close();
        this->m_Size = 0;
        return;
    }
    std::string date; //预约日期
    std::string interval;  //时间段
    std::string stuId;  //学号
    std::string stuName;  //姓名
    std::string roomId;  //机房号
    std::string status;  //预约状态
    this->m_Size = 0;  //记录预约信息的条数
    while (ifs >> date && ifs >> interval && ifs >> stuId && ifs >> stuName && ifs >> roomId && ifs >> status)
    {
        std::map<std::string, std::string> m;
        std::string key;
        std::string value;
        
        key = date.substr(0, date.find(":"));
        value = date.substr(date.find(":") + 1, date.size() - date.find(":") - 1);
        m.insert(std::make_pair(key, value));

        key = interval.substr(0, interval.find(":"));
        value = interval.substr(interval.find(":") + 1, interval.size() - interval.find(":") - 1);
        m.insert(std::make_pair(key, value));

        key = stuId.substr(0, stuId.find(":"));
        value = stuId.substr(stuId.find(":") + 1, stuId.size() - stuId.find(":") - 1);
        m.insert(std::make_pair(key, value));

        key = stuName.substr(0, stuName.find(":"));
        value = stuName.substr(stuName.find(":") + 1, stuName.size() - stuName.find(":") - 1);
        m.insert(std::make_pair(key, value));

        key = roomId.substr(0, roomId.find(":"));
        value = roomId.substr(roomId.find(":") + 1, roomId.size() - roomId.find(":") - 1);
        m.insert(std::make_pair(key, value));

        key = status.substr(0, status.find(":"));
        value = status.substr(status.find(":") + 1, status.size() - status.find(":") - 1);
        m.insert(std::make_pair(key, value));

        this->m_OrderData.insert(std::make_pair(this->m_Size, m));

        this->m_Size++;
    }
    ifs.close();
    // for(auto it = m_OrderData.begin(); it != m_OrderData.end(); ++it){
    //     std::cout << "预约编号：" << it->first << " ";
    //     for(auto mit = it->second.begin(); mit != it->second.end(); ++mit){
    //         std::cout << mit->first << ":" << mit->second << " ";
    //     }
    //     std::cout << std::endl;
    // }
}
void OrderFile::updateOrder()
{
    if (this->m_Size == 0)
    {
        return;
    }
    std::ofstream ofs;
    ofs.open(ORDER_FILE, std::ios::out | std::ios::trunc);
    for (int i = 0; i < this->m_Size; ++i)
    {
        ofs << "date:" << this->m_OrderData[i]["date"] << " "
            << "interval:" << this->m_OrderData[i]["interval"] << " "
            << "stuId:" << this->m_OrderData[i]["stuId"] << " "
            << "stuName:" << this->m_OrderData[i]["stuName"] << " "
            << "roomId:" << this->m_OrderData[i]["roomId"] << " "
            << "status:" << this->m_OrderData[i]["status"] << std::endl;
    }
    ofs.close();
}