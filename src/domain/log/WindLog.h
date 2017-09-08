#pragma once
#ifndef INCLUDED_WINDLOG_H
#define INCLUDED_WINDLOG_H

#include "Log.h"

class WindLog : public Log
{
public:
   virtual ~WindLog() {}
   static Log* getInstance();

private:
   WindLog() { generateMessages(); }
   WindLog(const WindLog&);

protected:
   void generateMessages();

};

#endif

