#pragma once

#include "cooling_types.hpp"
#include "IAlert.hpp"

#define PASSIVE_COOLING_LOWER_LIMIT          0
#define PASSIVE_COOLING_UPPER_LIMIT          35

#define HI_ACTIVE_COOLING_LOWER_LIMIT        0
#define HI_ACTIVE_COOLING_UPPER_LIMIT        45

#define MED_ACTIVE_COOLING_LOWER_LIMIT       0
#define MED_ACTIVE_COOLING_UPPER_LIMIT       40

typedef struct
{
   float lowerLimit;
   float upperLimit;
} CoolingLimits;

class CoolingLimit
{
   IAlert &m_alerter;

   BreachType inferBreach(double value, double lowerLimit, double upperLimit);
public:
   void checkAndAlert(BatteryCharacter batteryChar,
         double temperatureInC);
   CoolingLimit(IAlert &alerter) : m_alerter(alerter)
   {}
   ~CoolingLimit()
   {

   }
};

