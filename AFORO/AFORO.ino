/*
Fundación Kinal
Centro Educativo Técnico Labral Kinal 
Electrónica
Grado: Quinto
Sección: A
Curso: Taller de Electrónica Digital y Reparación de Computadoras I
Nombre: ALVARO MARROQUIN
Carné: 2022375
*/

#include <LiquidCrystal.h>


#define rs    2
#define enab  3
#define D4    4
#define D5    5
#define D6    6
#define D7    7
int contador = 0;
int trig   = 8;
int echo   = 9;
int buzzer = 10;
int tiempo;
int distancia;

LiquidCrystal LCD_Alvaro(rs,enab,D4,D5,D6,D7);

byte customChar[] = {
  B01110,
  B01110,
  B10101,
  B01110,
  B00100,
  B00100,
  B01010,
  B10001
};

 void setup(){
  LCD_Alvaro.begin(16, 2);
  LCD_Alvaro.createChar(0, customChar);
  LCD_Alvaro.home();
  LCD_Alvaro.write(1);
  
  pinMode(buzzer,OUTPUT);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  Serial.begin(9600);
   LCD_Alvaro.begin(16,2);
 }
 void loop(){
  digitalWrite(trig, HIGH);
  delay(1);
  digitalWrite(trig, LOW);
  tiempo=pulseIn(echo, HIGH);
  distancia=tiempo/50.2;

  if ((distancia>6) && (distancia<10)){
  contador++;}
  if(contador<17){
   delay(500); 
    LCD_Alvaro.setCursor(0,0);
LCD_Alvaro.print("personas");
LCD_Alvaro.setCursor(0,1);
    
LCD_Alvaro.println(contador);
    
}
   if ((contador>17)){
      
LCD_Alvaro.setCursor(0,0);
LCD_Alvaro.print("lleno");
LCD_Alvaro.clear();
LCD_Alvaro.setCursor(0,1);
LCD_Alvaro.clear();                    
    delay(100);
     tone(buzzer,260);
   delay(500);
   noTone(buzzer);
     contador=16;

     LCD_Alvaro.setCursor(0,0); 
   LCD_Alvaro.write(byte(0)); 
   LCD_Alvaro.setCursor(15,0); 
   LCD_Alvaro.write(byte(0));
   delay(500);
   LCD_Alvaro.setCursor(0,0); 
   LCD_Alvaro.write(byte(1)); 
   LCD_Alvaro.setCursor(15,0); 
   LCD_Alvaro.write(byte(1));
   delay(500);
   LCD_Alvaro.setCursor(0,0); 
   LCD_Alvaro.write(" "); 
   LCD_Alvaro.setCursor(15,0); 
   LCD_Alvaro.write(" ");
   tone(buzzer,260);
   delay(500);
   noTone(buzzer);
   }
   }
