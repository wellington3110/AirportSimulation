#pragma once
#ifndef INCLUDED_SINGLEVALUEWITHOUTHISTORICREPORT_H
#define INCLUDED_SINGLEVALUEWITHOUTHISTORICREPORT_H

#include "Report.h"

class SingleValueWithoutHistoricReport : public Report
{
public:
   SingleValueWithoutHistoricReport() : data("0"){}

protected:
   void insert(Data* _data);
   std::string getReportData() { return data; }

private:
   SingleValueWithoutHistoricReport(const SingleValueWithoutHistoricReport&);

   std::string data;
   
};

#endif

