#include <Wire.h>
#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>

#define BUZZER_PIN 2
#define SENSOR_PIN 4

Adafruit_MPU6050 mpu;

void setup() {
  Serial.begin(9600);

  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(SENSOR_PIN, INPUT);

  // Active LOW buzzer: OFF initially
  digitalWrite(BUZZER_PIN, HIGH);

  // Initialize MPU6050
  if (!mpu.begin()) {
    Serial.println("Failed to find MPU6050 chip!");
    while (1);
  }

  Serial.println("MPU6050 initialized successfully.");

  // Configure MPU6050
  mpu.setAccelerometerRange(MPU6050_RANGE_8_G);
  mpu.setGyroRange(MPU6050_RANGE_500_DEG);
  mpu.setFilterBandwidth(MPU6050_BAND_21_HZ);
}

void loop() {
  sensors_event_t a, g, temp;

  // Read MPU6050 data
  mpu.getEvent(&a, &g, &temp);

  // Print accelerometer data
  Serial.print("Accel X: ");
  Serial.print(a.acceleration.x);

  Serial.print(" m/s², Y: ");
  Serial.print(a.acceleration.y);

  Serial.print(" m/s², Z: ");
  Serial.println(a.acceleration.z);

  // Read inductive sensor
  int sensorState = digitalRead(SENSOR_PIN);

  if (sensorState == HIGH) {
    Serial.println("Metal detected! Activating buzzer.");

    digitalWrite(BUZZER_PIN, LOW);
    delay(500);
    digitalWrite(BUZZER_PIN, HIGH);
  } else {
    digitalWrite(BUZZER_PIN, HIGH);
  }

  delay(100);
}
