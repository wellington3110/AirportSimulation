#include "Data.h"

static Data* instance;

Data::~Data()
{
}

void Data::deleteData()
{
   if(instance)
      delete instance;
   instance= nullptr;
}

Data* Data::createData(int _onlyOneValue, DataType type)
{
   return createData(_onlyOneValue, _onlyOneValue, type);
}

Data* Data::createData(int _time, int _value, DataType type)
{
   if(instance)
      delete instance;
   instance= new Data(_time, _value, type);
   return instance;
}
