#pragma once
#ifndef INCLUDED_DATAREPORT_H
#define INCLUDED_DATAREPORT_H

class DataReport
{
public:
   ~DataReport();

   enum DataType {
      LANDED, PLANES_ON_LAND, PLANES_WAITING, WIND_CHANGES, WAITING_GREATER_THAN_5,
      PLANES_ON_LAND_EXCEEDED_CAPACITY, PLANES_SENT_ANOTHER_AIRPORT, REQUESTING_TAKE_OFF_GREATER_THAN_5
   };
   
   static void deleteDataInstance();
   static DataReport* createData(int _onlyOneValue, DataType type);
   static DataReport* createData(int _time, int _value, DataType type);
   

   int getTime(){ return time; }
   int getValue(){ return value; }
   DataType getType() { return type; }

private:
   DataReport(int _time, int _value, DataType _type) : value(_value), time(_time), type(_type){}
   DataReport(const DataReport&);

   int time;
   int value;
   DataType type;
   
};

#endif

