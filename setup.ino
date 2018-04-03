/* void setup */

void setup() {
  Serial.begin(9600);

  /* esp: wait for garbage to go away */
  delay(500);
  Serial.println("");

  /******************** ecran */
  /* generate the high voltage from the 3.3v line internally */
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);

  splash_logo_text();


  /******************** wifi */
  connect_wifi();
  connect_server();
}

/* vim: set ts=2 sw=2 et : */
