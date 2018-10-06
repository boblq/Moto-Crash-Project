// Import classes and libraries
#include "ImportClasses.h"

// Public functions
void GroveSensor::processValuesFromGroveSensor(float aX,
    float aY,
    float aZ,
    float gX,
    float gY,
    float gZ,
    float temperature) {

  if (debug) {

    // Accelerometer
    Serial.print("\nAccelerometer:\n");
    Serial.print(" X1 = ");
    Serial.println(aX);
    Serial.print(" Y1 = ");
    Serial.println(aY);
    Serial.print(" Z1 = ");
    Serial.println(aZ);

    // Gyroscope
    Serial.print("\nGyroscope:\n");
    Serial.print(" X1 = ");
    Serial.println(gX);
    Serial.print(" Y1 = ");
    Serial.println(gY);
    Serial.print(" Z1 = ");
    Serial.println(gZ);

    // Thermometer
    Serial.print("\nThermometer: ");
    Serial.print(temperature);
    Serial.println("*C");
    Serial.println();

    // Differences between values
    Serial.print("Difference between gyroscope X: ");
    Serial.println(differenceGyroscopeX);
    Serial.print("Difference between gyroscope Y: ");
    Serial.println(differenceGyroscopeY);
    Serial.println();
  }
}
