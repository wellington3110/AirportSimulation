#include "PlanesWaitingReport.h"
#include "Converter.h"
#include "Data.h"

void PlanesWaitingReport::insert(Data* _data)
{
   data= "Quantidade: " + Converter::toString(_data->getValue()) +
      " | Tempo aguardando: " + Converter::toString(_data->getTime()) + " minutos"; 
}
