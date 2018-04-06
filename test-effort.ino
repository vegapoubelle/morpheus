#include <Q2HX711.h>

Q2HX711 hx711(hx711_data_pin, hx711_clock_pin);

void test_effort() {
  int poids = (hx711.read()/100-85313)/4.4;
  Serial.print(poids);
  Serial.println(" grammes");
  delay(500);
}

/* vim: set ts=2 sw=2 et : */
