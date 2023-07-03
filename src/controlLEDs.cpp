#include "LEDControl.h"

void controlLEDs(Adafruit_NeoPixel& strip, int* index, int* hourlyData) {
    if (*hourlyData > 95) {
        strip.setPixelColor(*index, 250, 250, 250);  // 
    } else if (*hourlyData < 90) {
        strip.setPixelColor(*index, 250, 250, 250);  // Yellow
    } else if (*hourlyData < 85) {
        strip.setPixelColor(*index, 250, 250, 250);  // Yellow
    } else if (*hourlyData < 80) {
        strip.setPixelColor(*index, 250, 250, 250);  // Yellow
    } else if (*hourlyData < 75) {
        strip.setPixelColor(*index, 250, 250, 250);  // Yellow
    } else if (*hourlyData < 70) {
        strip.setPixelColor(*index, 250, 250, 250);  // Yellow
    } else if (*hourlyData < 65) {
        strip.setPixelColor(*index, 250, 250, 250);  // Yellow
    } else if (*hourlyData < 60) {
        strip.setPixelColor(*index, 250, 250, 250);  // Yellow
    } else if (*hourlyData < 55) {
        strip.setPixelColor(*index, 250, 250, 250);  // Yellow
    } else if (*hourlyData < 50) {
        strip.setPixelColor(*index, 250, 250, 250);  // Yellow
    } else if (*hourlyData < 45) {
        strip.setPixelColor(*index, 250, 250, 250);  // Yellow
    } else if (*hourlyData < 40) {
        strip.setPixelColor(*index, 250, 250, 250);  // Yellow
    } else if (*hourlyData < 35) {
        strip.setPixelColor(*index, 250, 250, 250);  // Yellow
    } else if (*hourlyData < 30) {
        strip.setPixelColor(*index, 250, 250, 250);  // Yellow
    } else if (*hourlyData < 25) {
        strip.setPixelColor(*index, 250, 250, 250);  // Yellow
    } else if (*hourlyData < 20) {
        strip.setPixelColor(*index, 250, 250, 250);  // Yellow
    } else if (*hourlyData < 15) {
        strip.setPixelColor(*index, 250, 250, 250);  // Yellow
    } else if (*hourlyData < 10) {
        strip.setPixelColor(*index, 250, 250, 250);  // Yellow
    } else if (*hourlyData < 5) {
        strip.setPixelColor(*index, 250, 250, 250);  // Yellow
}

