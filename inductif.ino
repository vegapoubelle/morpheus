/*
   inductif.ino : le capteur inductif

   http://poubelle.online

*/

void test_inductif() {

  if (digitalRead(capteur_inductif) == 1)
    matiere = 1;
  else
    /* set matiere to something else */

}
