//esta diseñada para que cuando la persona abra un obsequio
//empiece a sonar la melodia de cumpleaños con un guego de luces

int contador=0;
const int ledRojo=PA7;
const int ledAmarillo=PA6;
const int ledVerde=PA5;
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
  pinMode(ledVerde,OUTPUT);
  pinMode(ledRojo,OUTPUT);
  pinMode(ledAmarillo,OUTPUT);

}

void loop() {
  distancia=leer();
  cumple();

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
void cumple(){
  while(distancia>20){
    cancion();
  }
}
void cancion(){
  //perimera estrofa
  digitalWrite(ledVerde,HIGH);
  tone(sonido,523,500);//Do
  delay(500);
  digitalWrite(ledVerde,LOW);
  digitalWrite(ledRojo,HIGH);
  tone(sonido,523,500);//Do
  delay(500);
  digitalWrite(ledRojo,LOW);
  digitalWrite(ledAmarillo,HIGH);
  tone(sonido,600,1500);//Re
  delay(500);
  digitalWrite(ledAmarillo,LOW);
  digitalWrite(ledRojo,HIGH);
  tone(sonido,523,750);//DO
  delay(500);
  digitalWrite(ledRojo,LOW);
  digitalWrite(ledVerde,HIGH);
  tone(sonido,700,1000);//fa
  delay(500);
  digitalWrite(ledVerde,LOW);
  digitalWrite(ledAmarillo,HIGH);
  tone(sonido,650,1000);//mi
  digitalWrite(ledAmarillo,LOW);
delay(500);
  
  //segunda estrofa
  digitalWrite(ledVerde,HIGH);
            tone(sonido,523,500);//Do
            delay(500);
  digitalWrite(ledVerde,LOW);
  digitalWrite(ledRojo,HIGH);
            tone(sonido,523,500);//Do
            delay(500);
  digitalWrite(ledRojo,LOW);
  digitalWrite(ledAmarillo,HIGH);
            tone(sonido,600,1500);//Re
            delay(500);
  digitalWrite(ledAmarillo,LOW);
  digitalWrite(ledRojo,HIGH);
            tone(sonido,523,750);//DO
            delay(500);
  digitalWrite(ledRojo,LOW);
  digitalWrite(ledVerde,HIGH);
            tone(sonido,800,1000);//sol
            delay(500);
  digitalWrite(ledVerde,LOW);
  digitalWrite(ledAmarillo,HIGH);
            tone(sonido,700,1000);//fa
  digitalWrite(ledAmarillo,LOW);
delay(500);
  
  //tercera estrofa
  digitalWrite(ledVerde,HIGH);
            tone(sonido,523,500);//Do
            delay(500);
  digitalWrite(ledVerde,LOW);
  digitalWrite(ledRojo,HIGH);
            tone(sonido,523,500);//Do
            delay(500);
  digitalWrite(ledVerde,HIGH);
  digitalWrite(ledAmarillo,HIGH);
            tone(sonido,1100,1500);//Do*
            delay(500);
            tone(sonido,880,750);//la
            delay(500);
  digitalWrite(ledRojo,LOW);
            tone(sonido,700,1000);//fa
            delay(500);
  digitalWrite(ledVerde,LOW);
            tone(sonido,650,1000);//mi 
            delay(500);
  digitalWrite(ledAmarillo,LOW);
            tone(sonido,600,1500);//Re
delay(500);
  
  //cuarta estrofa
  digitalWrite(ledVerde,HIGH);
  tone(sonido,1000,500);//si
  delay(500);
  digitalWrite(ledVerde,LOW);
  digitalWrite(ledRojo,HIGH);
  tone(sonido,950,500);//si
  delay(500);
  digitalWrite(ledRojo,LOW);
  digitalWrite(ledAmarillo,HIGH);
  tone(sonido,880,1500);//la
  delay(500);
  digitalWrite(ledAmarillo,LOW);
  digitalWrite(ledRojo,HIGH);
  tone(sonido,700,750);//fa
  delay(500);
  digitalWrite(ledRojo,LOW);
  digitalWrite(ledVerde,HIGH);
  tone(sonido,800,1000);//sol
  delay(500);
  digitalWrite(ledVerde,LOW);
  digitalWrite(ledAmarillo,HIGH);
  tone(sonido,700,1000);//fa
  delay(500);
  digitalWrite(ledAmarillo,LOW);
  delay(10000);
}
