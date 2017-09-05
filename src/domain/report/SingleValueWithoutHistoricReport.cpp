#include "SingleValueWithoutHistoricReport.h"
#include "Data.h"
#include "Converter.h"

void SingleValueWithoutHistoricReport::insert(Data* _data)
{
   data= Converter::toString(_data->getValue());
}
