#pragma once
#ifndef  INCLUDED_DATA_H
#define INCLUDED_DATA_H

class Data
{
public:
   ~Data();

   enum DataType {
      LANDED, PLANES_ON_LAND, PLANES_WAITING, WIND_CHANGES, WAITING_GREATER_THAN_5,
      PLANES_ON_LAND_EXCEEDED_CAPACITY, PLANES_SENT_ANOTHER_AIRPORT, REQUESTING_TAKE_OFF_GREATER_THAN_5
   };
   
   static void deleteDataInstance();
   static Data* createData(int _onlyOneValue, DataType type);
   static Data* createData(int _time, int _value, DataType type);
   

   int getTime(){ return time; }
   int getValue(){ return value; }
   DataType getType() { return type; }

private:
   Data(int _time, int _value, DataType _type) : value(_value), time(_time), type(_type){}
   Data(const Data&);

   int time;
   int value;
   DataType type;
   
};

#endif

