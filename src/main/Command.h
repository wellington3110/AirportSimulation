#pragma once
#ifndef INCLUDED_COMMAND_H
#define INCLUDED_COMMAND_H

class Gui;
class ReportFactory;

class Command
{
public:
   virtual ~Command() {}
   virtual void execute(Gui* gui) = 0;
};

#endif
