#include "DataVendorToReport.h"
#include "ReportMediator.h"

DataVendorToReport::DataVendorToReport()
{
   mediator= ReportMediator::getInstance();
}

void DataVendorToReport::send(Data* data)
{
   mediator->receive(data);   
}


