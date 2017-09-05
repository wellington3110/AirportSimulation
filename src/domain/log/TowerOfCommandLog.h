#pragma once
#ifndef INCLUDED_TOWEROFCOMMANDLOG_H
#define INCLUDED_TOWEROFCOMMANDLOG_H

#include "Log.h"

class TowerOfCommandLog : public Log
{
public:
   ~TowerOfCommandLog(){}

   static Log* getInstance();

private:
   TowerOfCommandLog() {}
   TowerOfCommandLog(const TowerOfCommandLog&);

protected:
   void generateMessages();
};

#endif
