#pragma once
#ifndef INCLUDED_LOGMANIPULATOR_H
#define INCLUDED_LOGMANIPULATOR_H

#include <vector>

class LogManipulator
{
public:
   static LogManipulator* getInstance();
   std::string getLogs();

   void addLog(std::string log, std::string varValue);

private:
   LogManipulator() {}
   LogManipulator(const LogManipulator&);

   std::vector<std::string> allLogs;
   std::vector<std::string> unreadLogs;
   
};

#endif

