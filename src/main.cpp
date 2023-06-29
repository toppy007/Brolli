#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <ESP8266WiFiMulti.h>
#include <ESP8266HTTPClient.h>
#include <WiFiClient.h>
#include <JSON_Decoder.h>
#include <Time.h>
#include <Adafruit_NeoPixel.h>

#define LED_PIN D5
#define LED_COUNT 24

// =====================================================
// ========= User configured stuff starts here =========

#define SSID "TOPPY"
#define SSID_PASSWORD "top007196"

// =========  User configured stuff ends here  =========
// =====================================================

String LED[] = {"P0","P1","P2","P3","P4","P5","P6","P7","P8","P9","P10","P11","P12","P13","P14","P15","P16","P17","P18","P19","P20","P21","P22","P23"};
String LEDString  = "";

Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800); //defines the strips properties

ESP8266WiFiMulti WiFiMulti;

void makeHttpRequest() {
  WiFiClient client;
  HTTPClient http;

  Serial.print("[HTTP] begin...\n");
  // configure server and URL(HARDCODED)
  http.begin(client, "http://api.open-meteo.com/v1/forecast?latitude=51.51&longitude=-0.13&hourly=precipitation_probability");

  Serial.print("[HTTP] GET...\n");
  int httpCode = http.GET();
  if (httpCode > 0) {
    Serial.printf("[HTTP] GET... code: %d\n", httpCode);

    if (httpCode == HTTP_CODE_OK) {
      String payload = http.getString();
      Serial.println(payload);
    }
  } else {
    Serial.printf("[HTTP] GET... failed, error: %s\n", http.errorToString(httpCode).c_str());
  }
  http.end();
}

void setup() {
  Serial.begin(115200);
  // Serial.setDebugOutput(true);
  Serial.println();
  Serial.println();
  Serial.println();

  for (uint8_t t = 4; t > 0; t--) {
    Serial.printf("[SETUP] WAIT %d...\n", t);
    Serial.flush();
    delay(1000);
  }

  WiFi.mode(WIFI_STA);
  WiFiMulti.addAP(SSID, SSID_PASSWORD);
}

void loop() {
  if (WiFiMulti.run() == WL_CONNECTED) {
    makeHttpRequest();
  }

  delay(10000);
}
