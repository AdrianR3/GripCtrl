#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1331.h>
#include <RF24.h>

// SSD1331 
#define SCLK 14
#define MOSI 13
#define CS   15
#define DC   2
#define RST  4

// NRF24L01
#define CE   5
#define CSN  17

// 1 is left 2 is right
#define JOY1_X A0
#define JOY1_Y A1
#define JOY2_X A2
#define JOY2_Y A3

Adafruit_SSD1331 display = Adafruit_SSD1331(CS, DC, MOSI, SCLK, RST);
RF24 radio(CE, CSN);

void setup() {
  Serial.begin(115200);
  display.begin();
  display.fillScreen(SSD1331_BLACK);
  display.setTextSize(1);
  display.setTextColor(SSD1331_WHITE);
  display.setCursor(0, 0);


  display.display();
  delay(1000);
  
  radio.begin();
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_LOW);
  radio.stopListening();
}

void loop() {
  int joy1X = analogRead(JOY1_X);
  int joy1Y = analogRead(JOY1_Y);
  int joy2X = analogRead(JOY2_X);
  int joy2Y = analogRead(JOY2_Y);
  
  int payload[4] = {joy1X, joy1Y, joy2X, joy2Y};
  
  if (radio.write(&payload, sizeof(payload))) {
    Serial.println("successful");
  } else {
    Serial.println("failed");
  }
  
  display.fillScreen(SSD1331_BLACK);
  display.setCursor(0, 0);
  display.print("Joystick1 X: "); display.println(joy1X);
  display.print("Joystick1 Y: "); display.println(joy1Y);
  display.print("Joystick2 X: "); display.println(joy2X);
  display.print("Joystick2 Y: "); display.println(joy2Y);
  display.display();
  
  delay(100);
  
}