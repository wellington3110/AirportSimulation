#include "ReportFactory.h"
#include "LandedReport.h"
#include "OnLandReport.h"
#include "PlanesOnLandExceededCapacityReport.h"
#include "PlanesSentAnotherAirportReport.h"
#include "PlanesWaitingGreaterThanFiveReport.h"
#include "PlanesWaitingReport.h"
#include "RequestTakeOffGreaterThanFiveReport.h"
#include "WindReport.h"

static ReportFactory* instance;

static WindReport* windReport;
static LandedReport* landedReport;
static OnLandReport* onLandReport;
static PlanesWaitingReport* planesWaiting;
static PlanesSentAnotherAirportReport* planesSentAnotherAirportReport;
static PlanesOnLandExceededCapacityReport* planesOnLandExceededCapacity;
static PlanesWaitingGreaterThanFiveReport* planesWaitingGreaterThanFive;
static RequestTakeOffGreaterThanFiveReport* requestTakeOffGreaterThanFive;

ReportFactory::ReportFactory()
{
   windReport= new WindReport;
   landedReport= new LandedReport;
   onLandReport= new OnLandReport;
   planesWaiting= new PlanesWaitingReport;
   planesSentAnotherAirportReport= new PlanesSentAnotherAirportReport;
   planesOnLandExceededCapacity= new PlanesOnLandExceededCapacityReport;
   planesWaitingGreaterThanFive= new PlanesWaitingGreaterThanFiveReport;
   requestTakeOffGreaterThanFive= new RequestTakeOffGreaterThanFiveReport;
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

ReportFactory* ReportFactory::getInstace()
{
   if (!instance)
      instance= new ReportFactory;
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




