//
// Created by Sakura on 2024/2/28.
//
#include "iostream"
#include "user.h"

std::string namelib[libsize];
std::string passwordlib[libsize];
int money_lib[libsize];
int libws=0;

User::User(std::string name, std::string password, int money, std::tm *time)
{
    this->name = name;
    this->password = password;
    this->money = money;
    this->time = time;
}

int user_login(std::string name, std::string password)
{
    for(int i = 0; i < sizeof(namelib); i++)
    {
        if (name.compare(namelib[i]) && password.compare(passwordlib[i]))
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
}

int user_register(std::string name, std::string password)
{

    namelib[libws] = name;
    passwordlib[libws] = password;
    money_lib[libws] = 0;
    libws++;
    if (libws >= libsize)
    {
        return 0;
    }
    return 1;

}

void user_serch_money(std::string name,int money)
{
    for(int i = 0; i < sizeof(namelib); i++)
    {
        if (name.compare(namelib[i]))
        {
            money = money_lib[i];
        }
    }
}

void user_add_money(std::string name,int money)
{
    for(int i = 0; i < sizeof(namelib); i++)
    {
        if (name.compare(namelib[i]))
        {
            money_lib[i] = money_lib[i] + money;
        }
    }
}

void user_del_money(std::string name,int money)
{
    for(int i = 0; i < sizeof(namelib); i++)
    {
        if (name.compare(namelib[i]))
        {
            money_lib[i] = money_lib[i] - money;
        }
    }
}

void user_change_password(std::string name,std::string password)
{
    for(int i = 0; i < sizeof(namelib); i++)
    {
        if (name.compare(namelib[i]))
        {
            passwordlib[i] = password;
        }
    }
}//
// Created by Sakura on 2024/2/28.
//

#include "user.h"
