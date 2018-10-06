/**
   Moto Crash Project

   This project is free and use CC BY-NC-SA:
   This license lets others remix, tweak, and build upon your work, as long as they credit you and license their new creations under the identical terms.
   This license is often compared to “copyleft” free and open source software licenses. All new works based on yours will carry the same license.

   ArtCC 2018++

   Enjoy it! :)
*/

// Import classes and libraries
#include "ImportClasses.h"

// Properties
LSM6DS3 groveSensorModule(I2C_MODE, 0x6A);

// Public functions
void setup() {
  Serial.begin(115200);

  gps.activateGPS();
  gsm.activateSIM();
  configureGroveSensorModule();
}

void loop() {
  //gps.activateGPSData();
  //gsm.receivedSMS();
  //startGroveSensorModule();
  delay(500);
}

// Private functions
// LSM6DS3 config
void configureGroveSensorModule() {

  if (debug) {

    Serial.println("Initialize LSM6DS3");
  }

  while (groveSensorModule.begin() != 0) {

    if (debug) {

      Serial.println("Could not find a valid LSM6DS3 sensor, check wiring!");
    }

    delay(100);
  }
}

void startGroveSensorModule() {
  sensor.processValuesFromGroveSensor(groveSensorModule.readFloatAccelX(),
                                      groveSensorModule.readFloatAccelY(),
                                      groveSensorModule.readFloatAccelZ(),
                                      groveSensorModule.readFloatGyroX(),
                                      groveSensorModule.readFloatGyroY(),
                                      groveSensorModule.readFloatGyroZ(),
                                      groveSensorModule.readTempC());
}
