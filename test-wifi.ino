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

/* tls certificate:
 *
 * linux: install `openssl`
 * windows: check online `openssl client windows`
 */
const char* cert =\
"cert goes here\n" \
"multiple lines are done like that\n";

/* make an instance of WiFiClientSecure */
WiFiClientSecure client;

void setup() {
  Serial.begin(9600);
  WiFi.begin(network, password);

  /* waiting for wifi to connect */
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }

  Serial.print("connexion etablie au reseau: ");
  Serial.println(network);

  /* setup the tls certificate */
  client.setCACert(cert);
}

void loop() {
  //
}

/* vim: set ts=2 sw=2 sts=2 et : */
