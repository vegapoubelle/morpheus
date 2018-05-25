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
long masse;

/*
 * 1: metal
 * 2: verre
 * 3: plastique
 * 4: autre
 */
int matiere;

/* ecran */
const int delay_ecran = 2500;

/* inductif */
const int capteur_inductif = 13;
bool est_inductif;

/* effort */
const byte hx711_data_pin = 23;
const byte hx711_clock_pin = 18;

/* moteur */
#define MOTOR_STEPS 200
#define RPM 120
#define MICROSTEPS 1
#define DIR 15
#define STEP 2

/* potentiometre et palpeur */
const int avance = 17;
const int arriere = 16;
const int Enable = 4;   //sortie PWM avec LedC pour faire varier la vitesse
//potentiomètre palpeur sur A4
//courant palpeur sur A5
const int BP = 25;     //ATTENTION cette entrée sera utilisée plus tard comme capteur origine moteur de rotation
boolean obstacle=false;  // detection augmentation du courant moteur du palpeur
int compt_temps=0;
int position1;  //mémorisation de la première position du palpeur au moment de la détection d'obstacle
int position2;  //mémorisation de la deuxième position du palpeur 0.5s en vitesse max après la détection d'obstacle
