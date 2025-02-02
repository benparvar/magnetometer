#include <Wire.h>

#define ADDRESS_HMC5883 0x0D // Encontrado na listagem do i2c
#define SDA_SENSOR 21
#define SCL_SENSOR 22

bool isSensorAvailable = false;

void configureSensor() {
  Serial.println("configureSensor");
  Wire.begin();

}

void configureLCD() {

}

void setup() {
  Serial.begin(115200);
  Serial.println("setup");

  // Configure Sensor
  configureSensor();
}

void readSensor() {
  Serial.println("readSensor");
 
}

void loop() {
  readSensor();  
  delay(1000);
}
