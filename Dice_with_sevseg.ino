#include "SevSeg.h"
SevSeg sevseg;
const int buttonPin = 10;
int buttonState = 0;

void setup() {
  byte numDigits = 1;
  byte digitPins[] = {};
  byte segmentPins[] = { 3, 2, 8, 7, 6, 4, 5, 9 };
  bool resistorOnSegments = true;
  sevseg.begin(COMMON_ANODE, numDigits, digitPins, segmentPins, resistorOnSegments);
  sevseg.setBrightness(90);
  pinMode(buttonPin, INPUT);
}
void loop() {
  buttonState = digitalRead(buttonPin);
  if (buttonState == HIGH) {
    sevseg.setNumber(random(1, 7));
    sevseg.refreshDisplay();
  }
}