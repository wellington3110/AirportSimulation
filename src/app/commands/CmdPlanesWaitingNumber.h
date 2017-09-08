#pragma once
#ifndef INCLUDED_CMDPLANESWAITING_H
#define INCLUDED_CMDPLANESWAITING_H

#include "Command.h"
#include "TemplateProcessReport.h"


class CmdPlanesWaitingNumber : public Command, public TemplateProcessReport
{   
public:
   void execute(UserInterface* ui) { generateReport(Data::PLANES_WAITING, ui); }

protected:
   std::string getPresentationMessage() { return ""; }
};

#endif

