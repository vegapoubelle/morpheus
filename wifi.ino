/*
 * ecran.ino : gestion de l'ecran lcd
 * 
 * par Philippe Loctaux (x4m3)
 * 
 * http://poubelle.online
 * 
 */

#include <WiFi.h>

const char* ssid     = "phil's phone";
const char* password = "mechkeyb";
const char* host = "poubelle.online";
const int port = 80;
int masse;

void setup() {
  /* define the led and turn it off */
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);

  /* start the serial display */
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
}

void loop() {
  /* connection to the server */
  WiFiClient client;
  if (client.connect(host, port)) {
    /* message that we are connecting to the sever */
    Serial.print("connecting to ");
    Serial.println(host);

    /* debug messages */
    masse = random(300);
    Serial.print("debug: ");
    Serial.println(masse);

    /* send the http get request */
    client.print("GET /php/add.php?");

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

    /* finish the http request */
    client.println("User-Agent: esp32-poubelle");
    client.println("Connection: close");
    client.println();

    /* message to say success! */
    Serial.println("success!");

    /* blink the led */
    digitalWrite(LED_BUILTIN, HIGH);
    delay(100);
    digitalWrite(LED_BUILTIN, LOW);

  } else {
    /* if the conneciton failed */
    Serial.println("connection failed");
    Serial.println("");
    client.stop();
  }

  /* debug: get reply from the server
  while(client.available()) {
    char c = client.read();
    Serial.print(c);
  }
  */

  /* once the stuff has been sent, stop the wifi client */
  if (client.connected()) {
    client.stop();
    Serial.println("wifi client stopped");
    Serial.println("");
  }

  delay(1000);
}

/* vim: set ts=2 sw=2 et : */

