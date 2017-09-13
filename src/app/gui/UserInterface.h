#ifndef INCLUDED_USERINTERFACE_H
#define INCLUDED_USERINTERFACE_H
#include <string>

class UserInterface
{
public:
   virtual ~UserInterface() {}

   virtual int getMenuOption() = 0;
   virtual int getPlanesOnLand() = 0;

   virtual void clearDisplay() = 0;
   virtual void showMessage(std::string message) = 0;
  
};

#endif // USERINTERFACE
