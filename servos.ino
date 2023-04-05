#include <LiquidCrystal.h>
#include <Servo.h>

#define pwm_1 13 
#define pwm_2 12
#define pwm_3 11
#define pwm_4 10 
#define pwm_5 9
#define pwm_6 8
#define pul A0
#define dataLength 6

LiquidCrystal lcd(7,6,5,4,3,2);  //(rs,e,d4,d5,d6,d7)
Servo servo_1;
Servo servo_2;
Servo servo_3;
Servo servo_4;
Servo servo_5;
Servo servo_6;

String inputString = "";
bool stringComplete = false;
const char separator = ',';
uint8_t data[dataLength];   //[0-255,0-255,0-255]

uint8_t ang_1 = 0;
uint8_t ang_2 = 0;
uint8_t ang_3 = 0;
uint8_t ang_4 = 0;
uint8_t ang_5 = 0;
uint8_t ang_6 = 0;

uint8_t ang_ant_1 = 0;
uint8_t ang_ant_2 = 0;
uint8_t ang_ant_3 = 0;
uint8_t ang_ant_4 = 0;
uint8_t ang_ant_5 = 0;
uint8_t ang_ant_6 = 0;



uint8_t cont = 0;

void serialEvent(){
  while(Serial.available()){
    char inChar = (char)Serial.read();
    inputString += inChar;
    if(inChar == '-'){
      stringComplete = true;
    }
  }
}

void setup() {
  pinMode(pul,INPUT);
  
  servo_1.attach(pwm_1);
  servo_2.attach(pwm_2);
  servo_3.attach(pwm_3);
  servo_4.attach(pwm_4);
  servo_5.attach(pwm_5);
  servo_6.attach(pwm_6);

  servo_1.write(0);
  servo_2.write(0);
  servo_3.write(0);
  servo_4.write(0);
  servo_5.write(0);
  servo_6.write(0);

  Serial.begin(9600);

  lcd.begin(16,2);
  lcd.setCursor(4,0);
  lcd.print("SERVOS");
}

void loop() {
  if(stringComplete){
    for(uint8_t i = 0; i < dataLength; i++){
      uint8_t index = inputString.indexOf(separator);
      data[i] = inputString.substring(0,index).toInt();
      inputString = inputString.substring(index + 1);
    }

    ang_ant_1 = ang_1;
    ang_ant_2 = ang_2;
    ang_ant_3 = ang_3;
    ang_ant_1 = ang_4;
    ang_ant_2 = ang_5;
    ang_ant_3 = ang_6;

    ang_1 = data[0];
    ang_2 = data[1];
    ang_3 = data[3];
    ang_4 = data[4];
    ang_5 = data[5];
    ang_6 = data[6];

    Serial.println(String(ang_1) + ',' + String(ang_2) + ',' + String(ang_3) + ','+String(ang_4) + ',' + String(ang_5) + ',' + String(ang_6) + '-');

    lcd.clear();
    lcd.setCursor(4,0);
    lcd.print("SERVOS");

    inputString = "";
    stringComplete = false;

    for(uint8_t pos = ang_ant_1; pos <= ang_1; pos++){
      servo_1.write(pos);
      delay(10);
    }

     for(uint8_t pos = ang_ant_2; pos <= ang_2; pos++){
      servo_2.write(pos);
      delay(10);
    }

     for(uint8_t pos = ang_ant_3; pos <= ang_3; pos++){
      servo_3.write(pos);
      delay(10);
    }
    
      for(uint8_t pos = ang_ant_4; pos <= ang_4; pos++){
      servo_4.write(pos);
      delay(10);
    }

      for(uint8_t pos = ang_ant_5; pos <= ang_5; pos++){
      servo_5.write(pos);
      delay(10);
    }

      for(uint8_t pos = ang_ant_6; pos <= ang_6; pos++){
      servo_6.write(pos);
      delay(10);
    }

     for(uint8_t pos = ang_ant_1; pos > ang_1; pos--){
      servo_1.write(pos);
      delay(10);
    }

     for(uint8_t pos = ang_ant_2; pos > ang_2; pos--){
      servo_2.write(pos);
      delay(10);
    }

     for(uint8_t pos = ang_ant_3; pos > ang_3; pos--){
      servo_3.write(pos);
      delay(10);
    }

     for(uint8_t pos = ang_ant_4; pos > ang_1; pos--){
      servo_4.write(pos);
      delay(10);
    }

     for(uint8_t pos = ang_ant_5; pos > ang_2; pos--){
      servo_5.write(pos);
      delay(10);
    }

     for(uint8_t pos = ang_ant_6; pos > ang_3; pos--){
      servo_6.write(pos);
      delay(10);
    }


  }

  if(digitalRead(pul) == HIGH){
    while(digitalRead(pul)){}
    cont++;
    lcd.clear();
    lcd.setCursor(4,0);
    lcd.print("SERVOS");
  }
  switch(cont){
    case 0:
      lcd.setCursor(0,1);
      lcd.print("S1: ");
      lcd.print(ang_1);
      lcd.setCursor(7,1);
      lcd.print("S2: ");
      lcd.print(ang_2);
      break;

    case 1:
      lcd.setCursor(0,1);
      lcd.print("S3: ");
      lcd.print(ang_3);
      lcd.setCursor(7,1);
      lcd.print("S4: ");
      lcd.print(ang_4);
      break;

    case 2:
      lcd.setCursor(0,1);
      lcd.print("S5: ");
      lcd.print(ang_5);
      lcd.setCursor(7,1);
      lcd.print("S6: ");
      lcd.print(ang_6);
      break;


    case 3:
      cont = 0;
      break;
  }
}
