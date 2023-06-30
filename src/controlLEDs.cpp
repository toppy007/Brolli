#include "LEDControl.h"

void controlLEDs(Adafruit_NeoPixel& strip, int* index, int* hourlyData) {
    if (*hourlyData > 95) {
        strip.setPixelColor(*index, 0, 250, 0);  // RED
    } else if (*hourlyData < 90) {
        strip.setPixelColor(*index, 250, 0, 0);  // Yellow
    }
}

