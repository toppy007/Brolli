#ifndef LED_CONTROL_H
#define LED_CONTROL_H

#include <Adafruit_NeoPixel.h>

void controlLEDs(Adafruit_NeoPixel& strip, int* index, int* hourlyData);

#endif