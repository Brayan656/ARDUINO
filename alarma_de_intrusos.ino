int contador=0;
const int ledRojo=PA7;
const int ledAmarillo=PA6;
const int sonido=PA4;
int distancia;
void setup() {
  Serial.begin(9600);
  //ultrasonido
  pinMode(PA2,OUTPUT);
  pinMode(PA1,INPUT);
  digitalWrite(PA2,HIGH);
  //sonido
  pinMode(sonido,OUTPUT);
  //led
  pinMode(ledRojo,OUTPUT);
  pinMode(ledAmarillo,OUTPUT);
}

void loop() {
  distancia=leer();
  intruso(distancia);
}
int leer(){
  int  t;
  int  d; 

  digitalWrite(PA2, HIGH);
  delayMicroseconds(10);       
  digitalWrite(PA2, LOW);
  
  t = pulseIn(PA1, HIGH); 
  d = t/59; 
  return d;
}
void intruso(int distancia){
  if(distancia<100){
      do{
        Serial.println("intruso");
        digitalWrite(ledRojo,HIGH);
        tone(sonido,1000,250);
        delay(100);
        digitalWrite(ledRojo,LOW);
        digitalWrite(ledAmarillo,HIGH);
        tone(sonido,900,250);
        delay(100);
        digitalWrite(ledAmarillo,LOW);
      }while(Serial.available()<=0);
    }
}
