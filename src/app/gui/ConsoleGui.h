#pragma once
#ifndef INCLUDED_CONSOLEGUI_H
#define INCLUDED_CONSOLEGUI_H

#include "Gui.h"
#include <iostream>

class ConsoleGui : public Gui
{
public:
   ~ConsoleGui() {}

   int doInput();
   int getMenuOption();
   int getPlanesOnLand();

   void showMenu();
   void clearDisplay() { system("cls"); }
   void showMessage(std::string message){ std::cout << message;}

   
};

#endif

