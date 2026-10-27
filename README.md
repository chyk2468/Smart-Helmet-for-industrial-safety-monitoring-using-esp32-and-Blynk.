# Smart Helmet for Safety Monitoring

****An ESP32-S3 IoT prototype for monitoring motion, gas, and temperature.****

[![GitHub](https://img.shields.io/badge/GitHub-Source-24292f?logo=github)](https://github.com/chyk2468/Smart-Helmet-for-industrial-safety-monitoring-using-esp32-and-Blynk.)

## 1. Project Title & Tagline

**An ESP32-S3 IoT prototype for monitoring motion, gas, and temperature.**

## 2. Problem Statement

**An ESP32-S3 IoT prototype for monitoring motion, gas, and temperature.** The helmet prototype reads an MPU9250/MPU6500 motion sensor, MQ-2 gas sensor, and DHT11 temperature sensor. It can sound a local buzzer and publish live status to a Blynk dashboard. **Hardware and software:** ESP32-S3, MPU9250/MPU6500, MQ-2, DHT11, buzzer, Arduino IDE, Blynk IoT

## 3. Project Preview

Add a real screenshot, GIF, or public demo here after recording the application.

[Open interactive architecture](architecture.html)

## 4. Overview

**An ESP32-S3 IoT prototype for monitoring motion, gas, and temperature.** The helmet prototype reads an MPU9250/MPU6500 motion sensor, MQ-2 gas sensor, and DHT11 temperature sensor. It can sound a local buzzer and publish live status to a Blynk dashboard. **Hardware and software:** ESP32-S3, MPU9250/MPU6500, MQ-2, DHT11, buzzer, Arduino IDE, Blynk IoT

## 5. Key Features

- Use the main project workflow.
- Review output before relying on it.

## 6. Architecture / Workflow

![Animated Smart Helmet for Safety Monitoring workflow](docs/readme-architecture.svg)

Moving markers show the direction of data flow. Open the [interactive architecture page](architecture.html) to select a stage.

1. Sensors collect motion, gas, and temperature readings.
2. The ESP32-S3 reads sensor values and checks configured thresholds.
3. The buzzer provides a local warning when a configured condition is triggered.
4. Blynk shows sensor values and alert states over Wi-Fi.

## 7. Tech Stack

**Hardware and software:** ESP32-S3, MPU9250/MPU6500, MQ-2, DHT11, buzzer, Arduino IDE, Blynk IoT

## 8. Installation & Setup

1. Install Arduino IDE and ESP32 board support.
2. Install the Blynk, DHT, and MPU9250 libraries used by the sketch.
3. Create a Blynk template for an ESP32 device and configure the dashboard widgets.
4. Open the project sketch under `src/`.
5. Set Wi-Fi and Blynk credentials locally, then upload to the board.

Do not commit Wi-Fi passwords or Blynk tokens.

## 9. Usage

1. Install Arduino IDE and ESP32 board support.
2. Install the Blynk, DHT, and MPU9250 libraries used by the sketch.
3. Create a Blynk template for an ESP32 device and configure the dashboard widgets.
4. Open the project sketch under `src/`.
5. Set Wi-Fi and Blynk credentials locally, then upload to the board.

Do not commit Wi-Fi passwords or Blynk tokens.

## 10. Project Structure

Start with the main application or notebook, then follow its imported modules.

## 11. Results & Demo

Add a reproducible evaluation, a real screenshot, and a short demo recording after running the project.

## 12. Future Enhancements

- Add tests for the main workflow.
- Improve validation and error handling.
- Record reproducible results.
- Add a short demo GIF.

## 13. License

Add a `LICENSE` file if you intend to grant reuse or redistribution permissions.
