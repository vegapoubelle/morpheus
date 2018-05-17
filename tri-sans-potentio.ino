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
  while (test_effort() <= 0) {
    splash_weight_waiting_text();
    show_weight();
  }

  /* if the object is a metal */
  if (test_inductif() == true) {
    matiere = 1;
    show_weight();
    Serial.println();
    Serial.println("metal");
    Serial.println();
  }

  /* if the object is under said weight, it's plastic */
  else {
    if (test_effort() <= 175) {
      matiere = 3;
      show_weight();
      Serial.println();
      Serial.println("plastique");
      Serial.println();
    }

    /* if the object is above the weight above, it's glass */
    else {
      matiere = 2;
      show_weight();
      Serial.println();
      Serial.println("verre");
      Serial.println();
    }
  }
}

/* print the current weight */
void show_weight() {
  Serial.print("poids: ");
  Serial.print(test_effort());
  Serial.println(" grammes");
}
