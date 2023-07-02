#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <ESP8266WiFiMulti.h>
#include <ESP8266HTTPClient.h>
#include <WiFiClient.h>
#include <ArduinoJson.h>
#include <Time.h>
#include <Adafruit_NeoPixel.h>
#include "LEDControl.h"

#define LED_PIN 4
#define LED_COUNT 24

// =====================================================
// ========= User configured stuff starts here =========

#define SSID "TOPPY"
#define SSID_PASSWORD "password"

// =========  User configured stuff ends here  =========
// =====================================================

Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800); //defines the strips properties

ESP8266WiFiMulti WiFiMulti;

void parsePrecipitationProbability(const char* jsonResponse) {
  StaticJsonDocument<2000> doc;
  DeserializationError error = deserializeJson(doc, jsonResponse);

  if (error) {
    Serial.print("Failed to parse JSON: ");
    Serial.println(error.c_str());
    return;
  }

  JsonArray precipitationArray = doc["hourly"]["precipitation_probability"];
  int arraySize = precipitationArray.size();

  for (int i = 0; i < arraySize; ++i) {
    int value = precipitationArray[i].as<int>();
    Serial.println(value);
    controlLEDs(strip, &i, &value);
    strip.show();
    delay(1000);
  }
}

void makeHttpRequest() {
  WiFiClient client;
  HTTPClient http;

  Serial.print("[HTTP] begin...\n");
  // configure server and URL(HARDCODED)
  http.begin(client, "http://api.open-meteo.com/v1/forecast?latitude=52.52&longitude=13.41&hourly=precipitation_probability&timezone=GMT&forecast_days=1");

  Serial.print("[HTTP] GET...\n");
  int httpCode = http.GET();
  if (httpCode > 0) {
    Serial.printf("[HTTP] GET... code: %d\n", httpCode);

    if (httpCode == HTTP_CODE_OK) {
      String payload = http.getString();
      Serial.println(payload);

      parsePrecipitationProbability(payload.c_str());
    }
  } else {
    Serial.printf("[HTTP] GET... failed, error: %s\n", http.errorToString(httpCode).c_str());
  }
  http.end();
}

void setup() {
  strip.begin();
  strip.show();  // Initialize all pixels to off

  Serial.begin(115200);

  while (WiFiMulti.run() != WL_CONNECTED) {
    WiFi.mode(WIFI_STA);
    WiFiMulti.addAP(SSID, SSID_PASSWORD);

    Serial.print(".");
    strip.setPixelColor(1, 0, 250, 250);
    strip.show();
  }
  
  Serial.println();
  Serial.println("Wi-Fi connected!");
  strip.clear();
}


void loop() {
  if (WiFiMulti.run() == WL_CONNECTED) {
    makeHttpRequest();
  }
  delay(200000);
}