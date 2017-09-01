#include "ReportMediator.h"
#include "ReportFactory.h"
#include "Report.h"

static Mediator* instance;

ReportMediator::~ReportMediator()
{
   Data::deleteDataInstance();
}

void ReportMediator::deleteInstance()
{
   if (instance)
      delete instance;
   instance= nullptr;
}

Mediator* ReportMediator::getInstance()
{
   if(!instance)
      instance= new ReportMediator;
   return instance;
}

void ReportMediator::send(Data* data)
{
   Report* report= ReportFactory::getInstance()->retrieveReport(data->getType());
   report->insert(data);
}
