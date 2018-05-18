/*
   effort.ino : le capteur d'effort

   http://poubelle.online

*/

#include <Q2HX711.h>

Q2HX711 hx711(hx711_data_pin, hx711_clock_pin);

/* function to get the current weight */
int test_effort() {
	masse = ((hx711.read()-9105750)/1006);
	return masse;
}
