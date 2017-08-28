#include "ReportSingleValueWithHistoric.h"
#include "Data.h"
#include "StringConverter.h"

void ReportSingleValueWithHistoric::store(Data* data)
{
   historic.push_back( data->getTime() );
}

std::string ReportSingleValueWithHistoric::generateReport()
{
   std::stringstream report;
   for (iter it= historic.begin(); it != historic.end(); it++)
      report << *it;
   return report.str();
}
