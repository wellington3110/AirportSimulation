#pragma once
#ifndef INCLUDED_REPORTMEDIATOR_H
#define INCLUDED_REPORTMEDIATOR_H

#include "Mediator.h"

class DataMediator : public Mediator
{
public:
   ~DataMediator();
   static void deleteInstance();
   static Mediator* getInstance();
   
   void receive(Data* data) { send(data); }

private:
   DataMediator(){}
   DataMediator(const DataMediator&);

   void send(Data* data);
};

#endif

