
#define pinrelay 7
#define PINMike analogRead(A0)

LightSensor Light(A0,500);
Relay relay1 = Relay(pinrelay, 500, 500);



void setup() {
Serial.begin(9600);


}

void loop() {
  
  Light.checklight();
  relay1.check();
  relay1.setvoltage(Light.getvoltage());
  



Serial.print(" Voltage = "); Serial.println(Light.getvoltage()); 
  
  
 



}
