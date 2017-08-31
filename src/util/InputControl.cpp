#include "InputControl.h"
#include <iostream>

void InputControl::clearBuffer()
{
   std::cin.clear();
   std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
}

int InputControl::processInput()
{
   int input= 0;
   std::cin >> input;
   if (std::cin.fail() ) {
      clearBuffer();
      throw std::runtime_error("\nerror:Invalid input \n\n");
   }
   return input;
}



