/*
  Fundación Kinal
  Centro Educativo Técnico Labral Kinal
  Electrónica
  Grado: Quinto
  Sección: A
  Curso: Taller de Electrónica Digital y Reparación de Computadoras I
  Nombre: Alvaro Josue Antonio Marroquin Corado
  Carné: 2022375
  proyecto:SENSOR DE PARQUEO
*/
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#define trig 2
#define echo 3

int medidas; 
int i, a;
int medicion();

LiquidCrystal_I2C lcdmar(0x27, 16, 2);

byte mar[] = {
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111
};

void setup() {
  Serial.begin(9600);
  lcdmar.init();
  lcdmar.backlight();
  lcdmar.createChar(0, mar);
  lcdmar.home();
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT); 
  digitalWrite(trig, LOW); 
}

void loop() {
  medidas = medicion();
  if (medidas >70) {
    lcdmar.clear();
  }
  switch (medidas) {
    case 50:
      lcdmar.setCursor(7, 0);
      lcdmar.print("50    ");
      lcdmar.setCursor(0, 1);
      lcdmar.print("     LIBRE     ");
      i = 0;
      a = 13;
      for (i == 0; i <= 2; i++) {
        lcdmar.setCursor(i, 0);
        lcdmar.write(byte(0));
        lcdmar.setCursor(3, 0);
        lcdmar.print("    ");
      }
      for (a == 13; a <= 15; a++) {
        lcdmar.setCursor(a, 0);
        lcdmar.write(byte(0));
      }
      break;

    case 30:
      lcdmar.setCursor(7, 0);
      lcdmar.print("30  ");
      lcdmar.setCursor(0, 1);
      lcdmar.print("    CUIDADO!     ");
      i = 0;
      a = 11;
      for (i == 0; i <= 4; i++) {
        lcdmar.setCursor(i, 0);
        lcdmar.write(byte(0));
        lcdmar.setCursor(5, 0);
        lcdmar.print("  ");
      }
      for (a == 11; a <= 15; a++) {
        lcdmar.setCursor(a, 0);
        lcdmar.write(byte(0));
      }
      break;

    case 10:
      lcdmar.setCursor(7, 0);
      lcdmar.print("10");
      lcdmar.setCursor(0, 1);
      lcdmar.print("     ALTO!     ");
      i = 0;
      a = 9;
      for (i == 0; i <= 6; i++) {
        lcdmar.setCursor(i, 0);
        lcdmar.write(byte(0));
      }
      for (a == 9; a <= 15; a++) {
        lcdmar.setCursor(a, 0);
        lcdmar.write(byte(0));
      }
      break;
  }
}

int medicion() {
  long d; 
  long t; 
  digitalWrite(trig, HIGH);
  delayMicroseconds(10); 
  digitalWrite(trig, LOW);

  t = pulseIn(echo, HIGH); 
  d = t / 58; 
  Serial.println(d);
  return d;
}
