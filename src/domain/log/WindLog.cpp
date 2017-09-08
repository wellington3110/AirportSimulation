#include "WindLog.h"

static Log* instance; 

Log* WindLog::getInstance()
{
   if (!instance)
      instance= new WindLog;
   return instance;
}

void WindLog::generateMessages()
{
   messages[WIND_DIRECTION]= "Wind log: Direção do vento mudou";
}
