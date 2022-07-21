//#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "test/catch.hpp"
#include "cooling_alert_controller.hpp"

TEST_CASE("Cooling status controller alert normal")
{
   ControllerAlert controllerAlert(0x1234);
   controllerAlert.SendAlertMsg(COOLING_STATUS_NORMAL);

   REQUIRE(controllerAlert.getHeader() == 0x1234);
   REQUIRE(controllerAlert.getBreachType() == COOLING_STATUS_NORMAL);
}

TEST_CASE("Cooling status controller alert high")
{
   ControllerAlert controllerAlert(0);
   controllerAlert.SendAlertMsg(COOLING_STATUS_TOO_HIGH);

   REQUIRE(controllerAlert.getHeader() == 0);
   REQUIRE(controllerAlert.getBreachType() == COOLING_STATUS_TOO_HIGH);
}

TEST_CASE("Cooling status controller alert low")
{
   ControllerAlert controllerAlert(5);
   controllerAlert.SendAlertMsg(COOLING_STATUS_TOO_LOW);

   REQUIRE(controllerAlert.getHeader() == 5);
   REQUIRE(controllerAlert.getBreachType() == COOLING_STATUS_TOO_LOW);
}

TEST_CASE("Cooling status controller alert invalid")
{
   ControllerAlert controllerAlert(7);
   controllerAlert.SendAlertMsg(COOLING_STATUS_MAX);

   REQUIRE(controllerAlert.getHeader() == 7);
   REQUIRE(controllerAlert.getBreachType() == COOLING_STATUS_MAX);
}

