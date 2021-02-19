
#define PIN_LED1 7
#define PINMike analogRead(A0)


/*
 *  BLINKER CLASS VARIABLES DECLARATION
 */
Blinker blink1 = Blinker(PIN_LED1, 500, 500);
DepthSensor Depth = DepthSensor(analogRead (PINMike),500);


void setup() {
Serial.begin(9600);
}

void loop() {
  blink1.check();
  Depth.DepthCheck();


// Serial.println(Depth.getPINMike());                       


/* I WAS UNABLE TO GET THE ANALOG READINGS TO BE ANTHING OTHER THAN '0' WITHOUT DOING A GET VALUE IN THE MAIN,
   AND I THEN HAD TO DO THE CALCULATIONS IN THE MAIN, I AM ABLE TO GET VALUES FROM PRIVATE IT WAS JUST AN ISSUE WITH THE ANALOG VALUE.
   WHEN I TRIED GETTING IT IN THE PUBLIC CLASS FROM THE PRIVATE I KEPT GETTING 0V, FROM THE ANALOG INPUT ON MY SERIAL MONITOR. 
   THIS FILE IS A MESS BECAUSE I HAVE ATTEMTED SO MANY DIFFERENT WAYS AND WAS DOING TESTS IN THE MIDDLE.

  I KNOW THE MILLIS FUNCTION IS NEEDED TO STAEDY THE READINGS BUT TRYING TO GET THE OTHER PART EVEN CLOSE TO WORKING HAS EAT INTO MY TIME.
   */


  float voltage = Depth.getPINMike()*(5.0/1023.0);
  float distance = -22*voltage+60; //as per slope staright line graph
  float distance1 = (0.1064*(pow(voltage,4)))-(7.321*(pow(voltage,3)))+(45.118*(pow(voltage,2)))-(98.843*voltage)+85.045; // This line does the equation of a curve which allows the data to represented more accuratley
  float x = voltage;  
  //Serial.println(a);
  //Serial.println(Depth.getPINMike());
 // Serial.println(Depth.getvoltage());

     Serial.print("distance = "); Serial.print(distance);Serial.print("   voltage = ");Serial.print(voltage);
   Serial.println(" ");Serial.print("         distance1 = ");Serial.print(distance1);Serial.print("      ");
}
