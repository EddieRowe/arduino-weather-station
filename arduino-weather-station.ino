#include <dht11.h>
#include <dht.h>
#include <LiquidCrystal.h>
#include <math.h>

// Define data pin for temp/humidity sensor
#define DHT11PIN 7
#define DHT22PIN 8

// Create LCD & Sensor variables
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
dht11 DHT11;
dht DHT;

// Initialise LCD interface (columns, rows)
void  setup()
{
  lcd.begin(16, 2);
}

// Clear LCD and display new sensor readings every minute
void loop(){
  lcd.setCursor(0,0);

  int readData = DHT.read22(DHT22PIN);
  int t = round(DHT.temperature);
	int h = round(DHT.humidity);

  // DHT11.read() returns an int that could be used to detect errors.
  DHT11.read(DHT11PIN);
 
  lcd.print("I: ");
  lcd.print(DHT11.temperature);
  lcd.print((char)223);
  lcd.print("C, ");

  lcd.print(DHT11.humidity);
  lcd.print("%");

  lcd.setCursor(0,1);
  lcd.print("O: ");
  lcd.print(t);
  lcd.print((char)223);
  lcd.print("C, ");

  lcd.print(h);
  lcd.print("%");

  delay(60000);
  lcd.clear();
}
