#pragma once
#ifndef INCLUDED_CMDPLANESONLAND_H
#define INCLUDED_CMDPLANESONLAND_H

#include "Command.h"
#include "TemplateProcessReport.h"

class CmdPlanesOnLandNumber : public Command, public TemplateProcessReport
{
public:
   void execute( UserInterface* ui) { generateReport(Data::PLANES_ON_LAND, ui); }
protected:
   std::string getPresentationMessage() { return "Aviões em solo: "; }
};

#endif

