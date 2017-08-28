#pragma once
#ifndef INCLUDED_REPORTWITHHISTORIC_H
#define INCLUDED_REPORTWITHHISTORIC_H

#include <vector>
#include "Report.h"

class ReportSingleValueWithHistoric : public Report
{
protected:
   ReportSingleValueWithHistoric(){}

   void store(Data* data);
   std::string generateReport();
   
private:
   ReportSingleValueWithHistoric(const ReportSingleValueWithHistoric&);

   std::vector<int> historic;
   typedef std::vector<int>::iterator iter;
};

#endif

