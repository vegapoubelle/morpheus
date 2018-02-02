/*
 * test-wifi: test du wifi pour l'esp32
 * 
 * http://poubelle.online
 * https://goo.gl/6rx6EG
 */

#include <WiFi.h>

const char* network = "ssid";
const char* password = "pssw";
const char* server = "poubelle.online";

void setup() {
  Serial.begin(9600);
  WiFi.begin(network, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.println("connexion au wifi.......");
  }

  Serial.println("connexion etablie");
}

void loop() {
  //
}

/* vim: set ts=2 sw=2 sts=2 et : */
