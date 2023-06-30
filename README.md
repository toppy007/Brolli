# Brolli

Neo-Pixel Umbrella Stand API Precipitation Forecaster 

# WEMOS D1 R1 PCB hat for Neopixel

![PCB](/public/images/PCB_Brolli.png)
![PCB Schematic preview](/public/images/PCB_schematic.png)

# Data 

Example API call and Data Response

https://api.open-meteo.com/v1/forecast?latitude=52.52&longitude=13.41&hourly=precipitation_probability&timezone=GMT&forecast_days=1

{"latitude":52.52,"longitude":13.419998,"generationtime_ms":0.3209114074707031,"utc_offset_seconds":0,"timezone":"GMT","timezone_abbreviation":"GMT","elevation":38.0,"hourly_units":{"time":"iso8601","precipitation_probability":"%"},"hourly":{"time":["2023-06-30T00:00","2023-06-30T01:00","2023-06-30T02:00","2023-06-30T03:00","2023-06-30T04:00","2023-06-30T05:00","2023-06-30T06:00","2023-06-30T07:00","2023-06-30T08:00","2023-06-30T09:00","2023-06-30T10:00","2023-06-30T11:00","2023-06-30T12:00","2023-06-30T13:00","2023-06-30T14:00","2023-06-30T15:00","2023-06-30T16:00","2023-06-30T17:00","2023-06-30T18:00","2023-06-30T19:00","2023-06-30T20:00","2023-06-30T21:00","2023-06-30T22:00","2023-06-30T23:00"],"precipitation_probability":[32,54,75,97,96,95,94,93,91,90,93,97,100,94,87,81,68,55,42,36,29,23,23,23]}}