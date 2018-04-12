/*
   a_variables.ino: declaration des variables

   http://poubelle.online

*/

/* wifi */
const char* ssid     = "deadbaed";
const char* password = "mechkeyb";
const char* host = "poubelle.online";
const int port = 80;
int masse;

/* ecran */
const int delay_ecran = 2500;

/* inductif */
const int capteur_inductif = 13;

/* effort */
const byte hx711_data_pin = 18;
const byte hx711_clock_pin = 23;

/* moteur */
#define MOTOR_STEPS 200
#define RPM 120
#define MICROSTEPS 1
#define DIR 15
#define STEP 2
