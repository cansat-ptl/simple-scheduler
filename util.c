/*
 * util.c
 * 
 * Created: 20.02.2021 11:53:05
 * Author: ThePetrovich
 */

#include "util.h"
#include <avr/io.h>
#include <avr/iom128.h>
#include <avr/interrupt.h>

void uart_init()
{
	UBRR0H = (24 >> 8);
	UBRR0L = (24 & 0xFF);
	UCSR0A |= (1 << U2X);
	UCSR0B = (1<<RXEN)|(1<<TXEN)|(1<<RXCIE)|(0<<TXCIE)|(0<<UDRIE);
	UCSR0C = (0<<USBS)|(1<<UCSZ00)|(1<<UCSZ01)|(0<<UCSZ02)|(0<<UPM00)|(0<<UPM01)|(0<<UMSEL0);
}

void uart_putc(char c)
{
	UDR0 = c;
	while (!(UCSR0A & (1<<UDRE)));
}

void uart_puts(const char * msg)
{
	int i = 0;
	while (msg[i] != '\0') {
		uart_putc(msg[i]);
		i++;
	}
}

void arch_setupSystickTimer()
{
	uint8_t sreg = arch_STATUS_REG;
	arch_DISABLE_INTERRUPTS();
	TCCR0 |= (3 << CS00);
	TCNT0 = 0;
	OCR0 = 250;
	arch_ENABLE_INTERRUPTS();
	arch_STATUS_REG = sreg;
}

void arch_startSystickTimer()
{
	uint8_t sreg = arch_STATUS_REG;
	arch_DISABLE_INTERRUPTS();
	TIMSK |= (1 << OCIE0);
	arch_ENABLE_INTERRUPTS();
	arch_STATUS_REG = sreg;
}