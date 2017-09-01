#pragma once
#ifndef INCLUDED_REPORTMEDIATOR_H
#define INCLUDED_REPORTMEDIATOR_H

#include "Mediator.h"

class ReportMediator : public Mediator
{
public:
   ~ReportMediator();
   static void deleteInstance();
   static Mediator* getInstance();
   
   void receive(Data* data) { send(data); }

private:
   ReportMediator(){}
   ReportMediator(const ReportMediator&);

   void send(Data* data);
};

#endif

