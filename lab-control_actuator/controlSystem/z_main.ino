#include "c_depthSensor.h"
#include "c_Servo.h"
#define PINMike analogRead(A0)
#define PINSERVO 9

DepthSensor Depth(A0,500);
servoActuator Angle(PINSERVO,500);



void setup() {
Serial.begin(9600);
//pinMode(PINSERVO, OUTPUT);
myservo.attach(PINSERVO);  // (pin, min, max)
}

void loop() {
  
  Depth.checkdistance();
  float temp = Depth.geti();
  Angle.setdepth(Depth.getDepth());//Calls the distance1 from the depthsensor class into the Servo class, so it can be used to calculate the angle

/*Serial.print("Volatge = "); Serial.print(Depth.getvoltage());*/Serial.print(" Distance = "); Serial.print(Depth.getDepth()); /*Serial.print(" Servo angle = ");Serial.println(Depth.geti());*/
  
  
 

Angle.process();
//myservo.write(0);
//delay (1000);
//myservo.write(90);
//delay (1000);



}
