#pragma once
#ifndef INCLUDED_CMDPLANESONLAND_H
#define INCLUDED_CMDPLANESONLAND_H

#include "Command.h"
#include "TemplateProcessReport.h"

class CmdPlanesOnLandNumber : public Command, public TemplateProcessReport
{
public:
   void execute( Gui* gui) {generateReport(Data::PLANES_ON_LAND, gui);}
protected:
   std::string getPresentationMessage() { return "Aviões em solo: "; }
};

#endif

