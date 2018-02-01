/* note: il faut installer les bibliotheques
   https://github.com/adafruit/Adafruit-GFX-Library
   https://github.com/vegapoubelle/Adafruit_SSD1306
*/

#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define OLED_RESET 4
Adafruit_SSD1306 display(OLED_RESET);

#if (SSD1306_LCDHEIGHT != 64)
#error("Height incorrect, please fix Adafruit_SSD1306.h!");
#endif

void setup()   {
  Serial.begin(9600);

  /* by default, we'll generate the high voltage from the 3.3v line internally! (neat!) */
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);

  display.clearDisplay();

  display.setCursor(0, 0);
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.println("poubelle.online");
  display.display();
}

void loop() {
  /* empty atm */
}

/* vim: set tabstop=2: */
