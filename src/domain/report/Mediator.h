#ifndef INCLUDED_MEDIATOR_H
#define INCLUDED_MEDIATOR_H

class Data;

class Mediator
{
public:
   virtual ~Mediator(){}
   virtual void receive(Data* data) = 0;
};


#endif
