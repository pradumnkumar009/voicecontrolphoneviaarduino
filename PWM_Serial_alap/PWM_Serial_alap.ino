const int analogInPin = A5;  
const int analogOutPin = 9; 
int sensorValue = 0;        
int outputValue = 0;        
long long int timer=0;
int up=0;
int down=0;
int vector=0;
int temp=0;
int count=0;


void setup() {
  Serial.begin(9600);
}

void loop() {
  timer=millis();
  sensorValue = analogRead(analogInPin);
  if(timer%2000==0){            
    outputValue = map(sensorValue, 0, 1023, 0, 255);  
    analogWrite(analogOutPin, outputValue);
    if(count>150 && count<200 ){Serial.println(1);}/*Hi*/
    else if(count>400 && count<450 ){Serial.println(2);}/*whai Time is it*/
    else if(count>210 && count<260 ){Serial.println(3);}/*music*/
    else if(count>300 && count<3500 ){Serial.println(4);}/*Mathsmode*/
    count=0;
    up=0;
    down=0;
  } 
  if(analogRead(A5)>718){up=up+1;vector=1;}
  if(analogRead(A5)<10){down=down+1;vector=0;}
  if(vector!=temp){count+=1;}
  temp=vector;               
}
/*const int analogInPin = A0;       
long int timer;
int counter=0;

void setup() {
  Serial.begin(38400);
}

void loop() {
  timer=millis();
  if(timer%2000==0){          
    Serial.print(" " );                     
    Serial.println(counter);
    counter=0;
  }
  else if(analogRead(A0)>700){counter+=1;}
               
}*/
