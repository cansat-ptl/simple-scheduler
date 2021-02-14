/*
 * jobs.h
 * 
 * Created: 14.02.2021 09:21:04
 * Author: ThePetrovich
 */


#ifndef SCHED_JOBS_H_
#define SCHED_JOBS_H_

#include <lists.h>

typedef enum {STATE_UNINIT, STATE_READY, STATE_SLEEPING, STATE_SUSPENDED} sJobState_t;

typedef struct sJobStruct_t 
{
    void (*function)(void*);
    void* args;

    int delay;
    int period;
    sJobState_t state;

    sLinkedListItem_t listItem;

    char* name;
} sJob_t;

typedef sJob_t* sJobHandle_t;

sJob_t sched_createJob(void (*function)(void*), int delay, int period, sJobState_t startState, char* name);

#endif