#ifndef INCLUDED_DATAVENDORTOREPORT
#define INCLUDED_DATAVENDORTOREPORT

#include "Mediator.h"

class Data;

class DataVendorToReport
{
public:
   virtual ~DataVendorToReport();

protected:
   DataVendorToReport();
   void sendDateToReport(Data* data);
   
private:
   Mediator* mediator;
   DataVendorToReport(const DataVendorToReport&);

};

#endif
