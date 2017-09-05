#include "LogManipulator.h"

static LogManipulator* instance;
const std::string variable= "[x]";
typedef std::vector<std::string>::iterator iterator;


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
      log+= "/n";
   }
   unreadLogs.clear();
   return log;
}

void LogManipulator::addLog(std::string log, std::string varValue)
{
   log.replace( log.find(variable), variable.size(), varValue );   
   unreadLogs.push_back(log);
   allLogs.push_back(log);
}


