# arduino-weather-station
![GitHub](https://img.shields.io/github/license/EddieRowe/arduino-weather-station)
![GitHub code size in bytes](https://img.shields.io/github/languages/code-size/EddieRowe/arduino-weather-station)

## A simple Arduino-based weather station.

### Description

This is a simple Arduino project that uses a DHT11 sensor to monitor temperature and humidity, and an LCD to display the information.
I currently have mine setup next to a window, with the sensor outside. This way I can see the outside temperature and humidity.

In future I plan to add another sensor for indoor conditions, and possibly upgrade to DHT22 sensors for greater precision and range.

### Requirements

- An Arduino, I used an Arduino UNO, but most others should work fine. (£15-£20)
- A DHT11 sensor. (<£2)
- A 16x2 LCD. (<£6)
- A breadboard and wires! (<£2)

### Instructions to use

- Clone this repo or download the arduino-weather-station.ino sketch file.
- Open the arduino-weather-station.ino sketch file in the [Arduino IDE](https://www.arduino.cc/en/software).
- You'll need to add the [LiquidCrystal](https://www.arduino.cc/reference/en/libraries/liquidcrystal/) and [DHT11](https://playground.arduino.cc/Main/DHT11Lib/) libraries.
- Using the breadboard, wire together your Arduino of choice with the DHT11 sensor and LCD.
- Modify line 5 of the sketch file to change the DHT11PIN value from 7 to whatever data pin you used.
- Similarly, modify line 8 of the sketch file to set your LCD pins.
- Upload the sketch to your Arduino and enjoy!
