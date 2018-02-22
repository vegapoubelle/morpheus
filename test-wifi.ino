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

const char* ssid     = "phil's phone";
const char* password = "mechkeyb";
const char* host = "poubelle.online";
const int port = 80;
int masse = 42; // test value

void setup() {
  Serial.begin(9600);

  /* wait for garbage to go away */
  delay(500);
  Serial.println("");

  /* connecting to wifi */
  WiFi.begin(ssid, password);

  /* waiting for wifi to connect */
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.print("up: ");
  Serial.print(WiFi.localIP());
  Serial.print(" @ ");
  Serial.println(ssid);

  /******************** send stuff to the server */

  /* connection to the server */
  WiFiClient client;
  if (client.connect(host, port)) {
    /* message that we are connecting to the sever */
    Serial.print("connecting to ");
    Serial.println(host);

    /* send the http get request */
    client.print("GET /add.php?");

    /* send the value of 'masse' */
    client.print("masse=");
    client.print(masse);

    /* specify http spec version */
    client.println(" HTTP/1.1");

    /* put the host and the port */
    client.print("Host:");
    client.print(host);
    client.print(":");
    client.println(port);

    /* message to say success! */
    Serial.println("success!");
  } else {
    /* if the conneciton failed */
    Serial.println("connection failed");
    client.stop();
  }

  /* once the stuff has been sent, stop the wifi client */
  if (client.connected()) { 
    client.stop();
    Serial.println("wifi client stopped");
  }
}

void loop() {
  /* empty loop */
}

/* vim: set ts=2 sw=2 et : */

