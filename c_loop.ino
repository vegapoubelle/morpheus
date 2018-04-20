/*
   c_loop.ino : la fonction qui tourne à ∞

   http://poubelle.online

*/

void loop() {
  /******************** wifi */
  test_effort();
  test_inductif();
  connect_server();
}
