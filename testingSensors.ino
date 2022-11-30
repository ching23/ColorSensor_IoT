// The PWM pins the LED is attached to.
int rled = 14; 
int gled = 12;
int bled = 15;

// the setup routine runs once when you press reset:
void setup() {
  pinMode(rled, OUTPUT);
  pinMode(gled, OUTPUT);
  pinMode(bled, OUTPUT);
  
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  pinMode(39, INPUT);
  pinMode(35, INPUT);
  pinMode(33, INPUT);
}

// the loop routine runs over and over again forever:
void loop() {
  // sensors connected to each pin
  // sensor 1 = red
  // sensor 2 = green
  // sensor 3 = blue
  float sensorValue1 = analogRead(39);
  float sensorValue2 = analogRead(35);
  float sensorValue3 = analogRead(33);

  float Rcolor = 0; 
  float Gcolor = 0; 
  float Bcolor = 0; 

  // red LED
  if (sensorValue1 < 750) {
      Rcolor = map(sensorValue1, 0, 750, 255, 0);
      analogWrite(rled, Rcolor);
  }
  else {
      analogWrite(rled, 255);
  }

  // green LED
  if (sensorValue2 < 450) {
      Gcolor = map(sensorValue2, 0, 450, 255, 0);
      analogWrite(gled, Gcolor);
  }
  else {
      analogWrite(gled, 255);
  }

  // blue LED
  if (sensorValue3 < 310) {
      Bcolor = map(sensorValue3, 0, 310, 255, 0);
      analogWrite(bled, Bcolor);
  }
  else {
      analogWrite(bled, 255);
  }

  // print out the value you read:
  Serial.println(sensorValue1);
  Serial.println(sensorValue2);
  Serial.println(sensorValue3);
  Serial.println(Rcolor);
  Serial.println(Gcolor);
  Serial.println(Bcolor);
  Serial.println("----------------");
  // delay in between reads for stability
  delay(1000);        
}
