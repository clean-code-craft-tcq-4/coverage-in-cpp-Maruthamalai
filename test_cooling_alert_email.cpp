
#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "test/catch.hpp"
#include "cooling_alert_email.hpp"

TEST_CASE("Cooling status email alert normal") {
   EmailAlert emailAlert("abc@xyz");

   emailAlert.SendAlertMsg(COOLING_STATUS_NORMAL);

   REQUIRE(emailAlert.getMailReceipient().compare("abc@xyz") == 0);
   REQUIRE(emailAlert.getAlertMsg().compare("Hi, Temperature is normal") == 0);
}

TEST_CASE("Cooling status email alert low") {
   EmailAlert emailAlert("");

   emailAlert.SendAlertMsg(COOLING_STATUS_TOO_LOW);

   REQUIRE(emailAlert.getMailReceipient().compare("") == 0);
   REQUIRE(emailAlert.getAlertMsg().compare("Hi, Temperature is too low") == 0);
}

TEST_CASE("Cooling status email alert high") {
   EmailAlert emailAlert("a@xyz.com");

   emailAlert.SendAlertMsg(COOLING_STATUS_TOO_HIGH);

   REQUIRE(emailAlert.getMailReceipient().compare("a@xyz.com") == 0);
   REQUIRE(emailAlert.getAlertMsg().compare("Hi, Temperature is too high") == 0);
}

TEST_CASE("Cooling status email alert invalid") {
   EmailAlert emailAlert("a@xyz.com");

   emailAlert.SendAlertMsg(COOLING_STATUS_MAX);

   REQUIRE(emailAlert.getMailReceipient().compare("a@xyz.com") == 0);
   REQUIRE(emailAlert.getAlertMsg().compare("Hi, Temperature is invalid") == 0);
}
