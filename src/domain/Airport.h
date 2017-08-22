#pragma once
#ifndef INCLUDED_AIRPORT_H
#define INCLUDED_AIRPORT_H

class Plane;

class Airport
{
public:
   bool verifyLandingRequest(Plane* plane);
};

#endif