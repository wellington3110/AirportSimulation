#pragma once
#ifndef INCLUDED_CMDREMOVEDATA_H
#define INCLUDED_CMDREMOVEDATA_H

#include "Command.h"

class CmdRemoveData : public Command
{
public:
   void execute(Gui* gui);
};

#endif

