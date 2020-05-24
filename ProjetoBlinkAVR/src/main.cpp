//Código profissional para um blink no ATMEGA328P presente no Arduino UNO R3

#include <Arduino.h>

#define TIME_LED 1000 // Tempo de espera para um delay //
#define PIN_LED (1 << PB5) // Led interno do pino digital 13

int main(void)
{
  // ----- Setup ----- //
  DDRB |= PIN_LED;   //Direction registers
  PORTB &= ~PIN_LED; // Port "state" registers

  // ---- Loop ----- //
  while (1)
  {
    PORTB ^= PIN_LED; // Mudança automática de estado //
    _delay_ms(TIME_LED); // Espera uma quantidade de tempo em milisegundos // 
  }
  return 0;
}