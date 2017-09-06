#include "DataReport.h"

static DataReport* instance;

DataReport::~DataReport()
{
}

void DataReport::deleteDataInstance()
{
   if(instance)
      delete instance;
   instance= nullptr;
}

DataReport* DataReport::createData(int _onlyOneValue, DataType type)
{
   return createData(_onlyOneValue, _onlyOneValue, type);
}

DataReport* DataReport::createData(int _time, int _value, DataType type)
{
   if(instance)
      delete instance;
   instance= new DataReport(_time, _value, type);
   return instance;
}
