#include "DataMediator.h"
#include "ReportFactory.h"
#include "Report.h"

static Mediator* instance;

DataMediator::~DataMediator()
{
   Data::deleteDataInstance();
}

void DataMediator::deleteInstance()
{
   if (instance)
      delete instance;
   instance= nullptr;
}

Mediator* DataMediator::getInstance()
{
   if(!instance)
      instance= new DataMediator;
   return instance;
}

void DataMediator::send(Data* data)
{
   Report* report= ReportFactory::getInstance()->retrieveReport(data->getType());
   report->insert(data);
}
