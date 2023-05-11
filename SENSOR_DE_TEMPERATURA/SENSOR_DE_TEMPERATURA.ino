/*
  Fundación Kinal
  Centro Educativo Técnico Labral Kinal
  Electrónica
  Grado: Quinto
  Sección: A
  Curso: Taller de Electrónica Digital y Reparación de Computadoras I
  Nombre: Alvaro Josue Antonio Marroquin Corado
  Carné: 2022375
  proyecto:SENSOR DE TEMPERATURA
*/

#include <OneWire.h>
#include <DallasTemperature.h>
#include <LiquidCrystal_I2C.h>
#define led0 3
#define led1 4
#define led2 5

LiquidCrystal_I2C lcdmar(0x27,16,2);
OneWire ourWire(2);
DallasTemperature sensor(&ourWire);

int sensortF();
int sensortC();
int TempF, TempC;

byte termometro[] = {
  B01110,
  B01010,
  B01010,
  B01010,
  B10001,
  B10001,
  B10001,
  B01110
};

byte caliente[] = {
  B00000,
  B01111,
  B01000,
  B01000,
  B01000,
  B01000,
  B01111,
  B00000
};

byte frio[] = {
  B00000,
  B01111,
  B01000,
  B01110,
  B01000,
  B01000,
  B01000,
  B01000
};

byte templado[] = {
  B00000,
  B11111,
  B00100,
  B00100,
  B00100,
  B00100,
  B00100,
  B00100
};

byte grados[] = {
  B11100,
  B10100,
  B11100,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000
};

void setup() {
  Serial.begin(9600);   //Inicio la comunicacion serial
  lcdmar.init();  
  lcdmar.backlight();
  sensor.begin();   //Se inicia el sensor
  lcdmar.createChar(0, termometro);
  lcdmar.createChar(1, caliente);
  lcdmar.createChar(2, frio);
  lcdmar.createChar(3, templado);
  lcdmar.createChar(4, grados);
  lcdmar.home();
  pinMode(led0,OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(led1,OUTPUT);
}

void loop() {
   TempF = sensortF();
  TempC = sensortC();
 
 
  lcdmar.setCursor(0,0);
  lcdmar.print("  TERMOMETRO ");
  lcdmar.write(byte(0));
  //Temperatura en Celsius
  lcdmar.setCursor(2,1);
  lcdmar.print(TempC);
  lcdmar.write(byte(4));
  lcdmar.print("C");
  //Temperatura en Fahrenheit
  lcdmar.setCursor(8,1);
  lcdmar.print(TempF);
  lcdmar.write(byte(4));
  lcdmar.print("F ");


  if(TempC >= 15 && TempC <= 30){
    lcdmar.setCursor(13,1);
    lcdmar.write(byte(3));
    delay(800);
    lcdmar.setCursor(13,1);
    lcdmar.print(" ");
    digitalWrite(led0,LOW);
    digitalWrite(led1,LOW);
    digitalWrite(led2,HIGH);
  }

  if(TempC > 30){
    lcdmar.setCursor(13,1);
    lcdmar.write(byte(1));
    delay(800);
    lcdmar.setCursor(13,1);
    lcdmar.print(" ");
    digitalWrite(led0,HIGH);
    digitalWrite(led2,LOW);
    digitalWrite(led1,LOW);
  }

  if(TempC < 15){
    lcdmar.setCursor(13,1);
    lcdmar.write(byte(2));
    delay(800);
    lcdmar.setCursor(13,1);
    lcdmar.print(" ");
    digitalWrite(led0,LOW);
    digitalWrite(led2,LOW);
    digitalWrite(led1,HIGH);
  }
}

int sensortC(){
  sensor.requestTemperatures();  
  int temp= sensor.getTempCByIndex(0);
  return temp;
}

int sensortF(){
  sensor.requestTemperatures();  
  int temp1 = sensor.getTempFByIndex(0);
  return temp1;
}
