//#include <SoftwareSerial.h>
#include <Servo.h> 

//SoftwareSerial mySerial(2, 3);
String inputString = "";
boolean stringComplete = false;
String magicLetterA, magicLetterB;


Servo myservo;  // create servo object to control a servo 
                // a maximum of eight servo objects can be created 
 
int pos = 0;    // variable to store the servo position 


void setup() {
  // put your setup code here, to run once:
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object 
  
  Serial.begin(9600);
  Serial.println("Serial Connected");
  
  magicLetterA = String("a");
  magicLetterB = String("b");
}

void loop() {
  // put your main code here, to run repeatedly:
  
  if (stringComplete) {
        Serial.println("String Entered");
        
        Serial.println("String is "+inputString);
        
        if (inputString == magicLetterA){
          moveSwitchToPerson();
        } else if (inputString == magicLetterB) {
          moveSwitchAwayFromPerson();
        } else {
           Serial.println("no magic letter Entered");
        }
        
        stringComplete = false;
        inputString = "";
  }
  
  // if the letter a gets typed into the serial monitor
  
  // move the switch
}

void serialEvent() {
  Serial.println("Serial Connected");
  while (Serial.available()) {
    char inChar = (char)Serial.read(); 
    if (inChar == '\r') {
      stringComplete = true;
    } else {
      inputString += inChar;
    }
  }
}

void moveSwitchToPerson(){
  Serial.println("Move Switch To Person");
 for(pos = 0; pos < 180; pos += 1)  // goes from 0 degrees to 180 degrees 
  {                                  // in steps of 1 degree 
    myservo.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(15);                       // waits 15ms for the servo to reach the position 
  }  
}

void moveSwitchAwayFromPerson(){
    Serial.println("Move Switch Away from Person");
  for(pos = 180; pos>=1; pos-=1)     // goes from 180 degrees to 0 degrees 
  {                                
    myservo.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(15);                       // waits 15ms for the servo to reach the position 
  } 
}
