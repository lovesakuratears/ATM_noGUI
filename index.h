//
// Created by Sakura on 2024/2/28.
//

#ifndef ATM_NOGUI_INDEX_H
#define ATM_NOGUI_INDEX_H
#include <iostream>
#include <String.h>
#include <unistd.h>
#include <cstdlib>
#include "user.h"
using namespace std;

class index {
public:

    tm *time;
    index();
    void print();
};
void login_print();
void register_print();
void user_print(string  name);
void index_print();
void user_look_money(string  name);
void user_in_money(string  name);
void user_out_money(string  name);
void user_change_password_print(string  name);
#endif //ATM_NOGUI_INDEX_H
