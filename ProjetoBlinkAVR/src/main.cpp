#include <Arduino.h>

#define TIME_LED 250

// Código profissional p/ o blink
void setup() {
  //Direction registers
  DDRD = 0xFA; // 1111 1110 => 1 = output & 0 = input / D0 = 0 & D1 = 1 / D2-D7 = 1

  // Port "state" registers
  PORTD = 0x00; // 0000 0000 => 1 = high & 0 = low / D0-D7 = 0
  delay(TIME_LED);
}

void loop() {
  PORTD ^= 0x80; // PORTD xor 1000 0000
  delay(TIME_LED);
}