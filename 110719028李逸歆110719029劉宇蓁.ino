/*
  DigitalReadSerial

  Reads a digital input on pin 2, prints the result to the Serial Monitor

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/DigitalReadSerial
*/

// digital pin 2 has a pushbutton attached to it. Give it a name:
byte seven_seg_digits[10][7] = { { 1,1,1,1,1,1,0 },  // = 0
                                 { 0,1,1,0,0,0,0 },  // = 1
                                 { 1,1,0,1,1,0,1 },  // = 2
                                 { 1,1,1,1,0,0,1 },  // = 3
                                 { 0,1,1,0,0,1,1 },  // = 4
                                 { 1,0,1,1,0,1,1 },  // = 5
                                 { 1,0,1,1,1,1,1 },  // = 6
                                 { 1,1,1,0,0,0,0 },  // = 7
                                 { 1,1,1,1,1,1,1 },  // = 8
                                 { 1,1,1,0,0,1,1 }   // = 9
                             };

const int buttonPin = 12;
int buttonState = 0;
int num = 0;


// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second
  Serial.begin(9600);
  // make the pushbutton's pin an input:
  pinMode(2, OUTPUT);  
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  digitalWrite(9, 0);  // 關閉小數點
  pinMode(buttonPin,INPUT);
  digitalWrite(buttonPin,HIGH);
  
}

void sevenSegWrite(byte digit) {
  byte pin = 2;
  for (byte seg = 0; seg < 7; ++seg) {
    digitalWrite(pin, seven_seg_digits[digit][seg]);
    ++pin;
  }

}

// the loop routine runs over and over again forever:
void loop() {
  /*sevenSegWrite(num); 
  Serial.println(num);
  delay(1000);
  num++;*/
  buttonState = digitalRead(buttonPin);

   if(buttonState == LOW){
    //digitalWrite(pin,0);
    //sevenSegWrite(0); 
    num=0;
    
   }
  else if(buttonState == HIGH){
    sevenSegWrite(num); 
    Serial.println(num);
     num ++;

    if(num > 9){
       num = 0;
    }
}
//Serial.println(buttonState);
 //sevenSegWrite(num); 
delay(1000);

 
        
}
