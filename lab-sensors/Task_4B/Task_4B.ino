
const int numReadings = 10;

const unsigned long intervaltime= 1;
unsigned long lasttime = 0;
int readings[numReadings];      // the readings from the analog input
int readIndex = 0;              // the index of the current reading
int total = 0;                  // the running total
int average = 0;                // the average

int inputPin = A0;


void setup() {
  // initialize serial communication with computer:
  Serial.begin(9600);
  // initialize all the readings to 0:
  for (int thisReading = 0; thisReading < numReadings; thisReading++) {
    readings[thisReading] = 0;
  }
}

void loop() {
  // subtract the last reading:
  total = total - readings[readIndex];
  // read from the sensor:
  readings[readIndex] = analogRead(inputPin);
  // add the reading to the total:
  total = total + readings[readIndex];
  // advance to the next position in the array:
  readIndex = readIndex + 1;

  // if we're at the end of the array...
  if (readIndex >= numReadings) {
    // ...wrap around to the beginning:
    readIndex = 0;
  }

  // calculate the average:
  average = total / numReadings;

  //The millis begins a count from when the device is switched on
  //Using the millis function we are able using an if function read values at paticular time interval
  //The benefit of this over a delay is that the delay causes the program to delay to read and then print the value, 
  //whereas with the millis function the program is always running but the readings are just taken at defined intervals
    unsigned long timeNow = millis();
  if(timeNow - lasttime >= intervaltime){
    Serial.println(average);
   lasttime = timeNow;
 
  }
     
   

}
