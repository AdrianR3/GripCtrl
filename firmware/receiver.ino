#include <SPI.h>
#include <RF24.h>

#define CE   5
#define CSN  17
#define PIEZO 18

RF24 radio(CE, CSN);

void setup() {
  Serial.begin(115200);
  
  pinMode(PIEZO, OUTPUT);
  
  radio.begin();
  radio.openReadingPipe(0, address);
  radio.setPALevel(RF24_PA_LOW);
  radio.startListening();
}

void loop() {
  if (radio.available()) {
    int payload[4];
    radio.read(&payload, sizeof(payload));
    
    tone(PIEZO, 500, 100);

    delay(100);
  }
}