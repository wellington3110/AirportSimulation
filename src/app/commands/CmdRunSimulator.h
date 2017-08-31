#pragma once
#ifndef INCLUDED_CMDRUNSIMULATOR_H
#define INCLUDED_CMDRUNSIMULATOR_H

#include "Command.h"

class CmdRunSimulator : public Command
{
public:
   void execute(Gui* gui);

   Simulator* simulator;
};

#endif
