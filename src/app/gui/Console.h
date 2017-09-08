#pragma once
#ifndef INCLUDED_CONSOLEGUI_H
#define INCLUDED_CONSOLEGUI_H

#include "UserInterface.h"
#include <iostream>

class Console : public UserInterface
{
public:
   ~Console() {}

   int doInput();
   int getMenuOption();
   int getPlanesOnLand();

   void showMenu();
   void clearDisplay() { system("cls"); }
   void showMessage(std::string message){ std::cout << message;}

   
};

#endif

