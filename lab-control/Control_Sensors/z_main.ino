
#define PIN_LED1 7
#define PIN_Mike A0


/*
 *  BLINKER CLASS VARIABLES DECLARATION
 */
Blinker blink1 = Blinker(PIN_LED1, 500, 500);
DepthSensor Depth = DepthSensor(PIN_Mike,500);

void setup() {
Serial.begin(9600);
}

void loop() {
  blink1.check();
  Depth.DepthCheck();
  
}
