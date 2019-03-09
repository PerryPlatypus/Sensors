int Laser = 12;//Assign signal pin to Laser Module
int LDR = 32;//Assign signal pin to photoresistor
int value; // value holds LDR voltage/resistivity reading

int toggle = 0;

int LED = 26;// LED pin
void setup() {
  // put your setup code here, to run once:
  Serial.print("TripWire Test");
  Serial.begin(9600);
  pinMode(LDR,INPUT);// LDR is an input signal to board
  digitalWrite(LDR,LOW); //LDR begins in a low state
  
  pinMode(Laser,OUTPUT);//Laser receives output from board
  digitalWrite(Laser,LOW);//Laser starts in off state

  pinMode(LED,OUTPUT);// LED receives signal from board
  digitalWrite(LED,LOW);//LED starts in off state

}

void loop() {
  // put your main code here, to run repeatedly:
  value = analogRead(LDR); // value takes on value of the LDR
 
  digitalWrite(Laser,HIGH); //Laser is switched on
 
  
   if(value<300){// if value is less than threshold the laser trips
    Serial.print("laser trip:");
    Serial.print(" ");
    digitalWrite(LED,HIGH);//LED is set ON when Laser trips
    
    if (toggle == 0) {
      digitalWrite (LED, HIGH);
      toggle = 1;
    }
     
     
    }else{
       digitalWrite(LED,LOW);// otherwise the LED is off when Laser is not triped
       toggle = 0;
      }
      Serial.println(value);
  delay(500);//Delay between each reading

}
