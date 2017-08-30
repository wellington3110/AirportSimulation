#pragma once
#ifndef INCLUDED_PLANESWAITINGREPORT_H
#define INCLUDED_PLANESWAITINGREPORT_H

#include "Report.h"

class PlanesWaitingReport : public Report
{
public:
   PlanesWaitingReport() : data("0"){}

protected:
   void insert(Data* data);
   std::string getReportData() { return data; } 
   
private:
   std::string data;
}; 

#endif

