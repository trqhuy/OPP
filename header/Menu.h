#ifndef MENU_H
#define MENU_H

#include "Admin.h"
#include "ATM.h"
#include "Customer.h"

#include <conio.h>
#include <regex>
#include <unistd.h>

using namespace std;

void weigh();
int wait();
bool login();

void Print_Menu();
void Print_Menu_1();
void Print_Menu_2();
void Print_Menu_3();

void Oder1_1(Admin admin);
void Oder1_2(Admin admin);
void Oder1_3(Admin admin);

void Oder2_1(Admin admin);
void Oder2_1_1(Admin admin);
void Oder2_1_2(Admin admin);
void Oder2_1_3(Admin admin);


void Oder2_2(Admin admin);
void Oder2_2_1(Admin admin);
void Oder2_2_2(Admin admin);
void Oder2_2_3(Admin admin);

void Oder2_3(Admin admin);
void Oder2_4(Admin admin);
void Oder2_5(Admin admin);

void Oder3_1(Admin admin);
void Oder3_2(Admin admin);
void Oder3_3(Admin admin);
void Oder3_4(Admin admin);
void Oder3_5(Admin admin);

#endif