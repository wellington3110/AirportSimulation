#pragma once
#ifndef INCLUDED_APP_H
#define INCLUDED_APP_H

class Command;
class Gui;
class ReportFactory;
class Report;

class App
{
public:
   ~App();
   App();

   enum OPTIONS {LANDED= 1, ON_LAND, WAITING, WIND_HISTORIC, WAITING_GREATER_THAN_FIVE_HISTORIC,
      EXCEEDED_CAPACITY_HISTORIC, SENT_ANOTHER_AIRPORT_HISTORIC, TAKE_OFF_REQUESTS_GREATER_THAN_FIVE,
      CLS= 50, EXIT= 99};

   void run();

private:
   Gui* gui;
   ReportFactory* data;

   bool executeCmd(int option);
   Command* createCmd(int option);

   void startSimulator();
   
};

#endif

