#include "PlanesWaitingReport.h"
#include "StringConverter.h"
#include "Data.h"

void PlanesWaitingReport::store(Data* data)
{
   time= data->getTime();
   value= data->getValue();
}

std::string PlanesWaitingReport::generateReport()
{
   std::stringstream report;
   report << "Quantidade:" << value << "Tempo" << time << std::endl;
   return report.str();
}
