/*
   Fundacion Kinal
   Centro educativo tecnico laboral Kinal
   Quinto perito
   Quinto electronica
   Codigo Tecnico: EB5AM / EB5AV
   Curso: Taller de electronica digital y reparacion de computadoras I
   Proyecto: lcd y arduno
   ALUMNO: Alvaro Marroquin
   Profe. Alejandro Lopez Navas
   Fecha: 4 de mayo
*/
#include <LiquidCrystal.h>


#define rs    2
#define enab  3
#define D4    4
#define D5    5
#define D6    6
#define D7    7
 LiquidCrystal LCD_Alvaro(rs,enab,D4,D5,D6,D7);
void setup() {
  // put your setup code here, to run once:
LCD_Alvaro.begin(16,2);

}

void loop() {
LCD_Alvaro.setCursor(0,0);
LCD_Alvaro.print("Alvaro Marroquin");
LCD_Alvaro.setCursor(0,1);
LCD_Alvaro.print("2022375");
}
