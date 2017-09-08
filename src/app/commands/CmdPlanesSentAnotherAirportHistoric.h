#pragma once
#ifndef INCLUDED_CMDPLANESSENTANOTHERAIRPORTHISTORIC_H
#define INCLUDED_CMDPLANESSENTANOTHERAIRPORTHISTORIC_H

#include "Command.h"
#include "TemplateProcessReport.h"

class CmdPlanesSentAnotherAirportHistoric : public Command, public TemplateProcessReport
{
public:
   void execute(UserInterface* ui)  {generateReport(Data::PLANES_SENT_ANOTHER_AIRPORT, ui); }

protected:
   std::string getPresentationMessage() { return "Histórico de aviões enviados para outros aeroportos:\n";}
};

#endif

