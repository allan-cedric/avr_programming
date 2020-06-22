// -- Código profissional para o controle de um led por meio de um botão no Arduino UNO R3 --
// -- Microcontrolador: ATMEGA328P --
// -- Autor: Allan Cedric --

// -- Bibliotecas --
#include <Arduino.h>

// -- Macros --
#define PIN_BUTTON (1 << PB0) // Bit do pino digital 8 //
#define PIN_LED (1 << PB5)    // Bit do pino digital 13 //

#define set_bit(reg, b) (reg |= b)    // Seta o bit 1 em uma posição do registrador //
#define reset_bit(reg, b) (reg &= ~b) // Seta o bit 0 em uma posição do registrador //

#define DEBOUNCE_BUTTON 10 // Tempo(ms) de debounce para o botão //

// -- Programa principal --
int main(void)
{
  // -- Setup --

  // -- Push button --
  reset_bit(DDRB, PIN_BUTTON); // Pino digital 8 como INPUT //
  set_bit(PORTB, PIN_BUTTON);  // Pino digital 8 com bit 1  //

  // -- LED --
  set_bit(DDRB, PIN_LED); // Pino digital 13 como OUTPUT //

  // -- Loop --
  while (1)
  {
    if (!(PINB & PIN_BUTTON)) // Botão foi pressionado ? //
    {
      _delay_ms(DEBOUNCE_BUTTON); // Debounce do botão //
      if (PINB & PIN_BUTTON)      // Botão foi solto ? //
        PORTB ^= PIN_LED;         // Muda o estado do LED //
    }
  }
  return 0;
}
