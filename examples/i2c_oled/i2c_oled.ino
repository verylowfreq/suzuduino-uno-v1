// Use as Public domain
// Original author: Mitsumine Suzu 2023

#include <Wire.h>
#include <Adafruit_SSD1306.h>

#define DISPLAY_WIDTH 128
#define DISPLAY_HEIGHT 64
#define PIN_OLED_RESET -1  // OLED reset pin is not assigned.
#define DISPLAY_ADDRESS ((0x78) >> 1)

Adafruit_SSD1306 display(DISPLAY_WIDTH, DISPLAY_HEIGHT, &Wire, PIN_OLED_RESET);


void setup() {
  pinMode(PA5, OUTPUT);

  if (!display.begin(SSD1306_SWITCHCAPVCC, DISPLAY_ADDRESS)) {
    digitalWrite(PA5, HIGH);
    delay(200);
    digitalWrite(PA5, LOW);
    delay(200);
  }

  // Show the default Adafruit logo
  display.display();
  
  delay(2000);

  display.clearDisplay();
}


void loop() {
  static bool draw_white = true;

  for (int i = 0; i < 128; i++) {
    display.drawLine(0, 0, i, 63, draw_white ? WHITE : BLACK);
    display.display();
  }

  draw_white = !draw_white;
}
