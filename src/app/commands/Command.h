#pragma once
#ifndef INCLUDED_COMMAND_H
#define INCLUDED_COMMAND_H

class UserInterface;
class ReportFactory;

class Command
{
public:
   virtual ~Command() {}
   virtual void execute(UserInterface* ui) = 0;
};

#endif
