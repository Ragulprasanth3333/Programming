Project: Bluetooth Temperature and Humidity Monitoring

Description:
This project is designed to monitor temperature and humidity using a DHT11 sensor and send the sensor data to a mobile phone via Bluetooth. The HC-05 Bluetooth module connects to the smartphone, and the data is displayed on the ArduBluetooth app.

Components:
1. Arduino Uno
2. HC-05 Bluetooth Module
3. DHT11 Temperature and Humidity Sensor
4. ArduBluetooth App (on smartphone)
5. Jumper wires

Wiring:
- **DHT11 Sensor**:
   - VCC -> 5V
   - GND -> GND
   - Data Pin -> Pin 2 of Arduino
- **HC-05 Bluetooth Module**:
   - VCC -> 5V
   - GND -> GND
   - RX -> Pin 10 of Arduino
   - TX -> Pin 11 of Arduino

Arduino Code:
The Arduino reads temperature and humidity data from the DHT11 sensor and sends this information via Bluetooth to a smartphone running the ArduBluetooth app. The data format is as follows:
- Temperature: XX °C
- Humidity: XX %

Setup Instructions:
1. Connect the DHT11 sensor and HC-05 Bluetooth module to the Arduino as described in the wiring section.
2. Upload the provided Arduino code to your Arduino Uno.
3. Pair the HC-05 Bluetooth module with your smartphone via Bluetooth settings.
4. Open the ArduBluetooth app on your smartphone and connect to the HC-05 module.
5. Once connected, the app will display real-time temperature and humidity data sent from the Arduino.

Features:
- Continuously sends temperature and humidity readings every 2 seconds.
- Allows monitoring of environmental conditions remotely using Bluetooth.
  
Commands:
No additional user commands are required. The data is automatically transmitted to the smartphone via Bluetooth.

Author: Ragul prasanth
