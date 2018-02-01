/*
 * test-wifi: test du wifi pour l'esp32
 * 
 * http://poubelle.online
 * https://goo.gl/6rx6EG
 */

#include <WiFi.h>

const char* w_net = "ssid";
const char* w_psw = "pssw";

void setup() {
  Serial.begin(9600);
  WiFi.begin(w_net, w_psw);


  while (Wifi.status() != WL_CONNECTED) {
    delay(500);
    Serial.println("connexion au wifi.......");
  }

  Serial.println("connexion etablie");
}

void loop() {
  //
}

/* vim: set tabstop=2: */
