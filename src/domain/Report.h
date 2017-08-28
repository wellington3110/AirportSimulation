#pragma once
#ifndef INCLUDED_REPORT_H
#define INCLUDED_REPORT_H

#include <string>

class Data;

class Report
{
public:
   virtual ~Report(){}

   void insert(Data* data) { store(data); }
   std::string getReportData(){ return generateReport(); }

protected:
   virtual void store(Data* data) = 0;
   virtual std::string generateReport() = 0;
};
#endif
