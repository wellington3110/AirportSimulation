#include "TimeHistoricReport.h"
#include "Data.h"
#include "Converter.h"

void TimeHistoricReport::insert(Data* data)
{
   historic.push_back(Converter::toTimeFormat(data->getTime()));
}

std::string TimeHistoricReport::getReportData()
{
   if( historic.size() == 0)
      return "Nada registrado até o momento";
   std::string report;
   for (iter it= historic.begin(); it != historic.end(); it++)
      report= *it + "\n";
   return report;
}
