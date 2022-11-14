#include <IRremote.h>  
int RECV_PIN = 2;  
int hereket;
int pir = 8;
int buzzer = 3;
IRrecv irrecv(RECV_PIN);     
decode_results results;  
void setup()
{
  pinMode(pir,INPUT);
  pinMode(buzzer,OUTPUT);
  irrecv.enableIRIn();  
  Serial.begin(9600);
  
}


void loop()
{
  int hereket = digitalRead(pir);
  if(hereket == 1){
    digitalWrite(buzzer,HIGH);
  }
  if (irrecv.decode(&results)) {
     unsigned int value = results.value;
     switch(value){
       case 12495:
           digitalWrite(buzzer,LOW);
     }
     irrecv.resume();
   }

  
}
