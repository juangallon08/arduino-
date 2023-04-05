#include <LiquidCrystal.h>

const int Trigger = 2;   //Pin digital 2 para el Trigger del sensor
const int Echo = 3;   //Pin digital 3 para el Echo del sensor
float dd;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);//iniciailzamos la comunicación
  pinMode(Trigger, OUTPUT); //pin como salida
  pinMode(Echo, INPUT);  //pin como entrada
  digitalWrite(Trigger, LOW);//Inicializamos el pin con 0
}

void loop() {
   dd = distancia(Trigger,Echo);
}
float distancia(int Trigger,int Echo){
   long t; //timepo que demora en llegar el eco
   long d; //distancia en centimetros

   digitalWrite(Trigger, HIGH);
   delayMicroseconds(10);          //Enviamos un pulso de 10us
   digitalWrite(Trigger, LOW);
  
  t = pulseIn(Echo, HIGH); //obtenemos el ancho del pulso
  d = t/59;              //escalamos el tiempo a una distancia en cm
  
  return (d);
}
