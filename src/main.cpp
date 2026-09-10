#include <Arduino.h>
uint8_t value;

void setup() {
// Configure PD4 through PD7 as inputs using internal pull-up resistors.
    DDRD &= 0x0F;
// initialize pull up
    PORTD |= 0xF0;
// Configure PB0 through PB3 as outputs.
    DDRB &= 0x0F;
// Start serial communications.
    Serial.begin(9600);
}

void loop() {
//Read the entire Port D register.
value = PIND;
value &= 0xF0;
value >>= 4;
value = ~value;
value &= 0x0F;
PORTB = value;


//Print the value to the Serial Monitor.
Serial.print(" Binary: ");
Serial.println(value,BIN);
Serial.print("Decimal: ");
Serial.println(value);
delay(1000);
}

