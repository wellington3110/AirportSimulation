#pragma once
#ifndef INCLUDED_LANDEDREPORT_H
#define INCLUDED_LANDEDREPORT_H

#include "ReportSingleValueWithoutHistoric.h"

class LandedReport : public ReportSingleValueWithoutHistoric
{
public:
   LandedReport() : ReportSingleValueWithoutHistoric() {}
};

#endif
