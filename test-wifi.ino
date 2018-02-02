/*
 * test-wifi: test du wifi pour l'esp32
 * 
 * http://poubelle.online
 * https://goo.gl/6rx6EG
 * https://github.com/copercini/esp32-iot-examples/blob/master/ESP32_aws_iot/ESP32_aws_iot.ino
 * https://techtutorialsx.com/2017/11/18/esp32-arduino-https-get-request/
 * https://techtutorialsx.com/2017/05/19/esp32-http-get-requests/
 */

#include <WiFi.h>

const char* network = "phil's phone";
const char* password = "mechkeyb";

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

}

void loop() {
  /* empty loop */
}

/* vim: set ts=2 sw=2 sts=2 et : */
