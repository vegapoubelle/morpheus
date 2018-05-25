/*
   cycle_complet_palpeur.ino: cycle de tri avec le palpeur

   http://poubelle.online

*/

// use first channel of 16 channels (started from zero)
#define LEDC_CHANNEL_0     0

#define LEDC_TIMER_13_BIT  13

// use 5000 Hz as a LEDC base frequency
#define LEDC_BASE_FREQ     10000

void loop()
{
	while( digitalRead(BP) == LOW)   //Attendre action sur BP (court-circuiter le bornier origine moteur avec un fil)

	matiere = 0;
	compt_temps = 0;
	obstacle = false;

	while ( (matiere ==0) && (compt_temps <500) ) /*1ère sortie Palpeur */
	{  digitalWrite(avance, HIGH);
		delay(2);
		compt_temps++;
		if ( analogRead(A5) > 650 )  //détection obstacle si tension A5 > 1.15V
      {
      Serial.println (analogRead(A5));
			obstacle = true;
      }
		if ( obstacle == false )
      {
			ledcWrite( LEDC_CHANNEL_0, 6500); //sortie petite vitesse
      }
		else
      {
			ledcWrite( LEDC_CHANNEL_0, 8191);   //sortie vitesse max
      }
		if ( digitalRead(capteur_inductif) == HIGH)
			matiere =1;  //déchet métalique
		if (analogRead(A4) > 4000) //si curseur complètement sortie
			matiere =2;   //autre déchet
	}
	digitalWrite(avance, LOW);  /*Arrêt moteur */
	ledcWrite( LEDC_CHANNEL_0, 0);   //rapport cyclique de 0 à 8191
	delay(500);

	while ( analogRead(A4) > 100 ) /* Rentrée Palpeur */
	{  digitalWrite(arriere, HIGH);
		ledcWrite( LEDC_CHANNEL_0, 6500);   //rapport cyclique de 0 à 8191 (6000 est le minimum pour déplacer le curseur)
	}
	digitalWrite(arriere, LOW); /* Arrêt moteur */
	ledcWrite( LEDC_CHANNEL_0, 0);   //rapport cyclique de 0 à 8191
	delay(500);


	while ( matiere ==0 ) /* 2ème sortie Palpeur */
	{  digitalWrite(avance, HIGH);
		ledcWrite( LEDC_CHANNEL_0, 6000);   //sortie petite vitesse
    Serial.println (analogRead(A5));
		if ( analogRead(A5) > 1010)  //détection obstacle si tension A5 > 1.15V
		{  position1 = analogRead(A4);
			ledcWrite( LEDC_CHANNEL_0, 8191);   //sortie vitesse max
			delay(350);
			position2 = analogRead(A4);
      position1 = position1 + 8;
      position2 = position2 + 1;
			if (position2  > position1)
			matiere = 4; // détection plastique ou carton
			else
			matiere = 3; // détection verre

			Serial.print("position1 :");
			Serial.println(position1);
			Serial.print("position2 :");
			Serial.println(position2);
		}
	}
	digitalWrite(avance, LOW); /* Arrêt moteur */
	ledcWrite( LEDC_CHANNEL_0, 0);   //rapport cyclique de 0 à 8191
	delay(500);


	while ( analogRead(A4) > 100 ) /* Rentrée Palpeur */
	{  digitalWrite(arriere, HIGH);
		ledcWrite( LEDC_CHANNEL_0, 6500);   //rapport cyclique de 0 à 8191 (6000 est le minimum pour déplacer le curseur)
	}
	digitalWrite(arriere, LOW);  /* Arrêt moteur */
	ledcWrite( LEDC_CHANNEL_0, 0);   //rapport cyclique de 0 à 8191

	Serial.print("matiere detectee :");
	switch (matiere) {
	case 1:
		Serial.println("metal");
		break;
	case 2:
		Serial.println("autre");
		break;
	case 3:
		Serial.println("verre");
		break;
	case 4:
		Serial.println("plastique");
		break;
	}
}
