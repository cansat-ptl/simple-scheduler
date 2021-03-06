/*
 * main.c
 * 
 * Created: 14.02.2021 09:11:45
 * Author: ThePetrovich
 */


#include <scheduler/sched.h>
#include <stddef.h>
#include "util.h"

sSched_t sched0;
sJob_t job0; 
sJob_t job1;
sJob_t job2;
sJob_t job3;

void testJob0(void* args)
{
    uart_puts("Hello from test job 0!\r\n");
}

void testJob1(void* args)
{
    uart_puts("Hello from test job 1!\r\n");
}

void testJob2(void* args)
{
    uart_puts("Hello from test job 2!\r\n");
}

void testJob3(void* args)
{
    uart_puts("Hello from test job 3!\r\n");
}

int main()
{   
    uart_init();
    arch_setupSystickTimer();

    uart_puts("Scheduler test\r\n");
    /*job0 = sched_createJob(testJob0, NULL, 500, 500, 1, STATE_ACTIVE, "test 0");
    job1 = sched_createJob(testJob1, NULL, 500, 0, 3, STATE_ACTIVE, "test 1");
    job2 = sched_createJob(testJob2, NULL, 500, 1500, 3, STATE_ACTIVE, "test 2");
    job3 = sched_createJob(testJob3, NULL, 500, 2500, 4, STATE_ACTIVE, "test 3");

    sched_startJob(&sched0, &job0);
    sched_startJob(&sched0, &job1);
    sched_startJob(&sched0, &job2);
    sched_startJob(&sched0, &job3);*/

    arch_startSystickTimer();
    arch_ENABLE_INTERRUPTS();

    while(1) {
        uint8_t sreg = arch_STATUS_REG;
	    arch_DISABLE_INTERRUPTS();
        
        sched_run(&sched0);

        arch_ENABLE_INTERRUPTS();
        arch_STATUS_REG = sreg;
    }
}

ISR(TIMER0_COMP_vect)
{
	sched_tick(&sched0);
}