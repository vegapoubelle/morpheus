/*
   wifi.ino : gestion du wifi

   http://poubelle.online

*/

#include <WiFi.h>

void connect_wifi() {
  /* started wifi */
  Serial.println("wifi: started");

  /* disconnect from wifi first */
  WiFi.disconnect();
  Serial.println("wifi: disconnected");

  /* connecting to wifi */
  WiFi.begin(wifi_network, wifi_password);

  /* waiting for wifi to connect */
  Serial.println("wifi: if you can't connect, make sure the ssid and password are correct, the wifi router is on, and reboot the device");
  Serial.print("wifi: connecting to network");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  /* success in console and display */
  Serial.println(" connected!");
  splash_wifi_connected_text();

  /* display ip and ssid of current network */
  Serial.print("wifi: ip address: ");
  Serial.println(WiFi.localIP());

  Serial.print("wifi: network ssid: ");
  Serial.println(wifi_network);
}

void connect_server() {
  /* connection to the server */
  WiFiClient client;
  if (client.connect(host, port)) {
    /* message in console and display */
    Serial.println("wifi: the following data will be sent:");
    Serial.println("**************************************");

    Serial.print("masse: ");
    Serial.println(masse);

    Serial.print("matiere: ");
    Serial.println(matiere);
    Serial.println("**************************************");

    splash_wifi_send_text();

    /* start the http get request */
    client.print("GET /php/add.php?");

    /* send the value of 'masse' */
    client.print("masse=");
    client.print(masse);

    /* separation for other variables */
    client.print("&");

    /* send the value of "matiere"
     * 1: metal
     * 2: verre
     * 3: plastique
     * 4: autre
     */
    client.print("matiere=");
    client.print(matiere);

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
}
