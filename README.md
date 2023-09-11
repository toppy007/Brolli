# Brolli

Neo-Pixel Umbrella Stand API Precipitation Forecaster 

## Weather Forecast LED Indicator
This Arduino program utilizes an ESP8266 module, NeoPixel LED strip, and Wi-Fi connectivity to provide a visual indication of hourly precipitation probability for a specific location. It fetches weather forecast data from the Open Meteo API and uses NeoPixel LEDs to display the information.

## Components Used
#### ESP8266 Module: 
The program is designed to work with an ESP8266-based microcontroller, such as the NodeMCU or Wemos D1 Mini.

#### NeoPixel LED Strip: 
An Adafruit NeoPixel LED strip with a defined number of LEDs (LED_COUNT) is used to display the precipitation probability.

## User Configuration
Before uploading the program, the user must configure the following settings in the code:

#### Wi-Fi Configuration: 
Set your Wi-Fi network name (SSID) and password (SSID_PASSWORD) to enable the ESP8266 to connect to the internet.

#### LED Configuration: 
Specify the pin number (LED_PIN) and the total number of LEDs in your NeoPixel strip (LED_COUNT).

## Program Overview
The program establishes a Wi-Fi connection using the provided credentials.

It continuously makes HTTP requests to the Open Meteo API to fetch weather forecast data for a specific location (latitude and longitude).

The program then parses the JSON response from the API to extract the hourly precipitation probability data.

For each hour in the forecast, the precipitation probability is displayed using NeoPixel LEDs. The LED color and intensity represent the probability, with higher probabilities resulting in brighter or differently colored LEDs.

The LED strip is updated every hour with the new precipitation data.

The program runs in a loop, continuously updating the LED display with the latest forecast data.

## LED Display

The NeoPixel LED strip is controlled by the controlLEDs function, which maps the precipitation probability to LED colors and brightness levels. This function is called for each hour in the forecast.

The LEDs provide a visual indication of the precipitation probability, making it easy to glance at the weather forecast at a glance.

# WEMOS D1 R1 PCB hat for Neopixel

![PCB](/public/images/PCB_Brolli.png)
![PCB Schematic preview](/public/images/PCB_schematic.png)

# Data 

Example API call and Data Response

https://api.open-meteo.com/v1/forecast?latitude=52.52&longitude=13.41&hourly=precipitation_probability&timezone=GMT&forecast_days=1

{"latitude":52.52,"longitude":13.419998,"generationtime_ms":0.3209114074707031,"utc_offset_seconds":0,"timezone":"GMT","timezone_abbreviation":"GMT","elevation":38.0,"hourly_units":{"time":"iso8601","precipitation_probability":"%"},"hourly":{"time":["2023-06-30T00:00","2023-06-30T01:00","2023-06-30T02:00","2023-06-30T03:00","2023-06-30T04:00","2023-06-30T05:00","2023-06-30T06:00","2023-06-30T07:00","2023-06-30T08:00","2023-06-30T09:00","2023-06-30T10:00","2023-06-30T11:00","2023-06-30T12:00","2023-06-30T13:00","2023-06-30T14:00","2023-06-30T15:00","2023-06-30T16:00","2023-06-30T17:00","2023-06-30T18:00","2023-06-30T19:00","2023-06-30T20:00","2023-06-30T21:00","2023-06-30T22:00","2023-06-30T23:00"],"precipitation_probability":[32,54,75,97,96,95,94,93,91,90,93,97,100,94,87,81,68,55,42,36,29,23,23,23]}}