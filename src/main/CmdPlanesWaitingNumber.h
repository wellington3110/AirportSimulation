#pragma once
#ifndef INCLUDED_CMDPLANESWAITING_H
#define INCLUDED_CMDPLANESWAITING_H

#include "Command.h"
#include "TemplateProcessReport.h"


class CmdPlanesWaitingNumber : public Command, public TemplateProcessReport
{   
public:
   void execute(Gui* gui) { generateReport(Data::PLANES_WAITING, gui); }

protected:
   std::string getPresentationMessage() { return ""; }
};

#endif

