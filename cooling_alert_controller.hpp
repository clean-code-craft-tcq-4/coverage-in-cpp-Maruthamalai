#pragma once
#include "cooling_types.hpp"
#include "IAlert.hpp"

class ControllerAlert: public IAlert
{
   int m_header;
   BreachType m_breachType;

public:
   ControllerAlert(int header) :
         m_header(header),
         m_breachType(COOLING_STATUS_NORMAL)
   {}
   ControllerAlert()
   {}
   ~ControllerAlert()
   {}

   void SendAlertMsg(BreachType breachType);

   int getHeader()
   {
      return m_header;
   }

   BreachType getBreachType()
   {
      return m_breachType;
   }
};
