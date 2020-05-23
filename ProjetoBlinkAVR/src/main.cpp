//Código profissional para um blink no ATMEGA328P presente no Arduino UNO R3

#include <Arduino.h>

#define TIME_LED 250
#define PINS_RX_TX (1<<1)
#define PIN_LED (1<<7) // Led externo no pino digital 7 (D7)

int main(void)
{
  //Direction registers
  DDRD = PINS_RX_TX | PIN_LED;

  // Port "state" registers
  PORTD = 0x00; 
  _delay_ms(TIME_LED);
  while (1)
  {
    PORTD ^= PIN_LED;
   _delay_ms(TIME_LED);
  }
}