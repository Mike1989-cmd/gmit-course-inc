/*Servo actuator requires 4 to 6VDC, and maximum current draw of 140+/-50mA at 6VDC when operating in
 * no load conditions.
 * Communication with Pulse width modulation (PWM), 0.75-2.25ms high pulse, 20ms intervals.
 * operates between 0 and 180 degrees
 */

#include <Servo.h>



Servo myservo;  // create servo object to control a servo
   DepthSensor Mike (A0,500);
 class servoActuator{
  private:
  byte PINSERVO;
  unsigned long timeOn;
  int angle = 0;
  float tempdepth = 0;

  public:


  servoActuator(byte PINSERVO,unsigned long interval){
    this->PINSERVO = PINSERVO;
    this->timeOn = interval;
    pinMode(PINSERVO, OUTPUT);
  //myservo.attach(PINSERVO,600,2300);  // (pin, min, max)
  }
   void setdepth(float Depth){ //This defines the distance1 (distance using quadratic equation), from the depthsensor class so it can be used here for mapping.
    tempdepth = Depth;
   }
  
  void process(){


   if (tempdepth < 10){ //if statement so that if the distance is less than 10cm the angle remains at its minimum value of 0 degrees. 
    angle = 0;
   }
   else if (tempdepth > 20){ //if statement so that if the distance is graeter than 20cm the angle remains at its maximum value of 180 degrees. 
    angle = 0;
    angle = 180; 
   }

   else{
   angle = map(tempdepth, 10, 20, 0, 180); //The map function maps the distances from 10cm to 20cm, to 0 to 180 degrees. This formula also works (tempdepth - 10)*(180/10, but the map function eliminates the need for this; 
                                            // This formula only operates when the distance is between 10 and 20cm.
  }
   Serial.print(" Depth = ");Serial.print(tempdepth);Serial.print(" Servo angle = "); Serial.println(angle);
     myservo.write(angle);  // tell servo to go to a particular angle based on the distance calculated in the depthsensor class
    delay(1000);

  }
          float getangle(int angle){
          return angle;
         }
 };
