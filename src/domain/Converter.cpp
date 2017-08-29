#include "Converter.h"
#include <sstream>

std::string Converter::toString(int value)
{
   std::stringstream stream;
   stream << value;
   return stream.str();
}

void Converter::addAZero(std::stringstream& stream, int tempo)
{
   if(tempo < 10)
      stream <<"0";
   stream << tempo;
}

std::string Converter::toTimeFormat(int time)
{
   std::stringstream stream;
   int dia= time/1440;
   int hora= (time/60) - dia * 24;
   int minuto= time % 60;

   stream << "Dia: " << dia + 1 << " | Tempo: ";
   addAZero(stream, hora);
   stream << ":";
   addAZero(stream, minuto);
   
   return stream.str();
}
