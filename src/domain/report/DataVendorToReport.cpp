#include "DataVendorToReport.h"
#include "DataMediator.h"


DataVendorToReport::~DataVendorToReport()
{
   DataMediator::deleteInstance();
}

DataVendorToReport::DataVendorToReport()
{
   mediator= DataMediator::getInstance();
}

void DataVendorToReport::sendDateToReport(Data* data)
{
   mediator->receive(data);   
}


