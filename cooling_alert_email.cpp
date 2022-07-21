#include "cooling_alert_email.hpp"

const string msgString[COOLING_STATUS_MAX + 1] = {
 "Hi, Temperature is normal"  ,
 "Hi, Temperature is too low" ,
 "Hi, Temperature is too high",
 "Hi, Temperature is invalid"
};

void EmailAlert::SendAlertMsg(BreachType breachType)
{
   if (breachType < COOLING_STATUS_MAX)
   {
      m_alertmsg.assign(msgString[breachType]);
   }
   else
   {
      m_alertmsg.assign(msgString[COOLING_STATUS_MAX]);
   }
}

