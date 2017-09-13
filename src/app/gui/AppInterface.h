#pragma once
#ifndef INCLUDED_APPINTERFACE_H
#define INCLUDED_APPINTERFACE_H


class AppInterface
{
public:
   virtual ~AppInterface() {}
   virtual void receiveOption(int option) = 0;

};

#endif //INCLUDED_APPINTERFACE_H