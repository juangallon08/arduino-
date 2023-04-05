// Definir el pin del LED
int verde1 = 4;
int rojo1 = 3;
int amarillo = 5;
int rojo2 = 6;
int verde2 = 7;
// Definir el pin del botón
int buttonPin = 1;
int button2 = 2;
// Definir una variable para contar las pulsaciones del botón
int buttonCount = 0;
// Definir una variable para almacenar el estado anterior del botón
int lastButtonState = LOW;
// Definir una variable para contar las pulsaciones del botón 2
int buttonCount2 = 0;
// Definir una variable para almacenar el estado anterior del botón 2
int lastButtonState2 = LOW;


void setup() {
  // Configurar el pin del LED como salida
  //Serial.begin(9600);
  pinMode(verde1, OUTPUT);
  pinMode(rojo1, OUTPUT);
  pinMode(amarillo, OUTPUT);
  pinMode(verde2, OUTPUT);
  pinMode(rojo2, OUTPUT);
  // Configurar el pin del botón como entrada
  pinMode(buttonPin, INPUT);
  pinMode(button2,INPUT);
  //condicion inicial 
  digitalWrite(verde1,HIGH);
  digitalWrite(rojo1,LOW);
  digitalWrite(amarillo,LOW);
  digitalWrite(verde2,LOW);
  digitalWrite(rojo2,HIGH);
}

void loop() {
     
   // Leer el estado actual del botón
  int buttonState = digitalRead(buttonPin);

  // Comprobar si el botón ha sido pulsado
  if (buttonState != lastButtonState) {
    if (buttonState == HIGH) {
      // Aumentar el contador de pulsaciones del botón
      buttonCount++;
      
    }

    // Actualizar el estado anterior del botón
    lastButtonState = buttonState;
   
  }
  
 // Comprobar si el botón ha sido pulsado 5 veces
  if (buttonCount == 5) {
    // Encender el LED
    digitalWrite(amarillo,HIGH); 
    delay(1000);
    digitalWrite(verde1, LOW);
    digitalWrite(rojo1,HIGH);
    digitalWrite(verde2,HIGH);
    digitalWrite(rojo2,LOW);
    digitalWrite(amarillo,LOW); 
    buttonCount2=0;
  } 
 // Leer el estado actual del botón 2
  int buttonState2 = digitalRead(button2);

  // Comprobar si el botón 2 ha sido pulsado
  if (buttonState2 != lastButtonState2) {
    if (buttonState2 == HIGH) {
      // Aumentar el contador de pulsaciones del botón 2
      buttonCount2++;
    }
    Serial.println(buttonCount); 
    // Actualizar el estado anterior del botón 2
    lastButtonState2 = buttonState2;
  }           
   if (buttonCount2 == 5) {
    // Encender el LED
    digitalWrite(amarillo,HIGH); 
    delay(1000);
    digitalWrite(verde1,HIGH);
    digitalWrite(rojo1,LOW);
    digitalWrite(verde2,LOW);
    digitalWrite(rojo2,HIGH);
    digitalWrite(amarillo,LOW); 
    buttonCount=0;
   }   
  
}
