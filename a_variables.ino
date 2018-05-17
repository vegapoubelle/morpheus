/*
   a_variables.ino: declaration des variables

   http://poubelle.online

*/

/* wifi */
char const *wifi_network = "deadbaed";
char const *wifi_password = "mechkeybb";
char const *host = "poubelle.online";
const int port = 80;

/* matiere et masse */
int masse, matiere = 4;

/* ecran */
const int delay_ecran = 2500;

/* inductif */
const int capteur_inductif = 13;

/* effort */
const byte hx711_data_pin = 23;
const byte hx711_clock_pin = 18;

/* moteur */
#define MOTOR_STEPS 200
#define RPM 120
#define MICROSTEPS 1
#define DIR 15
#define STEP 2
