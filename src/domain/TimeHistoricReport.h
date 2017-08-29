#pragma once
#ifndef INCLUDED_TIMEHISTORICREPORT_H
#define INCLUDED_TIMEHISTORICREPORT_H

#include <vector>
#include "Report.h"

class TimeHistoricReport : public Report
{
public:
   TimeHistoricReport(){}

protected:
   void insert(Data* data);
    std::string getReportData();
   
private:
   TimeHistoricReport(const TimeHistoricReport&);

   std::vector<std::string> historic;
   typedef std::vector<std::string>::iterator iter;
};

#endif

