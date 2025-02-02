#include <Wire.h>
#include <I2Cdev.h>
#include <HMC5883L.h>

#define ADDRESS_HMC5883 0x0D // Encontrado na listagem do i2c
#define SDA_SENSOR 21
#define SCL_SENSOR 22

HMC5883L mag = HMC5883L(ADDRESS_HMC5883);

bool isSensorAvailable = false;

void configureSensor() {
  Serial.println("configureSensor");

  // join I2C bus (I2Cdev library doesn't do this automatically)
  Wire.begin();

   // initialize device
  Serial.println("Initializing I2C devices...");
  mag.
  mag.initialize();
  
  // verify connection
  Serial.println("Testing device connections...");
  isSensorAvailable = mag.testConnection();
  Serial.println(isSensorAvailable ? "HMC5883L connection successful": "HMC5883L connection failed");
}

void setup() {
  Serial.begin(115200);
  Serial.println("setup");

  // Configure Sensor
  configureSensor();
}

void readSensor() {
  //Serial.println("readSensor");
 
}

void loop() {
  readSensor();  
  delay(1000);
}
