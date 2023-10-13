#include <dht11.h>
#include <dht.h>
#include <LiquidCrystal.h>
#include <math.h>
#include <SPI.h>
#include <SD.h>
#include <Wire.h>
#include <RTClib.h>

// Define data pin for temp/humidity sensor
#define DHT11PIN 7
#define DHT22PIN 8

// Create LCD & Sensor variables
LiquidCrystal lcd(6, 9, 5, 4, 3, 2);
dht11 DHT11;
dht DHT;
File myFile;
RTC_DS1307 rtc;

// Initialise LCD interface (columns, rows)
void  setup()
{
  lcd.begin(16, 2);
  lcd.setCursor(0,0);

  if (! rtc.begin()){
    lcd.print("Couldn't find RTC!");
    while (1);
  }

  if (!rtc.isrunning()) 
  {
    lcd.print("RTC is NOT running!");
  }

  rtc.adjust(DateTime(F(__DATE__), F(__TIME__))); // set time from PC time

  // if (!SD.begin()) {
  //   lcd.setCursor(0,0);
  //   lcd.print("SD failed");
  //   while (1);
  // }

  // myFile = SD.open("temp_humid.txt", FILE_WRITE);

  // if (myFile) {
  //   myFile.println("2023-10-12_16-40");
  //   myFile.close();
  // } else {
  //   lcd.clear();
  //   lcd.setCursor(0,0);
  //   lcd.print("Failed to open file");
  // }
}

  // Show date on top, IN temp bottom for 10s
  // Show time on top OUT temp bottom for 10s
  //repeat 3x then update data
void loop(){

  int repeats = 0;
  DateTime now = rtc.now();
  String hourString = "";
  if(now.hour() < 10){
    hourString = "0";
  }
  hourString += String(now.hour());

  String minString = "";
  if(now.minute() < 10){
    minString = "0";
  }
  minString += String(now.minute());

  int readData = DHT.read22(DHT22PIN);
  int t = round(DHT.temperature);
	int h = round(DHT.humidity);
  DHT11.read(DHT11PIN);

  while(repeats < 3){
    lcd.setCursor(0, 0);
    lcd.clear();
    lcd.print(now.year());
    lcd.print("-");
    lcd.print(now.month());
    lcd.print("-");
    lcd.print(now.day());
    lcd.print(" ");
    lcd.print(hourString);
    lcd.print(':');
    lcd.print(minString);

    lcd.setCursor(0, 1);
    lcd.print("In:  ");
    lcd.print(DHT11.temperature);
    lcd.print((char)223);
    lcd.print("C ");
    lcd.print(DHT11.humidity);
    lcd.print("%");

    delay(10000);

    lcd.setCursor(0, 1);
    lcd.print("                "); //clearline
    lcd.setCursor(0, 1);
    lcd.print("Out: ");
    lcd.print(t);
    lcd.print((char)223);
    lcd.print("C ");
    lcd.print(h);
    lcd.print("%");

    delay(10000);

    repeats++;
  }
  // record data
  // myFile = SD.open("temp_humid.txt", FILE_WRITE);

  // if (myFile) {
  //   myFile.println(String(DHT.temperature) + ", " + String(DHT.humidity) + ", " 
  //   + String(DHT11.temperature) + ", " + String(DHT11.humidity));
  //   myFile.close();
  // } else {
  //   lcd.clear();
  //   lcd.setCursor(0,0);
  //   lcd.print("Failed to open file");
  // }

//////////////////////
  // delay(60000);
  // lcd.clear();
  // lcd.setCursor(0,0);
}
