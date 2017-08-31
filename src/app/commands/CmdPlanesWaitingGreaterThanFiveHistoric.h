#pragma once
#ifndef INCLUDED_CMDPLANESWAITINGGREATERTHANFIVEHISTORIC_H
#define INCLUDED_CMDPLANESWAITINGGREATERTHANFIVEHISTORIC_H

#include "Command.h"
#include "TemplateProcessReport.h"

class CmdPlanesWaitingGreaterThanFiveHistoric : public Command, public TemplateProcessReport
{
public:
   void execute(Gui* gui) { generateReport(Data::WAITING_GREATER_THAN_5, gui); }

protected:
   std::string getPresentationMessage() { return "Histórico de aviões aguardando maior que 5:\n"; }

};

#endif

