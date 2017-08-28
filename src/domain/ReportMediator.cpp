#include "ReportMediator.h"
#include "ReportFactory.h"
#include "Report.h"

static Mediator* instance;

Mediator* ReportMediator::getInstance()
{
   if(!instance)
      instance= new ReportMediator;
   return instance;
}

void ReportMediator::send(Data* data)
{
   Report* report= ReportFactory::getInstace()->retrieveReport(data->getType());
   report->insert(data);
}
