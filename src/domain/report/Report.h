#pragma once
#ifndef INCLUDED_REPORT_H
#define INCLUDED_REPORT_H

#include <string>

class Data;

class Report
{
public:
   virtual ~Report(){}

   virtual void insert(Data* data) = 0;
   virtual std::string getReportData() = 0;
};
#endif
