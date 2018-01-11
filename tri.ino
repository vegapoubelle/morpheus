/*
 * tri.ino : cycle de tri pour l'esp32
 * 
 * par Yann Le Guehennec
 * 
 * https://poubelle.online
 * https://github.com/vegapoubelle
 * 
 */


 /* Liste de truc a trier :
  *  * métaux
  *  * poids
  *  * rigidité
  *  
  *  
  *  étapes de tri:
  *  1. Métaux
  *       oui: dans le bac métal
  *  2. Rigidité
  *       si oui et poids > valeur: dans le bac verre
  *       si oui et poids < valeur: dans le bac plastique
  *       non: 
  *  
  *  
  */
