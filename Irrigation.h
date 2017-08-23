/*
  Irritation.h
  Library for controling AC water pumps and humidity sensors using an arduino

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 3.0 of the License, or (at your option) any later version.
  See file LICENSE.txt for further informations on licensing terms.
*/

#ifndef Irrigation_h
#define Irrigation_h

#include "Arduino.h"

class Pump {
  private:
    int pinPump;
  public:
    void irrigate(int duration);
};

class HumSensor {
  private:
    int pinHumSensor;
    int lastReadingVal;
    unsigned long lastReadingTime;
  public:
    int checkCurrentHumidity();
    int checkLastReadingVal();
    unsigned long checkLastReadingTime();
};

#endif
