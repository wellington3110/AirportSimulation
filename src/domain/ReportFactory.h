#pragma once
#ifndef INCLUDED_REPORTFACTORY_H
#define INCLUDED_REPORTFACTORY_H

#include "Data.h"

class Report;

class ReportFactory
{

public:
   ~ReportFactory();

   static ReportFactory* getInstance();
   Report* retrieveReport(Data::DataType type);
   
private:
   ReportFactory();
   ReportFactory(const ReportFactory&);
};

#endif

