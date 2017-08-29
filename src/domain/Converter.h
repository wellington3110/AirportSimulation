#pragma once
#include <string>

class Converter
{
public:
   static std::string toString(int value);
   static void addAZero(std::stringstream& stream, int hora);
   static std::string toTimeFormat(int time);
};

