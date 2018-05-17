/*
   tri-sans-potentio.ino: tri sans le potentio

http://poubelle.online

 */

/*
 * matiere:
 * 1: metal
 * 2: verre
 * 3: plastique
 * 4: autre
 */

void tri() {
  /* dont do anything if the weight is under 0 grams */
  while (test_effort() <= 0)
    message();

  /* if the object is a metal */
  if (test_inductif() == true) {
    matiere = 1;
    message();
    Serial.println();
    Serial.println("metal");
    Serial.println();
  }

  /* if the object is under 125 grams, it's plastic */
  else {
    if (test_effort() <= 125) {
      matiere = 3;
      message();
      Serial.println();
      Serial.println("plastique");
      Serial.println();
    }

    /* if the object is above 125 grams, it's glass */
    else {
      matiere = 2;
      message();
      Serial.println();
      Serial.println("verre");
      Serial.println();
    }
  }
}

/* print the current weight */
void message() {
  Serial.print("poids: ");
  Serial.print(test_effort());
  Serial.println(" grammes");
}
