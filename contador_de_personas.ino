int contador=0;
const int led=PA5;
const int sonido=PA4;

void setup() {
  Serial.begin(9600);
  //ultrasonido
  pinMode(PA2,OUTPUT);
  pinMode(PA1,INPUT);
  digitalWrite(PA2,HIGH);
  //sonido
  pinMode(sonido,OUTPUT);
  //led
  pinMode(led,OUTPUT);
}

void loop() {  
  int distancia;
  distancia=leer();
  Serial.print("CANTIDAD DE PERSONAS :");
  contar(distancia);
  delay(250);
  digitalWrite(led,LOW);
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

void contar (int distancia){
  if(distancia<100){
      contador=contador+1;
      digitalWrite(led,HIGH);
      tone(sonido,1000,250);
  }
  Serial.println(contador);
}
