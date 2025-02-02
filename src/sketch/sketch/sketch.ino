#include <Wire.h>

//define ADDRESS_HMC5883 0x1E // Não funciona
#define ADDRESS_HMC5883 0x0D // Encontrado na listagem do i2c
#define SDA_LCD 33
#define SCL_LCD 32
#define SDA_SENSOR 21
#define SCL_SENSOR 22

bool isSensorAvailable = false;

void configureSensor() {
  Serial.println("configureSensor");
  byte error;

  // Put the HMC5883 IC into the correct operating mode
  Wire.begin();
  Wire.beginTransmission(ADDRESS_HMC5883); // Open communication with HMC5883

  Wire.write(0x02); // Select mode register
  Wire.write(0x00); // Continuous measurement mode
 

  error = Wire.endTransmission();

  if (error == 0)
    Serial.println("I2C device found");
  else if (error == 4)
    Serial.println("I2C device found unknow error");
}

void configureLCD() {

}

void setup() {
  Serial.begin(115200);
  Serial.println("setup");

  // Configure Sensor
  configureSensor();

  // Configure LCD
  configureLCD();
}

void readSensor() {
  Serial.println("readSensor");
  unsigned int data[6];
  byte error;

  Wire.beginTransmission(ADDRESS_HMC5883); // Open communication with HMC5883
  Wire.write(0x03); // Select data register
  error = Wire.endTransmission();

  Serial.print("i2c error: ");
  Serial.println(error);

  Wire.requestFrom(ADDRESS_HMC5883, 6); // Request 6 bytes of data

  int wireAvailable = Wire.available();

  Serial.print("wireAvailable: ");
  Serial.println(wireAvailable);
  
  if (6 <= wireAvailable)
    isSensorAvailable = true;
  else
    isSensorAvailable = false;

  if(isSensorAvailable) {
    data[0] = Wire.read() << 8 | Wire.read(); // X-axis data
    data[1] = Wire.read() << 8 | Wire.read(); // Y-axis data
    data[2] = Wire.read() << 8 | Wire.read(); // Z-axis data
  
    // Print out values of each axis
    Serial.print("x: ");
    Serial.print(data[0]);
    Serial.print(" y: ");
    Serial.print(data[1]);
    Serial.print(" z: ");
    Serial.println(data[2]);
  } else {
    Serial.println("No sensor data available");
  }
}

void loop() {
  readSensor();  
  delay(1000);
}
