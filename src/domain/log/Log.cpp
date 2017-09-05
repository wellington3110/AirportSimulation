#include "Log.h"
#include "LogManipulator.h"

void Log::generateLog(LogType type, std::string varValue)
{
   if(isValidType(type))
      LogManipulator::getInstance()->addLog(messages[type], varValue);
   else
      throw std::runtime_error("Tipo de log inválido");
}

bool Log::isValidType(LogType type)
{
   for(std::map<LogType, std::string>::iterator iter= messages.begin()
      ; iter != messages.end(); ++iter) {
         if(iter->first == type)
            return true;
   }
   return false;
}
