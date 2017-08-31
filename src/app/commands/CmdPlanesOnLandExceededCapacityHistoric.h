#pragma once

#ifndef INCLUDED_CMDPLANESONLANDEXCEEDEDCAPACITYHISTORIC_H
#define INCLUDED_CMDPLANESONLANDEXCEEDEDCAPACITYHISTORIC_H

#include "Command.h"
#include "TemplateProcessReport.h"

class CmdPlanesOnLandExceededCapacityHistoric : public Command, public TemplateProcessReport
{
public:
   void execute(Gui* gui) {generateReport(Data::PLANES_ON_LAND_EXCEEDED_CAPACITY, gui); }

protected:
   std::string getPresentationMessage() { return "Histórico de aviões em solo maior que 70% da capacidade:\n";}
};

#endif

