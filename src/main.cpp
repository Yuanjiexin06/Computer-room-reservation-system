#include <iostream>

using namespace std;

#include "identity.h"




int main(){

    while(true){

        cout << "=====================  欢迎来到机房预约系统  ============" << endl;
        cout << "=======================  请选择您的身份  ===============" << endl;
        cout << "|                         1.学生代表                    |" << endl;
        cout << "|                         2.老师                        |" << endl;
        cout << "|                         3.管理员                      |" << endl;
        cout << "|                         0.退出                        |" << endl;
        cout << "=========================================================" << endl;
        cout << "请输入您的选择（0-3）：";
        int choice;
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "您选择了学生代表身份。" << endl;
            // 调用学生代表相关功能
            break;
        case 2:
            cout << "您选择了老师身份。" << endl;
            // 调用老师相关功能
            break;
        case 3:
            cout << "您选择了管理员身份。" << endl;
            // 调用管理员相关功能
            break;
        case 0:
            cout << "感谢使用机房预约系统，程序已退出。" << endl;
            return 0;
            break;
        default:
            cout << "无效的选择，请重新运行程序并选择0-3之间的数字。" << endl;
            cout << "按任意键继续..." << endl;
            cin.ignore();
            cin.get();
            system("clear");
            break;
        }
    }
}