
/*
 * Light Sensor CLASS DEFINITION*/

class LightSensor {
  
  private:
   
  float PINMIKE;
  unsigned long timeInterval;
  unsigned long nextchangetime = 0;
  int val = 0;
  float voltage = 0;


 
 
  public:
     //Constructor   
        
        LightSensor(float PINMIKE, unsigned long timeInterval) {

      this->PINMIKE = PINMIKE;
      this->timeInterval = timeInterval;
     
      pinMode(analogRead(PINMIKE), INPUT);
}

  //Calculations

  void checklight(){
    unsigned long currentTime = millis();//system clock

    //check if the interval of time has passed

    if(currentTime >= nextchangetime){
      val = analogRead(PINMIKE);
      voltage = val * (5.0/1023.0);
      

      nextchangetime = currentTime + timeInterval;
    }
  }
      
          
         float getvoltage(){
          return voltage;
         }


         
    };
