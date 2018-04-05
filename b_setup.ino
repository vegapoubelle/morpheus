/*
   b_setup.ino : la fonction setup

   http://poubelle.online

*/

void setup() {
  Serial.begin(9600);

  /* esp: wait for garbage to go away */
  delay(500);
  Serial.println("");

  /* serial: programme & version */
  Serial.print("programme ");
  Serial.println(codename);

  Serial.print("version ");
  Serial.println(version);

  /******************** ecran */
  init_display();
  splash_logo_text();


  /******************** wifi */
  connect_wifi();
}

/* vim: set ts=2 sw=2 et : */
