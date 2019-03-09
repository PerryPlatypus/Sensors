int soundSensor = 2;
int LED = 5;

int toggle = 0;

void setup() {
  // put your setup code here, to run once:

  pinMode(soundSensor,INPUT);
  pinMode(LED,OUTPUT);
  delay(1000);
  Serial.begin(9600);
  
}

void loop() {
  // put your main code here, to run repeatedly:
int SensorData=analogRead(soundSensor);

if(SensorData >=70 ){
 Serial.print("Sound trip: ");
    digitalWrite(LED,HIGH);

     if (toggle == 0) {
      digitalWrite (LED, HIGH);
      toggle = 1;
    }
 
     }else {
       // Serial.print("No Sound: ");
        digitalWrite(LED,LOW);
        toggle = 0;
        }

Serial.println(analogRead(soundSensor));
delay(1000);//Delay between each reading  
}
