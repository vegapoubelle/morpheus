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

/* potentiometre et palpeur
 *
 * fyi:
 * le potentiometre palpeur est sur A4
 * le courant palpeur est sur A5
 */

/* broches pour faire avancer le moteur */
const int avance = 17;
const int arriere = 16;

/* sortie PWM avec LedC pour variation de vitesse */
const int Enable = 4;

/* detection augmentation du courant moteur du palpeur */
boolean obstacle = false;

/* compteur de temps */
int compt_temps=0;

/* memorisation de la premiere et seconde position du palpeur */
int position1, position2;
