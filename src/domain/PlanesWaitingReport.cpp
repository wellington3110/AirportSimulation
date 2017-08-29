#include "PlanesWaitingReport.h"
#include "Converter.h"
#include "Data.h"

void PlanesWaitingReport::insert(Data* _data)
{
   data= "Quantidade: " + Converter::toString(_data->getValue()) +
      "Tempo: " + Converter::toString(_data->getTime()) + "/n"; 
}
