//
// Created by Sakura on 2024/2/28.
//
#include <iostream>
#include "index.h"

using namespace std;

int cindata;


index::index() {
    std::cout << "***************************\n" << std::endl;
    std::cout << "Hello, Wellcome Sakura'ATM!\n" << std::endl;
    std::cout << "***************************" << std::endl;
    sleep(1);
    system("cls");
    std::cout << "***************************\n" << std::endl;
    std::cout << "           Loading ........\n" <<std::endl;
    std::cout << "***************************" << std::endl;
    sleep(1);
    index_print();
}

void index_print() {

    system("cls");
    std::cout << "***************************\n" << std::endl;
    std::cout << "            首页              " <<std::endl;
    std::cout << "           1.登录             " <<std::endl;
    std::cout << "           2.注册             " <<std::endl;
    std::cout << "           3.退出             " <<std::endl;
    std::cout << "Press Enter to continue...\n" <<std::endl;
    std::cout << "***************************" << std::endl;
    std::cin >> cindata;

    switch (cindata) {
        case 1:
            login_print();
            break;
        case 2:
            register_print();
            break;
        case 3:
            exit(0);
        default:
            index_print();
    }
}

void login_print() {
    const int MaxLoginAttempts = 3; // 最大登录尝试次数
    string name;
    string password;
    int loginAttempts = 0; // 当前尝试次数

    while(loginAttempts < MaxLoginAttempts) {
        system("cls");
        cout << "***************************\n" << endl;
        cout << "             登录            " << endl;
        cout << "请输入用户名: \n" << endl;
        cout << "***************************" << endl;
        cin >> name;

        if (name == "admin") {
            cout << "***************************\n" << endl;
            cout << "             登录            " << endl;
            cout << "请输入管理员密码: \n" << endl;
            cout << "***************************" << endl;
            cin >> password;

            if (password == adminpassword) {
                cout << "***************************\n" << endl;
                cout << "             登录            " << endl;
                cout << "管理员登录成功！\n" << endl;
                cout << "***************************" << endl;
                return; // 管理员登录成功，函数结束
            } else {
                cout << "***************************\n" << endl;
                cout << "             登录            " << endl;
                cout << "管理员密码错误！\n" << endl;
                cout << "***************************" << endl;
                loginAttempts++;
                continue; // 用户名输入正确但密码错误，重新开始循环
            }
        } else {
            cout << "***************************\n" << endl;
            cout << "             登录            " << endl;
            cout << "请输入密码: \n" << endl;
            cout << "***************************" << endl;
            cin >> password;
            if (user_login(name, password)) {
                cout << "***************************\n" << endl;
                cout << "             登录            " << endl;
                cout << "登录成功！\n" << endl;
                cout << "***************************" << endl;
                break; // 登录成功，跳出循环
            } else {
                cout << "***************************\n" << endl;
                cout << "             登录            " << endl;
                cout << "登录失败！\n" << endl;
                cout << "***************************" << endl;
                loginAttempts++;
            }
        }
        user_print(name);
        if(loginAttempts == MaxLoginAttempts){
            cout << "***************************\n" << endl;
            cout << "             登录            " << endl;
            cout << "连续登录失败三次，请稍后再试。\n" << endl;
            cout << "***************************" << endl;
            index_print();
        }
    }
}

void register_print() {
    string name;
    string password;

    system("cls");
    cout << "***************************\n" << endl;
    cout << "             注册            " << endl;
    cout << "请输入用户名: "<< endl;
    cout << "用户名长度不得大于6位！\n" << endl;
    cout << "***************************" << endl;
    cin >> name;

    if (name.length() > 6) {
        register_print();
    }

    cout << "***************************\n" << endl;
    cout << "             注册            " << endl;
    cout << "请输入密码: \n" << endl;
    cout << "用户名长度不得小于6位！\n" << endl;
    cout << "***************************" << endl;
    cin >> password;

    if (name.length() > 6) {
        register_print();
    }

    if (user_register(name, password)) {
        cout << "***************************\n" << endl;
        cout << "             注册            " << endl;
        cout << "注册成功！\n" << endl;
        cout << "***************************" << endl;
    } else {
        cout << "***************************\n" << endl;
        cout << "             注册            " << endl;
        cout << "注册失败！\n" << endl;
        cout << "***************************" << endl;
    }
    index_print();
}

void user_print(string  name){
    system("cls");
    cout << "***************************\n" << endl;
    cout << "             用户            " << endl;
    cout << "           用户名: "+name << endl;
    cout << "           1.查询余额        " << endl;
    cout << "           2.存款           " << endl;
    cout << "           3.取款           " << endl;
    cout << "           4.修改密码        " << endl;
    cout << "           5.退出登录 \n     " << endl;
    cout << "***************************" << endl;
    cin >> cindata;

    switch (cindata) {
        case 1:
            user_look_money(name);
            break;

        case 2:
            user_in_money(name);
            break;

        case 3:
            user_out_money(name);
            break;

        case 4:
            user_change_password_print(name);
            break;

            case 5:
            index_print();

        default:
            user_print(name);

    }
}

void user_look_money(string  name){
    int money;
    user_serch_money(name,money);
    system("cls");
    cout << "***************************\n" << endl;
    cout << "             用户            " << endl;
    cout << "           用户名: "+name << endl;
    cout << "           余额: "+money << endl;
    cout << "***************************" << endl;
    cout << "Press Enter to continue...\n" << endl;
    cin >> cindata;
    user_print(name);
}

void user_in_money(string  name){
    int money;
    user_serch_money(name,money);

    system("cls");
    cout << "***************************\n" << endl;
    cout << "             用户            " << endl;
    cout << "           用户名: "+name << endl;
    cout << "           余额: "+money << endl;
    cout << "           请输入存款金额: \n" << endl;
    cout << "***************************" << endl;
    cin >> cindata;

    user_add_money(name,cindata);
    cout << "***************************\n" << endl;
    cout << "             用户            " << endl;
    cout << "           用户名: "+name << endl;
    cout << "           余额: "+money << endl;
    cout << "           存款成功！\n" << endl;
    cout << "***************************" << endl;
    cout << "Press Enter to continue...\n" << endl;
    cin >> cindata;

    user_print(name);
}

void user_out_money(string  name){
    int money;
    user_serch_money(name,money);

    system("cls");
    cout << "***************************\n" << endl;
    cout << "             用户            " << endl;
    cout << "           用户名: "+name << endl;
    cout << "           余额: "+money << endl;
    cout << "           请输入取款金额: \n" << endl;
    cout << "***************************" << endl;
    cin >> cindata;

    user_del_money(name,cindata);
    cout << "***************************\n" << endl;
    cout << "             用户            " << endl;
    cout << "           用户名: "+name << endl;
    cout << "           余额: "+money << endl;
    cout << "           取款成功！\n" << endl;
    cout << "***************************" << endl;
    cout << "Press Enter to continue...\n" << endl;
    cin >> cindata;

    user_print(name);
}

void user_change_password_print(string  name){
    string password;
    system("cls");
    cout << "***************************\n" << endl;
    cout << "             用户            " << endl;
    cout << "           用户名: "+name << endl;
    cout << "           请输入新密码: \n" << endl;
    cout << "***************************" << endl;
    cin >> password;

    if (password.length() > 6) {
        user_change_password(name,password);

        cout << "***************************\n" << endl;
        cout << "             用户            " << endl;
        cout << "           用户名: "+name << endl;
        cout << "           修改密码成功！\n" << endl;
        cout << "***************************" << endl;
    } else {
        cout << "***************************\n" << endl;
        cout << "             用户            " << endl;
        cout << "           用户名: "+name << endl;
        cout << "           修改密码失败！" << endl;
        cout << "           密码长度小于6\n" << endl;
        cout << "***************************" << endl;
    }
    cout << "Press Enter to continue...\n" << endl;
    user_print(name);
}