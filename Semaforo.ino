#include <LiquidCrystal.h>

#define sh_1 1
#define sh_2 2
#define rojo_1 3
#define verde_1 4
#define amarillo 5
#define rojo_2 6
#define verde_2 7
int ind;
int ban = 0;
int cap;
int suma = 0;

LiquidCrystal lcd(8,9,10,12,11,13);  //(rs,e,d4,d5,d6,d7)

void setup() {
  Serial.begin(9600);//iniciailzamos la comunicación
  pinMode(sh_1,INPUT);
  pinMode(sh_2,INPUT);
  pinMode(rojo_1,OUTPUT);
  pinMode(verde_1,OUTPUT);
  pinMode(amarillo,OUTPUT);
  pinMode(rojo_2,OUTPUT);
  pinMode(rojo_2,OUTPUT);
  lcd.begin(16,2);
  lcd.setCursor(4,0);
  lcd.print("SERVOS");

}

void loop() {
  // inicio primer semaforo
  digitalWrite(verde_1,HIGH);
  digitalWrite(rojo_1,LOW);
  digitalWrite(amarillo,LOW);// color amarillo comun para los dos semaforos 
  // inicio segundo semaforo
  digitalWrite(verde_2,LOW);
  digitalWrite(rojo_2,HIGH);
  
  if (ban==0){
     ind = contador (sh_1,suma);
     lcd.print("semaforo_1: ");
     lcd.print(ind);
     }
  if (ind == 5){
     digitalWrite(amarillo,HIGH); 
     delay(1000);
     //semaforo 1 
     digitalWrite(verde_1,LOW);
     digitalWrite(rojo_1,HIGH);
     //semaforo 2
     digitalWrite(verde_2,HIGH);
     digitalWrite(rojo_2,LOW);
     suma = 0;
     ban = 1;
    }
  if (ban == 1){
     cap = contador (sh_2,suma);
     lcd.print("semaforo_2: ");
     lcd.print(cap);
     if (cap == 5){
        digitalWrite(amarillo,HIGH); 
        delay(1000);
       //semaforo 1 
       digitalWrite(verde_1,HIGH);
       digitalWrite(rojo_1,LOW);
      //semaforo 2
       digitalWrite(verde_2,LOW);
       digitalWrite(rojo_2,HIGH);
       suma = 0;
       ban = 0;
      }
    }
  
  }

// Funcion para detecta el pulsador 
int contador (int sh,int suma){
    int estado;
    estado = digitalRead(sh);
    if (estado == 0 ){
        suma = suma + 1;
        }
    return (suma);   
   }
