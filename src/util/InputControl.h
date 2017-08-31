#pragma once
#ifndef INCLUDED_INPUTCONTROL_H
#define INCLUDED_INPUTCONTROL_H

class InputControl
{
public:
   InputControl() {};

   static void clearBuffer();
   static int processInput();
};

#endif

