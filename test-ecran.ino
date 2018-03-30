/* note: il faut installer les bibliotheques
   https://github.com/adafruit/Adafruit-GFX-Library
   https://github.com/vegapoubelle/Adafruit_SSD1306
*/

#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

String codename = "Morpheus";
String version = "0.0.1";

#define OLED_RESET 4
Adafruit_SSD1306 display(OLED_RESET);

/* made with http://javl.github.io/image2cpp */
#define LOGO_WIDTH  128
#define LOGO_HEIGHT 64
const unsigned char logo [] PROGMEM = {
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfb, 0xff, 0xaf, 0xff, 0xff, 0xd7, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfb, 0xff, 0xaf, 0xff, 0xff, 0xdf, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfb, 0xff, 0xaf, 0xff, 0xff, 0xdf, 0xff, 0xff, 0xff,
  0xff, 0xff, 0x6d, 0x6d, 0x6d, 0xe1, 0xc6, 0xe8, 0x71, 0xac, 0x7e, 0x34, 0xd5, 0x38, 0xff, 0xff,
  0xff, 0xff, 0x6d, 0x6d, 0x6d, 0xee, 0xba, 0xeb, 0xae, 0xab, 0xbd, 0xd3, 0x54, 0xd7, 0x7f, 0xff,
  0xff, 0xff, 0x55, 0x55, 0x55, 0xee, 0xba, 0xeb, 0xa0, 0xa8, 0x3d, 0xd7, 0x55, 0xd0, 0x7f, 0xff,
  0xff, 0xff, 0xbb, 0xbb, 0xbb, 0xee, 0xba, 0xcb, 0xaf, 0xab, 0xfd, 0xd7, 0x55, 0xd7, 0xff, 0xff,
  0xff, 0xff, 0xbb, 0xbb, 0xbb, 0xa1, 0xc7, 0x28, 0x70, 0xac, 0x36, 0x37, 0x55, 0xd8, 0x7f, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xef, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xef, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xc0, 0x00, 0x7f, 0xff, 0xf9, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xbf, 0xff, 0xbf, 0xff, 0xf9, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xbf, 0xff, 0xbf, 0xff, 0xf9, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xbf, 0xff, 0xbf, 0xff, 0xf9, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xc0, 0x00, 0x7f, 0xff, 0xf9, 0xe0, 0xff, 0x3f, 0x38, 0x3f, 0x09, 0xe0, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf9, 0xc0, 0x7f, 0x3f, 0x30, 0x1e, 0x01, 0xc0, 0x7f, 0xff,
  0xff, 0xf0, 0x00, 0x00, 0x01, 0xff, 0xf9, 0x9f, 0x3f, 0x9e, 0x63, 0x8c, 0x71, 0x9f, 0x3f, 0xff,
  0xff, 0xe7, 0xff, 0xff, 0xfc, 0xff, 0xf9, 0xff, 0x3f, 0x9e, 0x67, 0xcc, 0xf9, 0xff, 0x3f, 0xff,
  0xff, 0xcf, 0xff, 0xff, 0xfe, 0x7f, 0xf9, 0xe0, 0x3f, 0x9e, 0x60, 0x0c, 0xf9, 0xe0, 0x3f, 0xff,
  0xff, 0xdf, 0xff, 0xff, 0xff, 0x7f, 0xf9, 0xc0, 0x3f, 0xcc, 0xe0, 0x0c, 0xf9, 0xc0, 0x3f, 0xff,
  0xff, 0xdf, 0xff, 0xff, 0xff, 0x7f, 0xf9, 0x8f, 0x3f, 0xcc, 0xe7, 0xfc, 0xf9, 0x8f, 0x3f, 0xff,
  0xff, 0xdf, 0xff, 0xff, 0xff, 0x7f, 0xf9, 0x9f, 0x3f, 0xe1, 0xe7, 0xfc, 0xf9, 0x9f, 0x3f, 0xff,
  0xff, 0xcf, 0xff, 0xff, 0xfe, 0x7f, 0xf9, 0x9e, 0x3f, 0xe1, 0xe3, 0xcc, 0x71, 0x9e, 0x3f, 0xff,
  0xff, 0xe7, 0xff, 0xff, 0xfc, 0xff, 0xf9, 0x80, 0x3f, 0xf3, 0xf0, 0x1e, 0x01, 0x80, 0x3f, 0xff,
  0xff, 0xf7, 0xff, 0xff, 0xfd, 0xff, 0xf9, 0xc1, 0x3f, 0xf3, 0xf8, 0x3f, 0x09, 0xc1, 0x3f, 0xff,
  0xff, 0xf7, 0x1f, 0x1f, 0x1d, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf9, 0xff, 0xff, 0xff,
  0xff, 0xf6, 0xee, 0xee, 0xed, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf9, 0xff, 0xff, 0xff,
  0xff, 0xf6, 0xee, 0xee, 0xed, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0xf3, 0xff, 0xff, 0xff,
  0xff, 0xf6, 0xee, 0xee, 0xed, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x03, 0xff, 0xff, 0xff,
  0xff, 0xf6, 0xee, 0xee, 0xed, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0x07, 0xff, 0xff, 0xff,
  0xff, 0xf6, 0xee, 0xee, 0xed, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xf6, 0xee, 0xee, 0xed, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xf6, 0xee, 0xee, 0xed, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xf6, 0xee, 0xee, 0xed, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xf6, 0xee, 0xee, 0xed, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0xff, 0xff, 0xf3, 0x3f, 0xff,
  0xff, 0xf6, 0xee, 0xee, 0xed, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0xff, 0xff, 0xf3, 0x3f, 0xff,
  0xff, 0xf6, 0xee, 0xee, 0xed, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0xff, 0xff, 0xf3, 0x3f, 0xff,
  0xff, 0xf6, 0xee, 0xee, 0xed, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0xff, 0xff, 0xf3, 0x3f, 0xff,
  0xff, 0xf6, 0xee, 0xee, 0xed, 0xff, 0xf9, 0x0f, 0xc1, 0xe7, 0xcc, 0x87, 0xe0, 0xf3, 0x3c, 0x1f,
  0xff, 0xf6, 0xee, 0xee, 0xed, 0xff, 0xf8, 0x07, 0x80, 0xe7, 0xcc, 0x03, 0xc0, 0x73, 0x38, 0x0f,
  0xff, 0xf6, 0xee, 0xee, 0xed, 0xff, 0xf8, 0xe3, 0x1c, 0x67, 0xcc, 0x71, 0x8e, 0x33, 0x31, 0xc7,
  0xff, 0xf6, 0xee, 0xee, 0xed, 0xff, 0xf9, 0xf3, 0x3e, 0x67, 0xcc, 0xf9, 0x9f, 0x33, 0x33, 0xe7,
  0xff, 0xf6, 0xee, 0xee, 0xed, 0xff, 0xf9, 0xf3, 0x3e, 0x67, 0xcc, 0xf9, 0x80, 0x33, 0x30, 0x07,
  0xff, 0xf6, 0xee, 0xee, 0xed, 0xff, 0xf9, 0xf3, 0x3e, 0x67, 0xcc, 0xf9, 0x80, 0x33, 0x30, 0x07,
  0xff, 0xf6, 0xee, 0xee, 0xed, 0xff, 0xf9, 0xf3, 0x3e, 0x67, 0xcc, 0xf9, 0x9f, 0xf3, 0x33, 0xff,
  0xff, 0xf6, 0xee, 0xee, 0xed, 0xff, 0xf9, 0xf3, 0x3e, 0x67, 0xcc, 0xf9, 0x9f, 0xf3, 0x33, 0xff,
  0xff, 0xf6, 0xee, 0xee, 0xed, 0xff, 0xf8, 0xe3, 0x1c, 0x63, 0x8c, 0x71, 0x8f, 0x33, 0x31, 0xe7,
  0xff, 0xf7, 0x1f, 0x1f, 0x1d, 0xff, 0xf8, 0x07, 0x80, 0xf0, 0x0c, 0x03, 0xc0, 0x73, 0x38, 0x0f,
  0xff, 0xf7, 0xff, 0xff, 0xfd, 0xff, 0xf9, 0x0f, 0xc1, 0xf8, 0x4c, 0x87, 0xe0, 0xf3, 0x3c, 0x1f,
  0xff, 0xf7, 0xff, 0xff, 0xfd, 0xff, 0xf9, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xf3, 0xff, 0xff, 0xf9, 0xff, 0xf9, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xf9, 0xff, 0xff, 0xf3, 0xff, 0xf9, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xfc, 0xff, 0xff, 0xe7, 0xff, 0xf9, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xfe, 0x00, 0x00, 0x0f, 0xff, 0xf9, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
};

#if (SSD1306_LCDHEIGHT != 64)
#error("Height incorrect, please fix Adafruit_SSD1306.h!");
#endif

void setup()   {
  Serial.begin(9600);

  /* by default, we'll generate the high voltage from the 3.3v line internally! (neat!) */
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);

  display.clearDisplay();

  /* drawBitmap(x, y, bitmap data, width, height, color) */
  display.drawBitmap(0, 0, logo, LOGO_WIDTH, LOGO_HEIGHT, WHITE);
  display.display();
  delay(2500);

  display.clearDisplay();

  /* display_text(text, line, column, size) */
  display_text("www.poubelle.online", 30, 0, 1);
}

void loop() {
  /* empty atm */
}

void display_text(String text, int line, int column, int size) {
  display.setCursor(column, line);
  display.setTextSize(size);
  display.setTextColor(WHITE);
  display.println(text);
  display.display();
}

/* vim: set ts=2 sw=2 et : */
