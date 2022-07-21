#include "cooling_alert_controller.hpp"

void ControllerAlert::SendAlertMsg(BreachType breachType)
{
   m_breachType = breachType;
}
