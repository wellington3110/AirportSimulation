#include "LandedReport.h"
#include "StringConverter.h"

std::string LandedReport::getReportData()
{
   return StringConverter<int>::toString(value);
}
