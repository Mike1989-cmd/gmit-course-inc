
/*
 * Depth CLASS DEFINITION
 */
class DepthSensor {
  
  private:
   
  float PINMike;
  unsigned long timeInterval;

 
  public:
    
          float getPINMike(float a){
            PINMike = analogRead(a);
    }
      
      //float voltage = PINMike * (5.0/1023.0);
  //float distance = -22*voltage+60; //as per slope staright line graph
 // float distance1 = (0.1064*(pow(voltage,4)))-(7.321*(pow(voltage,3)))+(45.118*(pow(voltage,2)))-(98.843*voltage)+85.045; // This line does the equation of a curve which allows the data to represented more accuratley
  //float x = voltage;  
    
    DepthSensor(float PINMike, unsigned long timeInterval) {

      this->PINMike = PINMike;
      this->timeInterval = timeInterval;
 



      pinMode(analogRead(PINMike), INPUT);
    }


    float getPINMike(){
      return analogRead(PINMike);
    }
    


    // Code
    void DepthCheck() {


    //Serial.print("distance = "); Serial.print(distance);Serial.print("   voltage = ");Serial.print(voltage);
  // Serial.println(" ");Serial.print("         distance1 = ");Serial.print(distance1);Serial.print("      ");
    
     }
    
};
