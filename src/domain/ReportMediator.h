#pragma once
#include "Mediator.h"
#include "Data.h"

class ReportMediator : public Mediator
{
public:
   static Mediator* getInstance();

   void receive(Data* data) { send(data); }

private:
   ReportMediator(){}
   ReportMediator(const ReportMediator&);

   void send(Data* data);
};
