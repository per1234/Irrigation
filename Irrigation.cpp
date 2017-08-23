/*
  Irritation.cpp
  Library for controling AC water pumps and humidity sensors using an arduino

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 3.0 of the License, or (at your option) any later version.
  See file LICENSE.txt for further informations on licensing terms.
*/

#include <arduino.h>
#include "Irrigation.h"

/** Pump funtions **/
void Pump::Pump(int pin){
  pinMode(pin, OUTPUT);
  pinPump = pin;
}

void Pump::irrigate(int duration){
  unsigned long currTime = millis();
  digitalWrite(pinPump, HIGH);
  while (millis() - currTime < duration) {
    // This loop will last the duration value
  }
  digitalWrite(pinPump, LOW);
}

/** Humidity sensor functions **/
void HumSensor::HumSensor(int pin){
  pinMode(pin, INPUT);
  pinHumSensor = pin;
  lastReadingVal = analogRead(pinHumSensor);
  lastReadingTime = millis();
}

int HumSensor::checkCurrentHumidity(){
  lastReadingVal = analogRead(pinHumSensor);
  lastReadingTime = millis();
  return lastReadingVal;
}

int HumSensor::checkLastReadingVal(){
  return lastReadingVal;
}

unsigned long HumSensor::checkLastReadingTime(){
  return lastReadingTime;
}
