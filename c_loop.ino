/*
   c_loop.ino : la fonction qui tourne à ∞

   http://poubelle.online

*/

void loop() {
  /* tri(); sans le palpeur */
  tri_potentio();
  splash_weight_text();
  connect_server();
}
