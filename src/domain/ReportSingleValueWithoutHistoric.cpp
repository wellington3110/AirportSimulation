#include "ReportSingleValueWithoutHistoric.h"
#include "Data.h"
#include "StringConverter.h"

void ReportSingleValueWithoutHistoric::store(Data* data)
{
   value= data->getValue();
}

std::string ReportSingleValueWithoutHistoric::generateReport()
{
   return StringConverter<int>::toString(value);
}
