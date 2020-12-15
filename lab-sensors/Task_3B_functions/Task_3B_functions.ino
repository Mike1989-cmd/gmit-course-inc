void setup(){      
  Serial.begin(9600);
}

void loop() {
  int z;

 // This is where the function sum_func is called up in the part of the program
  z = sum_func(5, 6); // z now contains 1
  Serial.println(z);
  delay(1000);
}

int sum_func(int x, int y){ //Function which is called up in the main part of the program
  int z;
  z = x + y;
  return z;
}
