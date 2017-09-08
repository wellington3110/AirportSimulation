#pragma once
#ifndef INCLUDED_CMDTOLISTUNREADEVENTS
#define INCLUDED_CMDTOLISTUNREADEVENTS

#include "TemplateProcessReport.h"
#include "Command.h"

class CmdToListUnreadEvents :  public Command
{
public:
   void execute(UserInterface* ui);

};

#endif

