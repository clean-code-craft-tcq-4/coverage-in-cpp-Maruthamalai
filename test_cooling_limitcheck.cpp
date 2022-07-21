//#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "string.h"
#include "test/catch.hpp"
#include "cooling_limitcheck.hpp"
#include "cooling_alert_email.hpp"
#include "cooling_alert_controller.hpp"

char printstring[100];
void printstub(char* ptr)
{
   memset(printstring, 0, sizeof(printstring));
   strcpy(printstring, ptr);
}

//----------------------------------------------------------------------------//
//---------------To Email------------------------------------------------//
// -----------------PASSIVE-----------------------------------------------------
EmailAlert emailAlert("abc@xyz");

ControllerAlert controllerAlert(0xff11);
CoolingLimit batCooling(emailAlert);

ControllerAlert controllerAlert(0x1234);
CoolingLimit batCooling(controllerAlert);


TEST_CASE("COOLING Passive, Alert to Email, Normal") {
   BatteryCharacter battery = {.coolingType = COOLING_PASSIVE, .brand = "ABC" };

  batCooling.checkAndAlert(TO_EMAIL, battery, 0);
  REQUIRE(emailAlert.getAlertMsg().compare("Hi, Temperature is normal") == 0);
}

TEST_CASE("COOLING Passive, Alert to Email, low") {
   BatteryCharacter battery = {.coolingType = COOLING_PASSIVE, .brand = "ABC" };

  batCooling.checkAndAlert(TO_EMAIL, battery, -1);
  REQUIRE(emailAlert.getAlertMsg().compare("Hi, Temperature is too low") == 0);
}

TEST_CASE("COOLING Passive, Alert to Email, high") {
   BatteryCharacter battery = {.coolingType = COOLING_PASSIVE, .brand = "ABC" };

   EmailAlert emailAlert("123@xyz");
   CoolingLimit batCooling(emailAlert);


  batCooling.checkAndAlert(TO_EMAIL, battery, 36);
  REQUIRE(emailAlert.getAlertMsg().compare("Hi, Temperature is too high") == 0);
}

// -----------------COOLING_HI_ACTIVE------------------------------------------
TEST_CASE("COOLING_HI_ACTIVE, Alert to Email, Normal") {
   BatteryCharacter battery = {.coolingType = COOLING_HI_ACTIVE, .brand = "ABC" };

  batCooling.checkAndAlert(TO_EMAIL, battery, 0);
  REQUIRE(emailAlert.getAlertMsg().compare("Hi, Temperature is normal") == 0);
}

TEST_CASE("COOLING_HI_ACTIVE, Alert to Email, low") {
   BatteryCharacter battery = {.coolingType = COOLING_HI_ACTIVE, .brand = "ABC" };

  batCooling.checkAndAlert(TO_EMAIL, battery, -1);
  REQUIRE(emailAlert.getAlertMsg().compare("Hi, Temperature is too low") == 0);
}

TEST_CASE("COOLING_HI_ACTIVE, Alert to Email, high") {
   BatteryCharacter battery = {.coolingType = COOLING_HI_ACTIVE, .brand = "ABC" };

  batCooling.checkAndAlert(TO_EMAIL, battery, 46);
  REQUIRE(emailAlert.getAlertMsg().compare("Hi, Temperature is too high") == 0);
}

// -----------------COOLING_MED_ACTIVE----------------------------------------
TEST_CASE("COOLING_MED_ACTIVE, Alert to Email, Normal") {
   BatteryCharacter battery = {.coolingType = COOLING_MED_ACTIVE, .brand = "ABC" };

  batCooling.checkAndAlert(TO_EMAIL, battery, 0);
  REQUIRE(emailAlert.getAlertMsg().compare("Hi, Temperature is normal") == 0);
}

TEST_CASE("COOLING_MED_ACTIVE, Alert to Email, low") {
   BatteryCharacter battery = {.coolingType = COOLING_MED_ACTIVE, .brand = "ABC" };

  batCooling.checkAndAlert(TO_EMAIL, battery, -1);
  REQUIRE(emailAlert.getAlertMsg().compare("Hi, Temperature is too low") == 0);
}

TEST_CASE("COOLING_MED_ACTIVE, Alert to Email, high") {
   BatteryCharacter battery = {.coolingType = COOLING_MED_ACTIVE, .brand = "ABC" };

  batCooling.checkAndAlert(TO_EMAIL, battery, 41);
  REQUIRE(emailAlert.getAlertMsg().compare("Hi, Temperature is too high") == 0);
}


//----------------------------------------------------------------------------//
//---------------To Controller------------------------------------------------//

// -----------------PASSIVE-----------------------------------------------------
BatteryCharacter battery = {.coolingType = COOLING_PASSIVE, .brand = "ABC" };

TEST_CASE("COOLING Passive, Alert to Controller, Normal") {

  batCooling.checkAndAlert(TO_CONTROLLER, battery, 0);
  REQUIRE(controllerAlert.getBreachType()== COOLING_STATUS_NORMAL);
}

TEST_CASE("COOLING Passive, Alert to Controller, low") {
  batCooling.checkAndAlert(TO_CONTROLLER, battery, -1);
  REQUIRE(controllerAlert.getBreachType()== COOLING_STATUS_TOO_LOW);
}

TEST_CASE("COOLING Passive, Alert to Controller, high") {

  batCooling.checkAndAlert(TO_CONTROLLER, battery, 36);
  REQUIRE(controllerAlert.getBreachType()== COOLING_STATUS_TOO_HIGH);
}

// -----------------COOLING_HI_ACTIVE-------------------------------------------
BatteryCharacter battery = {.coolingType = COOLING_HI_ACTIVE, .brand = "ABC" };

TEST_CASE("COOLING_HI_ACTIVE, Alert to Controller, Normal") {

  batCooling.checkAndAlert(TO_CONTROLLER, battery, 0);
  REQUIRE(controllerAlert.getBreachType()== COOLING_STATUS_NORMAL);
}

TEST_CASE("COOLING_HI_ACTIVE, Alert to Controller, low") {

  batCooling.checkAndAlert(TO_CONTROLLER, battery, -1);
  REQUIRE(controllerAlert.getBreachType()== COOLING_STATUS_TOO_LOW);
}

TEST_CASE("COOLING_HI_ACTIVE, Alert to Controller, high") {

  batCooling.checkAndAlert(TO_CONTROLLER, battery, 46);
  REQUIRE(controllerAlert.getBreachType()== COOLING_STATUS_TOO_HIGH);
}

// -----------------COOLING_MED_ACTIVE----------------------------------------
BatteryCharacter battery = {.coolingType = COOLING_MED_ACTIVE, .brand = "ABC" };

TEST_CASE("COOLING_MED_ACTIVE, Alert to Controller, Normal") {

  batCooling.checkAndAlert(TO_CONTROLLER, battery, 0);
  REQUIRE(controllerAlert.getBreachType()== COOLING_STATUS_NORMAL);
}

TEST_CASE("COOLING_MED_ACTIVE, Alert to Controller, low") {

  batCooling.checkAndAlert(TO_CONTROLLER, battery, -1);
  REQUIRE(controllerAlert.getBreachType()== COOLING_STATUS_TOO_LOW);
}

TEST_CASE("COOLING_MED_ACTIVE, Alert to Controller, high") {

  batCooling.checkAndAlert(TO_CONTROLLER, battery, 41);
  REQUIRE(controllerAlert.getBreachType()== COOLING_STATUS_TOO_HIGH);
}


