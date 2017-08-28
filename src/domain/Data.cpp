#include "Data.h"

static Data* instance;

Data* Data::getInstance(int _onlyOneValue, DataType type)
{
   return getInstance(_onlyOneValue, _onlyOneValue, type);
}

Data* Data::getInstance(int _time, int _value, DataType type)
{
   if(instance)
      delete instance;
   instance= new Data(_time, _value, type);
   return instance;
}
