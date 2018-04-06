//Fonctionnement OK sur ESP32 après modification de la bibliothèque Q2HX711.h
//Voir le fichier Q2HX711.cpp de la bibliothèque pour éventuellement modifier le gain de la carte HX711 (le gain par défaut est de 128. C'est le gain le plus élevé)    
#include <Q2HX711.h>

const byte hx711_data_pin = 34;
const byte hx711_clock_pin = 25;
//const byte hx711_clock_pin = 35;  //ne fonctionne pas avec cette broche! Pb sur Entrée-sortie 35 ESP32? 

Q2HX711 hx711(hx711_data_pin, hx711_clock_pin);

void setup() {
  Serial.begin(9600);
}

void loop() {
  int poids = (hx711.read()/100-85313)/4.4;
  Serial.print(poids);
  Serial.println(" grammes");
  delay(500);
}

/* vim: set ts=2 sw=2 et : */
