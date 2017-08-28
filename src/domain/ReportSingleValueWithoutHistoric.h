#pragma once
#ifndef INCLUDED_REPORTWITHOUTHISTORIC_H
#define INCLUDED_REPORTWITHOUTHISTORIC_H

#include "Report.h"

class ReportSingleValueWithoutHistoric : public Report
{
protected:
   ReportSingleValueWithoutHistoric() : value(0) {}

   void store(Data* data);
   std::string generateReport();
private:
   ReportSingleValueWithoutHistoric(const ReportSingleValueWithoutHistoric&);
   int value;
   
};

#endif

