#include "DataVendorToReport.h"
#include "ReportMediator.h"

DataVendorToReport::DataVendorToReport()
{
   mediator= ReportMediator::getInstance();
}

void DataVendorToReport::sendDateToReport(Data* data)
{
   mediator->receive(data);   
}


