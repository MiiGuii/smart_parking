/*
  Capitulo 48 de Arduino desde cero en Español.
  Programa que muestra los valores de la magnitud del campo magnetico sobre los 3 ejes
  del magnetometro y el valor calculado de acimut magnetico
  Requiere instalar libreria MechaQMC5883

  Autor: bitwiseAr  

*/

#include <Wire.h>   // incluye libreria bus I2C
#include <MechaQMC5883.h> // incluye libreria para magnetometro QMC5883L

MechaQMC5883 qmc;   // crear objeto

void setup() {
  Wire.begin();     // inicializa bus I2C
  Serial.begin(9600);   // inicializa monitor serie a 9600 bps
  qmc.init();     // inicializa objeto
}

void loop() {
  int x,y,z,acimut;   // variables para los 3 ejes y acimut
  qmc.read(&x,&y,&z,&acimut); // funcion para leer valores y asignar a variables

  Serial.print("x:");   // muestra texto x:
  Serial.print(x);    // muestra valor de variable x
  Serial.print("\t");   // espacio de tabulacion
  Serial.print("y:");   // muestra y:
  Serial.print(y);    // muestra valor de variable y
  Serial.print("\t");   // espacio de tabulacion
  Serial.print("z:");   // muestra texto z:
  Serial.print(z);    // muestra valor de variable z
  Serial.print("\t");   // espacio de tabulacion
  Serial.print("a:");   // muestra texto a:
  Serial.println(acimut); // muestra valor de variable acimut
 
  delay(250);     // demora de 250 mseg.
}
