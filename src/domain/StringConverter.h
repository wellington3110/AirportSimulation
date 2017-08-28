#pragma once
#include <string>
#include <sstream>

template <class V>class StringConverter
{
public:
   static std::string toString(V v);   
};

template <class V>
std::string StringConverter<V>::toString(V v)
{
   std::stringstream stream;
   stream << v;
   return stream.str();
}
