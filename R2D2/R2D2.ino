#include <SoftwareSerial.h>// import the serial library
//Bluetooth
SoftwareSerial BTserial(11, 12); //RX TX

//Code by Reichenstein7 (thejamerson.com)

//Keyboard Controls:
//
// 1 -Motor 1 Left
// 2 -Motor 1 Stop
// 3 -Motor 1 Right
//
// 4 -Motor 2 Left
// 5 -Motor 2 Stop
// 6 -Motor 2 Right

// Declare L298N Dual H-Bridge Motor Controller directly since there is not a library to load.
// Motor 1
int dir1PinA = 2;
int dir2PinA = 3;

// Motor 2
int dir1PinB = 4;
int dir2PinB = 5;


String cmdBuilder = "";
String cmd = "";

char c=' ';
void setup() 
{
  Serial.begin(9600); // initialize serial communication @ 9600 baud:
  BTserial.begin(9600); //Bluetooth
  
  //Define L298N Dual H-Bridge Motor Controller Pins
  pinMode(dir1PinA,OUTPUT);
  pinMode(dir2PinA,OUTPUT);
  pinMode(dir1PinB,OUTPUT);
  pinMode(dir2PinB,OUTPUT);
}

void loop() 
{
  
  //bluetooth
  BTserial.listen();
  
  if(BTserial.available() > 0)
  {
    c=BTserial.read();

    if(cmd != "S")
    {
      Serial.println(c);
    }

    runCmd(String(c));    
  }
}

//// Motor 1
//int dir1PinA = 2;
//int dir2PinA = 3;
//
//// Motor 2
//int dir1PinB = 4;
//int dir2PinB = 5;

void runCmd(String cmd)
{
  if(cmd == "W")
  {
    
  }
  
  if(cmd == "S" || cmd == "J" || cmd == "H" || cmd == "I" || cmd == "G")
  {
    digitalWrite(dir1PinA, LOW);
    digitalWrite(dir2PinA, LOW);
    
    digitalWrite(dir1PinB, LOW);
    digitalWrite(dir2PinB, LOW);
  }

  if(cmd == "F")
  {
    //Motor 1 Forward
    digitalWrite(dir1PinA, LOW);
    digitalWrite(dir2PinA, HIGH);

    //Motor 2 Forward
    digitalWrite(dir1PinB, LOW);
    digitalWrite(dir2PinB, HIGH);
  }


  if(cmd == "B")
  {
    //Motor 1 Reverse
    digitalWrite(dir1PinA, HIGH);
    digitalWrite(dir2PinA, LOW);

    //Motor 2 Reverse
    digitalWrite(dir1PinB, HIGH);
    digitalWrite(dir2PinB, LOW);
  }

  if(cmd == "R")
  {
    //Motor 1 Reverse
    digitalWrite(dir1PinA, LOW);
    digitalWrite(dir2PinA, LOW);

    //Motor 2 Reverse
    digitalWrite(dir1PinB, HIGH);
    digitalWrite(dir2PinB, LOW);
  }

  if(cmd == "L")
  {
    //Motor 1 Reverse
    digitalWrite(dir1PinA, HIGH);
    digitalWrite(dir2PinA, LOW);

    //Motor 2 Reverse
    digitalWrite(dir1PinB, LOW);
    digitalWrite(dir2PinB, LOW);
  }

  
}
