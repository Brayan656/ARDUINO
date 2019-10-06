const int TRIGG = PA2;
const int ECHO = PA1;
const int LED = PA5;
const int sonido=PA4;
void setup() {
  // put your setup code here, to run once:
 Serial.begin(9600);
  pinMode(TRIGG,OUTPUT); 
  pinMode(ECHO,INPUT);  
  pinMode(LED, OUTPUT);
  pinMode(sonido,OUTPUT);
  digitalWrite(TRIGG,HIGH);
}



void loop() {
 int contador; 
 int  tiempo; 
 int  distancia; 
 int total;
 
  digitalWrite(TRIGG, HIGH);//prende
  delayMicroseconds(10);       //espera
  digitalWrite(TRIGG, LOW);//apaga
  
  tiempo = pulseIn(ECHO,HIGH); 
  distancia = tiempo/59; 

  if(distancia >0 && distancia <=70){
    Serial.print("Se subio un pasajero");
    contador++;
    digitalWrite(LED,HIGH);
    tone(sonido,1000,250);
    delay(100);
    digitalWrite(LED,LOW);
    }
  total = calculaTotal(contador); 
  
  Serial.print("CANTIDAD DE PASAJEROS "+contador);
  Serial.print("TOTAL MONTO PASAJES"+total);
  delay(500);

}

int calculaTotal(int contador){
  int valor;

  valor = contador*5400;
  
  return valor;
  }
