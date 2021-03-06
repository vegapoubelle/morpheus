/*
   cycle_complet_palpeur.ino: cycle de tri avec le palpeur

   http://poubelle.online

*/

void tri_potentio() {
  /* dont do anything if the weight is under 0 grams */
  while (test_effort() <= 0) {
    splash_weight_waiting_text();
    show_weight();
  }

  matiere = 0;
  compt_temps = 0;
  obstacle = false;

  while ((matiere == 0) && (compt_temps < 500)) { /* 1ère sortie Palpeur */
    digitalWrite(avance, HIGH);
    delay(2);
    compt_temps++;
    if (analogRead(A5) > 650) { /* détection obstacle si tension A5 > 1.15V */
      Serial.println(analogRead(A5));
      obstacle = true;
    }
    if (obstacle == false)
      ledcWrite(LEDC_CHANNEL_0, 6500); /* sortie petite vitesse */
    else
      ledcWrite(LEDC_CHANNEL_0, 8191); /* sortie vitesse max */
    if (digitalRead(capteur_inductif) == HIGH)
      matiere = 1; /* déchet métalique */
    if (analogRead(A4) > 4000) /* si curseur complètement sortie */
      matiere = 4; /* autre déchet */
  }

  digitalWrite(avance, LOW); /* Arrêt moteur */
  ledcWrite(LEDC_CHANNEL_0, 0); /* rapport cyclique de 0 à 8191 */
  delay(500);

  while (analogRead(A4) > 100) { /* Rentrée Palpeur */
    digitalWrite(arriere, HIGH);
    ledcWrite(LEDC_CHANNEL_0, 6500); /* rapport cyclique: 0-8191 (min 6000) */
  }

  digitalWrite(arriere, LOW); /* Arrêt moteur */
  ledcWrite(LEDC_CHANNEL_0, 0);   /* rapport cyclique de 0 à 8191 */
  delay(500);

  while (matiere == 0) { /* 2ème sortie Palpeur */
    digitalWrite(avance, HIGH);
    ledcWrite(LEDC_CHANNEL_0, 6000); /* sortie petite vitesse */
    if (analogRead(A5) > 1010) { /* détection obstacle si tension A5 > 1.15V */
      position1 = analogRead(A4);
      ledcWrite(LEDC_CHANNEL_0, 8191); /* sortie vitesse max */
      delay(350);
      position2 = analogRead(A4);
      position1 = position1 + 8;
      position2 = position2 + 1;
      if (position2 > position1)
        matiere = 3; /* détection plastique ou carton */
      else
        matiere = 2; /* détection verre */
      Serial.print("position1 :");
      Serial.println(position1);
      Serial.print("position2 :");
      Serial.println(position2);
    }
  }
  digitalWrite(avance, LOW); /* Arrêt moteur */
  ledcWrite(LEDC_CHANNEL_0, 0); /* rapport cyclique de 0 à 8191 */
  delay(500);

  while (analogRead(A4) > 100) { /* Rentrée Palpeur */
    digitalWrite(arriere, HIGH);
    ledcWrite(LEDC_CHANNEL_0, 6500); /* rapport cyclique: 0-8191 (min 6000) */
  }

  digitalWrite(arriere, LOW); /* Arrêt moteur */
  ledcWrite(LEDC_CHANNEL_0, 0); /* rapport cyclique de 0 à 8191 */

  Serial.print("matiere detectee :");
  switch (matiere) {
    case 1:
      show_weight();
      Serial.println();
      Serial.println("metal");
      Serial.println();
      break;
    case 2:
      show_weight();
      Serial.println();
      Serial.println("verre");
      Serial.println();
      break;
    case 3:
      show_weight();
      Serial.println();
      Serial.println("plastique");
      Serial.println();
      break;
    case 4:
      show_weight();
      Serial.println();
      Serial.println("autre");
      Serial.println();
      break;
  }
}
