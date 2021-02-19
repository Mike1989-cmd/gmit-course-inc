
/*
 * Depth CLASS DEFINITION
 */
class DepthSensor {
  private:
   
  byte PIN_Mike;
  
  unsigned long timeInterval;

  float voltage = PIN_Mike * (5.0/1023.0);
  float distance = -22*voltage+60; //as per slope staright line graph
  float distance1 = (0.1064*(pow(voltage,4)))-(7.321*(pow(voltage,3)))+(45.118*(pow(voltage,2)))-(98.843*voltage)+85.045; // This line does the equation of a curve which allows the data to represented more accuratley
  float x = voltage;

  public:
    DepthSensor(byte PIN_Mike, unsigned long timeInterval) {

      this->PIN_Mike = PIN_Mike;
      this->timeInterval = timeInterval;
      this->x = x;
      this->distance = distance;
      this->distance1 = distance1;

      pinMode(PIN_Mike, OUTPUT);
    }

    // Code
    void DepthCheck() {
     Serial.print("distance = "); Serial.print(distance);Serial.print("   voltage = ");Serial.print(voltage);
     Serial.println(" ");Serial.print("         distance1 = ");Serial.print(distance1);Serial.print("      ");
      }
    
};
