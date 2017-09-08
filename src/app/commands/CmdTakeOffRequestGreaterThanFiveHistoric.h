#pragma once
#ifndef INCLUDED_CMDTAKEOFFREQUESTSGREATERTHANFIVEHISTORIC_H
#define INCLUDED_CMDTAKEOFFREQUESTSGREATERTHANFIVEHISTORIC_H

#include "Command.h"
#include "TemplateProcessReport.h"

class CmdTakeOffRequestGreaterThanFiveHistoric : public Command, public TemplateProcessReport
{
public:
   void execute(UserInterface* ui) { generateReport(Data::REQUESTING_TAKE_OFF_GREATER_THAN_5, ui); }

protected:
   std::string getPresentationMessage() { return "Histórico de decolagens pendentes acima de 5:\n"; }
};

#endif

