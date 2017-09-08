#ifndef INCLUDED_GUI_H
#define INCLUDED_GUI_H
#include <string>

class UserInterface
{
public:
   virtual ~UserInterface() {}

   virtual int doInput() = 0;
   virtual int getMenuOption() = 0;
   virtual int getPlanesOnLand() = 0;

   virtual void showMenu() = 0;
   virtual void clearDisplay() = 0;
   virtual void showMessage(std::string message) = 0;
  
};

#endif
