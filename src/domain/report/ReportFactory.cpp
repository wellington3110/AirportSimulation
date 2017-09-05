#include "ReportFactory.h"
#include "TimeHistoricReport.h"
#include "SingleValueWithoutHistoricReport.h"
#include "PlanesWaitingReport.h"

static Report* windReport;
static Report* landedReport;
static Report* onLandReport;
static Report* planesWaiting;
static Report* planesSentAnotherAirportReport;
static Report* planesOnLandExceededCapacity;
static Report* planesWaitingGreaterThanFive;
static Report* requestTakeOffGreaterThanFive;

static ReportFactory* instance;

ReportFactory::ReportFactory()
{
   planesWaiting= new PlanesWaitingReport;

   landedReport= new SingleValueWithoutHistoricReport;
   onLandReport= new SingleValueWithoutHistoricReport;

   windReport= new TimeHistoricReport();
   planesOnLandExceededCapacity=   new  TimeHistoricReport();
   planesWaitingGreaterThanFive=   new  TimeHistoricReport();
   requestTakeOffGreaterThanFive=  new TimeHistoricReport();
   planesSentAnotherAirportReport= new TimeHistoricReport();
}

ReportFactory::~ReportFactory()
{
   delete windReport;
   delete landedReport;
   delete onLandReport;
   delete planesWaiting;
   delete planesSentAnotherAirportReport;
   delete planesOnLandExceededCapacity;
   delete planesWaitingGreaterThanFive;
   delete requestTakeOffGreaterThanFive;
}

ReportFactory* ReportFactory::getInstance()
{
   if (!instance)
      instance= new ReportFactory();
   return instance;
}

Report* ReportFactory::retrieveReport(Data::DataType type)
{
   switch (type) {
   case Data::WIND_CHANGES:                       return windReport;
   case Data::LANDED:                             return landedReport;
   case Data::PLANES_ON_LAND:                     return onLandReport;
   case Data::PLANES_WAITING:                     return planesWaiting;
   case Data::PLANES_SENT_ANOTHER_AIRPORT:        return planesSentAnotherAirportReport;
   case Data::PLANES_ON_LAND_EXCEEDED_CAPACITY:   return planesOnLandExceededCapacity;
   case Data::WAITING_GREATER_THAN_5:             return planesWaitingGreaterThanFive;
   case Data::REQUESTING_TAKE_OFF_GREATER_THAN_5: return requestTakeOffGreaterThanFive;
   default: return nullptr;

   }      
}




