const int TRIGG=PA2;
const int ECHO=PA1;
const int led = PA5; 

 
void setup() {
  Serial.begin(9600);
  pinMode(TRIGG, OUTPUT);
  pinMode(ECHO, INPUT);
  pinMode(led, OUTPUT); // se define como salida
  
}
boolean t = false;
void loop() {
  
  int distancia;

  
  distancia = calculaDistancia();
  digitalWrite(led,0);
  
  if(distancia < 20 && t == false) {
    prenderlo();//se prende el led
    t = true;
    delay(10000);
  }
  if(distancia < 20 && t == true)
  {
    delay(30000);
    apagarlo();// se apaga el led
    t = false;
  }
}

int calculaDistancia() {
  int tiempo;
  int distancia;
  
  digitalWrite(TRIGG, 1);//prende
  delayMicroseconds(10);       //espera
  digitalWrite(TRIGG, 0);//apaga
  
  tiempo = pulseIn(ECHO,1); 
  distancia = tiempo/59;    

  return distancia;
}
void prenderlo(){
   digitalWrite(led, HIGH);
  delay (1001);
  }

void apagarlo(){
   digitalWrite(led, LOW );
  delay (1001);
  }
