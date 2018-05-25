/*
   b_setup.ino : la fonction setup

   http://poubelle.online

*/

void setup() {
  Serial.begin(9600);

  /* capteur inductif */
  pinMode(capteur_inductif, INPUT);

  /* moteur */
  init_moteur();

  /* potentiometre */
  pinMode(avance, OUTPUT);
  pinMode(arriere, OUTPUT);
  digitalWrite(avance, LOW);
  digitalWrite(arriere, LOW);
  ledcSetup(LEDC_CHANNEL_0, LEDC_BASE_FREQ, LEDC_TIMER_13_BIT);
  ledcAttachPin(Enable, LEDC_CHANNEL_0);

  pinMode(BP, INPUT); //ATTENTION cette entrée sera utilisée plus tard comme capteur origine moteur de rotation

  /* esp: wait for garbage to go away */
  delay(500);
  Serial.println("");

  /* serial: programme & version */
  Serial.print("programme ");
  Serial.println(codename);

  Serial.print("version ");
  Serial.println(version);

  /******************** ecran: init & splash */
  init_display();
  splash_logo_text();

  /******************** wifi: text & connect to network */
  splash_wifi_init_text();
  connect_wifi();
}
