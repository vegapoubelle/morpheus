/*
   tri.ino : cycle de tri pour l'esp32

   par Yann Le Guehennec

   https://poubelle.online
   https://github.com/vegapoubelle

*/


/* Liste de trucs a trier :

    * métaux
    * poids
    * rigidité


    étapes de tri:
    1. Métaux
         oui: dans le bac métal
    2. Phototransistor (transparence)
         si oui:
 		poids +- valeur: dans le bac x
 		poids +- valeur: dans le bac y
 		poids +- valeur: dans le bac z
    2. Rigidité
         si oui:
 		poids +- valeur: dans le bac verre
 		poids +- valeur: dans le bac plastique
         si non:
 		poids +- valeur: dans le bac plastique
 		poids +- valeur: dans le bac autre

*/

/* vim: set ts=2 sw=2 et : */
