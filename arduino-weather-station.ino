#include <dht11.h>
#include <LiquidCrystal.h>

// Define data pin for temp/humidity sensor
#define DHT11PIN 7

// Create LCD & Sensor variables
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
dht11 DHT11;

// Initialise LCD interface (columns, rows)
void  setup()
{
  lcd.begin(16, 2);
}

// Clear LCD and display new sensor readings every minute
void loop(){
  lcd.setCursor(0,0);

  // DHT11.read() returns an int that could be used to detect errors.
  DHT11.read(DHT11PIN);
 
  lcd.print("Temp: ");
  lcd.print(DHT11.temperature);
  lcd.print((char)223);
  lcd.print("C");

  lcd.setCursor(0,1);
  lcd.print("Humidity: ");
  lcd.print(DHT11.humidity);
  lcd.print("%");

  delay(60000);
  lcd.clear();
}
