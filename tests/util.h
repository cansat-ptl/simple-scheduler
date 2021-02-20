/*
 * util.h
 * 
 * Created: 20.02.2021 11:53:15
 * Author: ThePetrovich
 */


#ifndef SCHED_UTIL_H_
#define SCHED_UTIL_H_

#include <avr/io.h>
#include <avr/iom128.h>
#include <avr/interrupt.h>

#define arch_DISABLE_INTERRUPTS() asm volatile ("cli"::)
#define arch_ENABLE_INTERRUPTS() asm volatile ("sei"::)
#define arch_STATUS_REG SREG

#ifndef F_CPU
#define F_CPU 16000000L
#endif

void uart_init();
void uart_putc(char c);
void uart_puts(const char * msg);
void arch_setupSystickTimer();
void arch_startSystickTimer();

#endif