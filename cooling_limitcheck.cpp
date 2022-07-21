#include "cooling_limitcheck.hpp"

const CoolingLimits coolingThresholds [COOLING_TYPE_MAX] =
{
    {PASSIVE_COOLING_LOWER_LIMIT, PASSIVE_COOLING_UPPER_LIMIT},
    {HI_ACTIVE_COOLING_LOWER_LIMIT, HI_ACTIVE_COOLING_UPPER_LIMIT},
    {MED_ACTIVE_COOLING_LOWER_LIMIT, MED_ACTIVE_COOLING_UPPER_LIMIT}
};

BreachType CoolingLimit::inferBreach(double value, double lowerLimit,
      double upperLimit)
{
   if (value < lowerLimit)
   {
      return COOLING_STATUS_TOO_LOW;
   }
   if (value > upperLimit)
   {
      return COOLING_STATUS_TOO_HIGH;
   }
   return COOLING_STATUS_NORMAL;
}

void CoolingLimit::checkAndAlert(BatteryCharacter batteryChar, double temperatureInC)
{
   BreachType breachType = inferBreach(temperatureInC,
         coolingThresholds[batteryChar.coolingType].lowerLimit,
         coolingThresholds[batteryChar.coolingType].upperLimit);

   m_alerter.SendAlertMsg(breachType);
}
