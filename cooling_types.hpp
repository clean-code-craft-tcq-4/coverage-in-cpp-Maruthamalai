#pragma once
#include "string"
using namespace std;

typedef enum {
  COOLING_PASSIVE,
  COOLING_HI_ACTIVE,
  COOLING_MED_ACTIVE,
  COOLING_TYPE_MAX
} CoolingType;

typedef enum {
  COOLING_STATUS_NORMAL,
  COOLING_STATUS_TOO_LOW,
  COOLING_STATUS_TOO_HIGH,
  COOLING_STATUS_MAX
} BreachType;

typedef enum {
  TO_CONTROLLER,
  TO_EMAIL
} AlertTarget;

typedef struct {
  CoolingType coolingType;
  string brand;
} BatteryCharacter;

