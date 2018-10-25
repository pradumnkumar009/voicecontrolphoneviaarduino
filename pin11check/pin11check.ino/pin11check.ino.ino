long int timer;
int up=0;
int down=0;
int vector=0;
int temp=0;
int count=0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

}

void loop() {
  timer=millis();
  if(timer%2000==0){
     Serial.print(up);
     Serial.print(' ');
     Serial.print(down);
     Serial.print(' ');
     Serial.print(abs(up-down));
     up=0;
     down=0;
     Serial.print(' ');
     Serial.println(count);
     count=0;
  }
  if(analogRead(A5)>718){up=up+1;vector=1;}
  if(analogRead(A5)<10){down=down+1;vector=0;}
  if(vector!=temp){count+=1;}
  temp=vector;
}
