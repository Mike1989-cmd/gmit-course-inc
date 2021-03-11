
/*
 * Depth CLASS DEFINITION*/
 
class DepthSensor {
  
  private:
   
  float PINMike;
  unsigned long timeInterval;
  unsigned long nextchangetime = 0;
  int val = 0;
  float voltage = 0;
  float distance = 0;
  int distance1 = 0;
  int i = 0;

 
 
  public:
     //Constructor   
        
        DepthSensor(float PINMike, unsigned long timeInterval) {

      this->PINMike = PINMike;
      this->timeInterval = timeInterval;
     
      pinMode(analogRead(PINMike), INPUT);
}

  //Calculations

  void checkdistance(){
    unsigned long currentTime = millis();//system clock

    //check if the interval of time has passed

    if(currentTime >= nextchangetime){
      val = analogRead(PINMike);
      voltage = val * (5.0/1023.0);
      distance = -22*voltage+60; //as per slope staright line graph
      distance1 = (11.506*(pow(voltage,4)))-(86.445*(pow(voltage,3)))+(244.78*(pow(voltage,2)))-(317.24*voltage)+174.48; // This line does the equation of a curve which allows the data to represented more accuratley
     //I recalibrated the sensor for as for some distances between 10 and 20cm, I was getting erratic values, I got the corresponding voltage for 10cm, 11cm, 12cm ..... 20cm, and got a new quadratic equation based on this.
     //So this eqaution differs from previous assignment for that reason.
      i = (distance1-10)*(180/10);
      

      nextchangetime = currentTime + timeInterval;
    }
  }
      
          
         float getvoltage(){
          return voltage;
         }
         float getDepth(){
          return distance1;
         }
         float getnextchangetime(){
          return nextchangetime;
         }

         float geti(){
          return i;
         }

         
    };
