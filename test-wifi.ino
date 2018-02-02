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
 *
 * command on arch: "openssl s_client -showcerts -connect poubelle.online:443 </dev/null "
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


  Serial.println("connexion au server sur le port 443");
  if (!client.connect(server, 443)) {
    Serial.println(":(");
  } else {
    Serial.println(":)");
    /* create HTTPS request */
    client.println("GET https://poubelle.online HTTP/1.0");
    client.println("Host: poubelle.online");
    client.println("Connection: close");
    client.println();

    Serial.print("en attente d'une reponse");
    while (!client.available()) {
      delay(50);
      Serial.print(".");
    }

    /* if data is available then receive and print to Terminal */
    while (client.available()) {
      char c = client.read();
      Serial.write(c);
    }

    /* if the server disconnected, stop the client */
    if (!client.connected()) {
      Serial.println();
      Serial.println("Server disconnected");
      client.stop();
    }
  }
}

void loop() {
  /* empty loop */
}

/* vim: set ts=2 sw=2 sts=2 et : */
