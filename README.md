# 🪖 Smart Helmet with IoT (ESP32-S3 + Blynk)

## 1. Project Overview

A Smart Helmet system that improves rider safety by detecting:

* 🚨 Sudden motion/accident (MPU9250/6500)
* 🌫️ Harmful gases (MQ2)
* 🌡️ High temperature (DHT11)
* 🔔 Alerts via buzzer + mobile app (Blynk)

---

## 2. Features

* Accident detection with accelerometer & gyroscope
* Gas/smoke detection for hazardous environments
* Overheat warning (Temp > 50°C)
* Real-time monitoring on Blynk app
* Buzzer for local alert
* Wi-Fi enabled ESP32-S3

---

## 3. Hardware Requirements

* ESP32-S3 Dev Board
* MPU9250 / MPU6500
* MQ2 Gas Sensor
* DHT11 Sensor
* Buzzer
* Breadboard + Jumper Wires
* Powerbank (optional)

---

## 4. Software Requirements

* Arduino IDE
* Blynk IoT App
* ESP32 Board support in Arduino IDE
* Libraries:

  * BlynkSimpleEsp32
  * WiFi.h
  * Wire.h
  * MPU9250_asukiaaa
  * DHT.h

---

## 5. Installation & Setup

### Arduino IDE

1. Download and install [Arduino IDE](https://www.arduino.cc/en/software)
2. Add ESP32 Board URL in Preferences:

   ```
   https://raw.githubusercontent.com/espressif/arduino-esp32/gh-pages/package_esp32_index.json
   ```
3. Go to Board Manager → Install ESP32

### Libraries

Install via **Sketch → Include Library → Manage Libraries**:

* Blynk
* DHT sensor library
* MPU9250_asukiaaa

---

## 6. ESP32 Port Connections

| Component   | ESP32-S3 Pin | Notes                   |
| ----------- | ------------ | ----------------------- |
| MPU9250 SDA | GPIO 20      | I²C Data                |
| MPU9250 SCL | GPIO 21      | I²C Clock               |
| MQ2 AO      | GPIO 5       | Analog Input            |
| DHT11 Data  | GPIO 4       | Pull-up resistor needed |
| Buzzer +    | GPIO 12      | Digital Output          |
| 3.3V Power  | 3.3V         | All VCC                 |
| GND         | GND          | Common ground           |

---

## 7. Blynk Setup

1. Download Blynk IoT App
2. Create a Template:

   * Name: Helmet Sensor
   * Hardware: ESP32
   * Connection: WiFi
3. Add Widgets to Dashboard:

   * LED, Gauge for each sensor & alerts
4. Copy **Template ID, Name, and Auth Token** into Arduino code

---

## 8. Uploading Code

1. Open `helmet_sensor.ino` in Arduino IDE
2. Replace WiFi and Blynk credentials:

   ```cpp
   char ssid[] = "YourWiFiSSID";
   char pass[] = "YourWiFiPassword";
   #define BLYNK_AUTH_TOKEN "YourAuthToken"
   ```
3. Select **Board → ESP32-S3 Dev Module**
4. Select **Port → COM Port**
5. Click **Upload**
6. Open Serial Monitor at 115200 baud to verify

---

## 9. Working / Output

* Sensors constantly monitor helmet conditions
* Alerts if:

  * Acceleration/Gyro exceeds threshold → Motion Alert
  * MQ2 > threshold → Gas Alert
  * Temp > threshold → Temp Alert
* Blynk dashboard shows live readings + alert LEDs
* Buzzer sounds for local warnings

---

## 10. Future Improvements

* GPS + SMS alerts
* Cloud data logging
* AI accident prediction
* Compact PCB for helmet fitting

---

## 11. Authors

* **Yashwant Kumar Chitchula** – Project Development

---
