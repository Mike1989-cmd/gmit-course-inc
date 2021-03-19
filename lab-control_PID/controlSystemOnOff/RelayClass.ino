/*
 * BLINKER CLASS DEFINITION
 */
class Relay {
  private:
    byte pinrelay;

    boolean relayState = LOW;

    unsigned long timerelayOn;
    unsigned long timerelayOff;

    unsigned long nextChangeTime = 0;
    float tempvoltage = 0;

  public:
    Relay(byte pinrelay, unsigned long timerelayOn, unsigned long timerelayOff) {
      this->pinrelay = pinrelay;
      this->timerelayOn = timerelayOn;
      this->timerelayOff = timerelayOff;

      pinMode(pinrelay, OUTPUT);
    }

   void setvoltage(float voltage){
    tempvoltage = voltage;
   }
   
    
    void check() {
      unsigned long currentTime = millis();

      if(currentTime >= nextChangeTime) {

        if(tempvoltage <= 2) {
          // LED is currently turned On. Turn Off LED.
          relayState = LOW;
          nextChangeTime = currentTime + timerelayOff;
        }
        else{
          // LED is currently turned Off. Turn On LED.
          relayState = HIGH;
          nextChangeTime = currentTime + timerelayOn;
        }

        digitalWrite(pinrelay, relayState);
      }
    }
};
