//Código profissional para um blink no ATMEGA328P presente no Arduino UNO R3

#include <Arduino.h>

#define TIME_LED 1000
#define PIN_LED (1 << PB5) // Led interno do pino digital 13

int main(void)
{
  DDRB |= PIN_LED;   //Direction registers
  PORTB &= ~PIN_LED; // Port "state" registers

  while (1)
  {
    PORTB ^= PIN_LED;
    _delay_ms(TIME_LED);
  }
}