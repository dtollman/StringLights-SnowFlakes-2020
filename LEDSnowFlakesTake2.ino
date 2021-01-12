#include <SoftwareSerial.h> 
SoftwareSerial HM10(2,3); //RX = 2, TX = 3
char appData;  //Input from bluetooth app
String inData = ""; //Input converted for processing
int delayms = 250; //Delay in ms
long RandNum; //Random Number for Random Sequence Option
//9 = All Green LEDs
//8 = All Blue LEDs
//7 = All Yellow LEDs
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("HM10 serial started at 9600");
  HM10.begin(9600); // set HM10 serial at 9600 baud rate
  pinMode(9, OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(7,OUTPUT);
  digitalWrite(9, LOW); // switch OFF LED
  digitalWrite(8, LOW); // switch OFF LED
  digitalWrite(7, LOW); // switch OFF LED  
  HM10.listen();  // listen the HM10 port

}

void loop() 
{
  while (HM10.available() > 0) 
  {   // if HM10 sends something then read
    appData = HM10.read();
    inData = String(appData);  // save the data in string format
    Serial.write(appData);
    Serial.println("\n"); //New line for readability
  }
  if (Serial.available()) 
  {           // Read user input if available.
    delay(10); //Delay to not overwhelm sensor
    HM10.write(Serial.read());
    Serial.println("\n");
  }

   if ( inData == "C") //Continuous On
   {
    
    Serial.println("LED OFF");
    digitalWrite(9, HIGH);
    digitalWrite(8, HIGH);
    digitalWrite(7, HIGH);
    delay(100);
  }
  
  if ( inData == "B")  //Blink Pattern
  {
    
    Serial.println("LED ON");
    digitalWrite(9, HIGH);
    digitalWrite(8, HIGH);
    digitalWrite(7, HIGH);
    delay(delayms);
    digitalWrite(7, LOW);
    delay(delayms);
    digitalWrite(8, LOW);
    delay(delayms);
    digitalWrite(9,LOW);
    digitalWrite(8,HIGH);
    delay(delayms);
    digitalWrite(8,LOW);
    digitalWrite(7,HIGH);
    delay(delayms);
    digitalWrite(9,HIGH);
    delay(delayms);
    digitalWrite(7,LOW);
    digitalWrite(8,HIGH);
    delay(delayms);
    digitalWrite(9,LOW);
    digitalWrite(7,HIGH);
    delay(delayms);
    digitalWrite(9,HIGH);
    delay(delayms);
    digitalWrite(9,LOW);
    digitalWrite(8,LOW);
    digitalWrite(7,LOW);
    delay(100);
    digitalWrite(9,HIGH);
    digitalWrite(8,HIGH);
    digitalWrite(7,HIGH);
    delay(100);
    digitalWrite(9,LOW);
    digitalWrite(8,LOW);
    digitalWrite(7,LOW);
    delay(100);
    digitalWrite(9,HIGH);
    digitalWrite(8,HIGH);
    digitalWrite(7,HIGH);
    delay(100);
    digitalWrite(9,LOW);
    digitalWrite(8,LOW);
    digitalWrite(7,LOW);
    delay(100);
    digitalWrite(9,HIGH);
    digitalWrite(8,HIGH);
    digitalWrite(7,HIGH);
    delay(100);
    digitalWrite(9,LOW);
    digitalWrite(8,LOW);
    digitalWrite(7,LOW);
    delay(delayms);
  } 

 if ( inData == "D")  //Blink Pattern
  {
    
    Serial.println("LED ON");
    digitalWrite(9, HIGH);
    digitalWrite(8, HIGH);
    digitalWrite(7, HIGH);
    delay(delayms);
    digitalWrite(7, LOW);
    delay(delayms);
    digitalWrite(8, LOW);
    delay(delayms);
    digitalWrite(9,LOW);
    digitalWrite(8,HIGH);
    delay(delayms);
    digitalWrite(8,LOW);
    digitalWrite(7,HIGH);
    delay(delayms);
    digitalWrite(9,HIGH);
    delay(delayms);
    digitalWrite(7,LOW);
    digitalWrite(8,HIGH);
    delay(delayms);
    digitalWrite(9,LOW);
    digitalWrite(7,HIGH);
    delay(delayms);

  } 
  if ( inData == "R") //Random
   {
    //Turn off all LEDs to allow Random sequence
    digitalWrite(9,LOW);
    digitalWrite(8,LOW);
    digitalWrite(7,LOW);

    //Create random sequence!
    RandNum = random(8); //Chose a random number which indicates a sequence
    if (RandNum == 0)
     {
       digitalWrite(9,HIGH);    
     }
     
    if (RandNum == 1)
     {
       digitalWrite(8,HIGH);    
     }
     
    if (RandNum == 2)
     {
       digitalWrite(7,HIGH);    
     }

    if (RandNum == 3)
     {
       digitalWrite(9,HIGH); 
       digitalWrite(8,HIGH);   
     }

    if (RandNum == 4)
     {
       digitalWrite(9,HIGH); 
       digitalWrite(7,HIGH);   
     }

    if (RandNum == 5)
     {
       digitalWrite(8,HIGH); 
       digitalWrite(7,HIGH);   
     }

    if (RandNum == 6)
     {
       digitalWrite(9,HIGH);
       digitalWrite(8,HIGH); 
       digitalWrite(7,HIGH);  
     }

    if (RandNum == 7)
    {
      //Nothing!
    }
    delay(delayms);
   }

   if ( inData == "O") //Off
   {
     digitalWrite(9,LOW);
     digitalWrite(8,LOW);
     digitalWrite(7,LOW);
     delay(delayms);
   }

}