#include <LiquidCrystal.h>
#define sh_2 8
#define sh_1 7
#define rojo 9
#define verde 10
#define amarillo 11
#define rojo2 12
#define verde2 13
int b = 0;
int b2 = 0;
// Definir una variable para contar las pulsaciones del botón
int buttonCount = 0;
// Definir una variable para almacenar el estado anterior del botón
int lastButtonState = LOW;

// Definir una variable para contar las pulsaciones del botón
int buttonCount2 = 0;
// Definir una variable para almacenar el estado anterior del botón
int lastButtonState2 = LOW;

//LiquidCrystal lcd(7,6,5,4,3,2);  //(rs,e,d4,d5,d6,d7)

void setup() {
  // put your setup code here, to run once:
//  lcd.begin(16, 2);
  Serial.begin(9600);//iniciailzamos la comunicación
  pinMode(sh_2, INPUT);
  pinMode(sh_1, INPUT);
  pinMode(rojo, OUTPUT);
  pinMode(verde,OUTPUT);
  pinMode(rojo2, OUTPUT);
  pinMode(verde2,OUTPUT);
  pinMode(amarillo,OUTPUT);
  //Condiciones niciales 
  digitalWrite(verde,HIGH);
  digitalWrite(rojo,LOW);
  digitalWrite(amarillo,LOW);
  digitalWrite(verde2,LOW);
  digitalWrite(rojo2,HIGH);
  
}

void loop() {
  // put your main code here, to run repeatedly:
 int coco = contador (sh_1);
 int chanel = contador2 (sh_2);
 Serial.print("\nInductivo:");
 Serial.println(coco);
 Serial.print("Capacitivo:");
 Serial.println(chanel);
 delay(100);
 //lcd.setCursor(0,0);
 //lcd.print("semaforo 1");
 //lcd.setCursor(0,1);
 //lcd.print(coco);

 if (coco == 5){
  digitalWrite(amarillo,HIGH);
  delay(1000);
  digitalWrite(rojo,HIGH);
  digitalWrite(amarillo,LOW);
  digitalWrite(verde,LOW);
  digitalWrite(rojo2,LOW);
  digitalWrite(verde2,HIGH);
  b=1;
  }
if (b==1){
  buttonCount=0;
  digitalWrite(rojo,HIGH);
  digitalWrite(amarillo,LOW);
  digitalWrite(verde,LOW);
  digitalWrite(rojo2,LOW);
  digitalWrite(verde2,HIGH);
  b=0;
  }  
if (chanel == 5){
  digitalWrite(amarillo,HIGH);
  delay(1000);
  digitalWrite(rojo,LOW);
  digitalWrite(amarillo,LOW);
  digitalWrite(verde,HIGH);
  digitalWrite(rojo2,HIGH);
  digitalWrite(verde2,LOW);
  b2=1;
  }
if (b2==1){
  buttonCount2=0;
  digitalWrite(rojo,LOW);
  digitalWrite(amarillo,LOW);
  digitalWrite(verde,HIGH);
  digitalWrite(rojo2,HIGH);
  digitalWrite(verde2,LOW);
  b2=0;
  }  
}
// Funciones Para los dos pulsadores 
int contador (int buttonPin){
  
    
   // Leer el estado actual del botón
  int buttonState = digitalRead(buttonPin);

  // Comprobar si el botón ha sido pulsado
  if (buttonState != lastButtonState) {
    if (buttonState == HIGH) {
      // Aumentar el contador de pulsaciones del botón
      buttonCount++;
      delay(100);
    }

    // Actualizar el estado anterior del botón
    lastButtonState = buttonState;
   
  }
  
  return (buttonCount);
  
  
  }
int contador2 (int buttonPin){
  
    
   // Leer el estado actual del botón
  int buttonState2 = digitalRead(buttonPin);

  // Comprobar si el botón ha sido pulsado
  if (buttonState2 != lastButtonState2) {
    if (buttonState2 == HIGH) {
      // Aumentar el contador de pulsaciones del botón
      buttonCount2++;
      delay(100);
    }

    // Actualizar el estado anterior del botón
    lastButtonState2 = buttonState2;
   
  }
  
  return (buttonCount2);
  
  
  }  
