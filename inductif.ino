/*
   inductif.ino : le capteur inductif

   http://poubelle.online

*/

/* function to test if it's a metal or not */
bool test_inductif() {
  if (digitalRead(capteur_inductif) == 1)
    est_inductif = true;
  else
    est_inductif = false;

  return est_inductif;
}
