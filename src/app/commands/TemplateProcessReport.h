#pragma once
#ifndef INCLUDED_TEMPLATECMDMESSAGE
#define INCLUDED_TEMPLATECMDMESSAGE
#include <string>
#include "Data.h"

class Report;
class Gui;

class TemplateProcessReport
{
public:
   virtual ~TemplateProcessReport() {}

protected:
   TemplateProcessReport() {}

   virtual std::string getPresentationMessage() = 0;

   void generateReport(Data::DataType data, Gui* gui);
   
private:
   TemplateProcessReport (const TemplateProcessReport&);

};

#endif

