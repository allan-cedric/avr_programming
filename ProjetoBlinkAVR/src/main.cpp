// Código profissional para o blink

#include <Arduino.h>

#define TIME_LED 250
#define PINS_RX_TX (1<<1)
#define PIN_LED (1<<7) // Led externo no pino digital 7 (D7)

void setup() {
  //Direction registers
  DDRD = PINS_RX_TX | PIN_LED;

  // Port "state" registers
  PORTD = 0x00; 
  delay(TIME_LED);
}

void loop() {
  PORTD ^= PIN_LED;
  delay(TIME_LED);
}