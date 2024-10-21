#include <Arduino.h>
#include <SoftwareSerial.h>
#include <DHT.h>

#define DHTPIN 2    // Pin where the DHT sensor is connected
#define DHTTYPE DHT11 // DHT11 or DHT22 sensor

DHT dht(DHTPIN, DHTTYPE);
SoftwareSerial bluetooth(10, 11); // RX = 10, TX = 11

void setup() {
  Serial.begin(9600);        // Begin serial communication with PC
  bluetooth.begin(9600);     // Begin serial communication with Bluetooth
  dht.begin();               // Initialize the DHT sensor
}

void loop() {
  float temp = dht.readTemperature();    // Read temperature in Celsius
  float humidity = dht.readHumidity();   // Read humidity

  if (isnan(temp) || isnan(humidity)) {  // Check if readings failed
    bluetooth.println("Failed to read from DHT sensor!");
    return;
  }

  bluetooth.print("Temperature: ");
  bluetooth.print(temp);
  bluetooth.print(" C");
  bluetooth.print("; ");

  bluetooth.print("Humidity: ");
  bluetooth.print(humidity);
  bluetooth.println(" %");

  delay(2000);  // Send data every 2 seconds
}
