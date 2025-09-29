// ---------------- BLYNK TEMPLATE DEFINITIONS ----------------
#define BLYNK_TEMPLATE_ID "TMPL3............."
#define BLYNK_TEMPLATE_NAME "Helmat sensor"
#define BLYNK_AUTH_TOKEN "oFrm..........."

// ---------------- INCLUDE LIBRARIES ----------------
#include <WiFi.h>                     // ESP32 Wi-Fi
#include <BlynkSimpleEsp32.h>         // Blynk for ESP32
#include <Wire.h>                     // I2C
#include <MPU9250_asukiaaa.h>         // MPU9250
#include <math.h>
#include "DHT.h"                      // DHT sensor

// ---------------- WIFI CREDENTIALS ----------------
char ssid[] = "........";       // Wi-Fi SSID
char pass[] = ".........";    // Wi-Fi password

// ---------------- PIN DEFINITIONS ----------------
#define SDA_PIN 20
#define SCL_PIN 21
#define BUZZER_PIN 12
#define MQ2_PIN 5
#define DHT_PIN 4
#define DHT_TYPE DHT11

// ---------------- OBJECTS ----------------
MPU9250_asukiaaa mpu;
DHT dht(DHT_PIN, DHT_TYPE);

// ---------------- THRESHOLDS ----------------
const float HIT_THRESHOLD_ACCEL = 2.0;  
const float HIT_THRESHOLD_GYRO  = 200.0;
const int   MQ2_THRESHOLD       = 400;
const float TEMP_THRESHOLD      = 50.0;

void setup() {
  Serial.begin(115200);

  // ---------------- WIFI ----------------
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, pass);
  Serial.print("Connecting to Wi-Fi");
  int attempts = 0;
  while (WiFi.status() != WL_CONNECTED && attempts < 20) {
    delay(500);
    Serial.print(".");
    attempts++;
  }
  if(WiFi.status() == WL_CONNECTED){
    Serial.println("\nWi-Fi connected!");
    Serial.print("IP address: "); Serial.println(WiFi.localIP());
  } else {
    Serial.println("\nFailed to connect to Wi-Fi!");
  }

  // ---------------- SENSORS ----------------
  Wire.begin(SDA_PIN, SCL_PIN);

  mpu.setWire(&Wire);
  mpu.beginAccel();
  mpu.beginGyro();

  dht.begin();

  pinMode(BUZZER_PIN, OUTPUT);
  digitalWrite(BUZZER_PIN, LOW);

  pinMode(MQ2_PIN, INPUT);

  // ---------------- BLYNK ----------------
  if(WiFi.status() == WL_CONNECTED){
    Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
  }

  Serial.println("System Initialized: MPU9250 + MQ2 + DHT11 + Blynk");
}

void loop() {
  Blynk.run();

  bool alertMotion = false;
  bool alertGas = false;
  bool alertTemp = false;

  // -------- MPU9250 --------
  mpu.accelUpdate();
  mpu.gyroUpdate();

  float totalAccel = sqrt(sq(mpu.accelX()) + sq(mpu.accelY()) + sq(mpu.accelZ()));
  float totalGyro  = sqrt(sq(mpu.gyroX()) + sq(mpu.gyroY()) + sq(mpu.gyroZ()));

  if(totalAccel > HIT_THRESHOLD_ACCEL || totalGyro > HIT_THRESHOLD_GYRO){
    alertMotion = true;
  }

  // -------- MQ2 --------
  int mq2Value = analogRead(MQ2_PIN);
  if(mq2Value > MQ2_THRESHOLD){
    alertGas = true;
  }

  // -------- DHT11 --------
  float temperature = dht.readTemperature();
  float humidity    = dht.readHumidity();

  if(isnan(temperature) || isnan(humidity)){
    delay(2000);
    temperature = dht.readTemperature();
    humidity    = dht.readHumidity();
  }

  if(!isnan(temperature) && temperature > TEMP_THRESHOLD){
    alertTemp = true;
  }

  // -------- BUZZER --------
  bool overallAlert = alertMotion || alertGas || alertTemp;
  if(overallAlert){
    digitalWrite(BUZZER_PIN, HIGH);
    delay(5000);
    digitalWrite(BUZZER_PIN, LOW);
  }

  // -------- SEND DATA TO BLYNK --------
  Blynk.virtualWrite(V0, overallAlert ? 1 : 0);  // Overall Alert
  Blynk.virtualWrite(V1, totalAccel);
  Blynk.virtualWrite(V2, totalGyro);
  Blynk.virtualWrite(V3, alertMotion ? 1 : 0);
  Blynk.virtualWrite(V4, mq2Value);
  Blynk.virtualWrite(V5, alertGas ? 1 : 0);
  Blynk.virtualWrite(V6, temperature);
  Blynk.virtualWrite(V7, humidity);
  Blynk.virtualWrite(V8, alertTemp ? 1 : 0);

  delay(2000);
}