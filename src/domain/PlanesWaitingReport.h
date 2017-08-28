#pragma once
#ifndef INCLUDED_PLANESWAITINGREPORT_H
#define INCLUDED_PLANESWAITINGREPORT_H

#include "Report.h"

class PlanesWaitingReport : public Report
{
public:
   PlanesWaitingReport() : value(0), time(0) {}

protected:
   void store(Data* data);
   std::string generateReport(); 
   
private:
   int value;
   int time;
}; 

#endif

