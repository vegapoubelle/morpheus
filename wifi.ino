/*
   wifi.ino : gestion du wifi

   par Philippe Loctaux (x4m3)

   http://poubelle.online

*/

#include <WiFi.h>

void connect_wifi() {
  /* started wifi */
  Serial.println("wifi: started");

  /* connecting to wifi */
  WiFi.begin(ssid, password);

  /* waiting for wifi to connect */
  Serial.println("wifi: if you can't connect, make sure the ssid and password are correct, the wifi router is on, and reboot the device");
  Serial.print("wifi: connecting to network");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  /* display ip and ssid of current network */
  Serial.println(" connected!");

  Serial.print("wifi: ip address: ");
  Serial.println(WiFi.localIP());

  Serial.print("wifi: network ssid: ");
  Serial.println(ssid);
}

void connect_server() {
  /* connection to the server */
  WiFiClient client;
  if (client.connect(host, port)) {
    /* message that we are sending stuff to the server */
    Serial.println("wifi: the following data will be sent:");
    Serial.println("**************************************");

    /* print variables that we wanna send to the server */
    masse = random(300);
    Serial.print("masse: ");
    Serial.println(masse);
    Serial.println("**************************************");

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
    Serial.println("wifi: information sent to the server !");

  } else {
    /* if the conneciton failed */
    Serial.println("wifi: connection failed to the server");
    Serial.println("wifi: if you lost your wifi network, please reboot the device");
    Serial.println("wifi: you also may wanna check if the server is not offline");
    Serial.println("");
    client.stop();
  }

  /* debug: get reply from the server
    while(client.available()) {
    char c = client.read();
    Serial.print(c);
    }
  */

  /* once data has been sent, stop the wifi client */
  if (client.connected()) {
    client.stop();
    Serial.println("wifi: client stopped");
    Serial.println("");
  }

  delay(3000);

}

/* vim: set ts=2 sw=2 et : */

