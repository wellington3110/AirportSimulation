#pragma once
#ifndef INCLUDED_CMDLANDINGSNUMBER_H
#define INCLUDED_CMDLANDINGSNUMBER_H

#include "Command.h"
#include "TemplateProcessReport.h"

class CmdLandingsNumber : public Command, public TemplateProcessReport
{
public:
   CmdLandingsNumber(){}
   void execute(UserInterface* ui) { generateReport(Data::LANDED, ui);}

protected:
   std::string getPresentationMessage() { return "Quantidade: ";}
};

#endif
