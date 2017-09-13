#include "LogManipulator.h"
#include "Converter.h"
#include "Timer.h"

static LogManipulator* instance;
const std::string variable= "[x]";
typedef std::vector<std::string>::iterator iterator;

bool hasVariable(std::string log)
{
   int x= log.find(variable);
   return x > 0;
}

void replaceVariable(std::string& log, std::string& varValue)
{
   log.replace( log.find(variable), variable.size(), varValue );      
}

LogManipulator* LogManipulator::getInstance()
{
   if(!instance)
      instance= new LogManipulator;
   return instance;
}

std::string LogManipulator::getLogs()
{
   std::string log;
   for (iterator iter= unreadLogs.begin(); iter != unreadLogs.end(); ++iter ) {
      log+= *iter;
      log+= "\n";
   }
   unreadLogs.clear();
   return log;
}

void addTimeInFrontOfTheLog(std::string& log)
{
   log.insert(0, " Data: " + Converter::toTimeFormat(Timer::getInstance()->getActualTime()) + " | ");
}

void LogManipulator::addLog(std::string log, std::string varValue)
{
   if(hasVariable(log))
      replaceVariable(log, varValue);
   addTimeInFrontOfTheLog(log);
   unreadLogs.push_back(log);
   allLogs.push_back(log);
}




