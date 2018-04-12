/*
   effort.ino : le capteur d'effort

   http://poubelle.online

*/

#include <Q2HX711.h>

Q2HX711 hx711(hx711_data_pin, hx711_clock_pin);

void test_effort() {
  int poids = (hx711.read()/100-84406)/10;
  Serial.print(poids);
  Serial.println(" grammes");
  delay(500);
}
