
#define PinE 7
int buttonstate = 0;

void setup(){
  pinMode(PinA,OUTPUT);
  pinMode(PinB,OUTPUT);
  pinMode(PinC,OUTPUT);
  pinMode(PinD,OUTPUT);
  pinMode(PinE,INPUT);
    
  }


void loop() {
  // put your main code here, to run repeatedly:
  

/*  for (int i = 0; i<513; i++){
  
   oneStepCW(1); 

  }

    for (int i = 0; i<513; i++){
  
   oneStepCCW(1); */

int delayValue = analogRead(A0);
delayValue = map(delayValue, 0, 1023, 0, 255);   
buttonstate = digitalRead(PinE);
   if (buttonstate == HIGH){

    oneStepCCW(delayValue);

  
}
else {
  oneStepCW(delayValue);
}
}
