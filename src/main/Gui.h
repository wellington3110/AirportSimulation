#ifndef INCLUDED_GUI_H
#define INCLUDED_GUI_H
#include <string>

class Gui
{
public:
   virtual ~Gui() {}

   virtual int doInput() = 0;
   virtual int getMenuOption() = 0;

   virtual void showMenu() = 0;
   virtual void clearDisplay() = 0;
   virtual void showMessage(std::string message) = 0;
  
};

#endif
