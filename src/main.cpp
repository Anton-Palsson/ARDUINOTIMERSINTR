#include <avr/io.h>
#include <avr/interrupt.h>

#define LED_PIN (1 << PD3)

void toggleLed() {
    PORTD ^= LED_PIN; // Toggle LED
}

void interruptSetup() {
    DDRD |= LED_PIN;

    TCCR1A = 0; // Init Timer1
    TCCR1B = 0; // Init Timer1
    TCCR1B |= (1 << CS11) | (1 << CS10); // Prescaler = 64
    OCR1A = 31250; // Timer Preloading
    TIMSK1 |= (1 << OCIE1A); // Enable Timer Compare A Match Interrupt
}

ISR(TIMER1_COMPA_vect) {
    toggleLed();
}

int main() {
    interruptSetup();
    sei(); // Enable int viktig!!

    while (1) {
        // måste loopa
    }

    return 0;
}


