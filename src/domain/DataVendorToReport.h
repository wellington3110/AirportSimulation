#ifndef  INCLUDED_DATA_VENDOR_TO_REPORT
#define INCLUDED_DATA_VENDOR_TO_REPORT
#include "Mediator.h"

class Data;

class DataVendorToReport
{
public:
   virtual ~DataVendorToReport() {}

protected:
   DataVendorToReport();
   void send(Data* data);
   Mediator* mediator;

private:  
   DataVendorToReport(const DataVendorToReport&);

};

#endif
