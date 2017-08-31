#pragma once
#ifndef INCLUDED_CMDLANDINGSNUMBER_H
#define INCLUDED_CMDLANDINGSNUMBER_H

#include "Command.h"
#include "TemplateProcessReport.h"

class CmdLandingsNumber : public Command, public TemplateProcessReport
{
public:
   CmdLandingsNumber(){}
   void execute(Gui* gui) { generateReport(Data::LANDED, gui);}

protected:
   std::string getPresentationMessage() { return "Quantidade: ";}
};

#endif
