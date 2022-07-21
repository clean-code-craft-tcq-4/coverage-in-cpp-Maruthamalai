#pragma once
#include "cooling_types.hpp"
#include "string"
using namespace std;

class IAlert
{
public:
   //virtual ~IAlert() = 0;
   virtual void SendAlertMsg(BreachType breachType) = 0;
};
