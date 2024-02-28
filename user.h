//
// Created by Sakura on 2024/2/28.
//

#ifndef ATM_NOGUI_USER_H
#define ATM_NOGUI_USER_H

#define libsize 100
#define adminpassword "admin"
#include <iostream>
#include <String.h>
#include <string>
#include <ctime>
using namespace std;

class User {
public:
    User(std::string name, std::string password, int money, std::tm *time);

private:
    std::string name;
    std::string password;
    int money;
    std::tm *time;
};

int user_login(std::string name, std::string password);
int user_register(std::string name, std::string password);
void user_serch_money(std::string name,int money);
void user_add_money(std::string name,int money);
void user_del_money(std::string name,int money);
void user_change_password(std::string name,std::string password);

#endif //ATM_NOGUI_USERS_H
