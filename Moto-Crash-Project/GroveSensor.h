/*
   GroveSensor class
   All functions for use Grove 6-Axis Accelerometer & Gyroscope module
*/

class GroveSensor {
  private:

    // Accelerometer and gyroscope
    int firstGyroscopeX;
    int firstGyroscopeY;
    int differenceGyroscopeX;
    int differenceGyroscopeY;
  public:

    // Function for process all values from module
    void processValuesFromGroveSensor(float aX,
                                      float aY,
                                      float aZ,
                                      float gX,
                                      float gY,
                                      float gZ,
                                      float temperature);
};
