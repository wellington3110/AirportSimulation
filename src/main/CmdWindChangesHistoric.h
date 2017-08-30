#pragma once
#ifndef INCLUDED_CMDWINDCHANGES_H
#define INCLUDED_CMDWINDCHANGES_H

#include "Command.h"
#include "TemplateProcessReport.h"

class CmdWindChangesHistoric : public Command, public TemplateProcessReport
{
public:
   void execute(Gui* gui) { generateReport(Data::WIND_CHANGES, gui); }

protected:
   std::string getPresentationMessage() { return "Histórico de mudanças da direção do vento: \n"; }
};

#endif

