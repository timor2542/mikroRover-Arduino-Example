#include <Servo.h>

#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

int x = 90;
Servo sv_keep;
void setup() {
  // put your setup code here, to run once:
  while (digitalRead(8));
  Serial.begin(115200);
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Address 0x3D for 128x64
    Serial.println(F("SSD1306 allocation failed"));
    for (;;);
  }
  delay(2000);
  sv_keep.attach(18);
}

void loop() {
  // put your main code here, to run repeatedly:
  display.clearDisplay();
  display.setTextSize(3);
  display.setTextColor(WHITE);
  display.setCursor(0, 0);
  // Display static text
  display.print("SV1:");
  display.println(x);
  display.display();
  
  if (!digitalRead(8) && digitalRead(9) && x > 0) {
    x--;
  }
  else if (digitalRead(8) && !digitalRead(9) && x < 180) {
    x++;
  }
  sv_keep.write(x);
  
  delay(50);
}
