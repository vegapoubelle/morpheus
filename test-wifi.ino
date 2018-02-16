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
const int httpPort = 80;
String url = "/test.txt";

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

  /* connect to the server */
  Serial.print("connecting to ");
  Serial.println(host);

  /* create tcp connexion */
  WiFiClient client;
  if (!client.connect(host, httpPort)) {
    Serial.println("connection failed");
    return;
  }

  Serial.println("connected!");

  /* PUSH SHIT 
    !!!!!!!!!!!!!!!!!!!!!  */

  int data = 42;

  if (client.connect(host,httpPort)) { 
    client.println("POST /add.php HTTP/1.1"); 
    client.print("Host: ");
    client.println(host);
    client.println("Content-Type: application/x-www-form-urlencoded"); 
    client.print("Content-Length: "); 
    client.println(data); 
  } 

  if (client.connected()) { 
    client.stop();
  }
}

void loop() {
  /* empty loop */
}

  /* DOWNLOAD SHIT
   * !!!!!!!!!!!!! 

  Serial.print("Requesting URL: ");
  Serial.println(url);

  // request url to host 
  client.print(String("GET ") + url + " HTTP/1.1\r\n" +
      "Host: " + host + "\r\n" +
      "Connection: close\r\n\r\n");
  unsigned long timeout = millis();
  while (client.available() == 0) {
    if (millis() - timeout > 5000) {
      Serial.println(">>> Client Timeout !");
      client.stop();
      return;
    }
  }

  // read reply and print to serial 
  while(client.available()) {
    String line = client.readStringUntil('\r');
    Serial.print(line);
  }

  Serial.println();
  Serial.println("closing connection");

  **** END TO DOWNLOAD SHIT */


/* vim: set ts=2 sw=2 et : */

