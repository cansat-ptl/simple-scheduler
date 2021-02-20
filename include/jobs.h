/*
 * jobs.h
 * 
 * Created: 14.02.2021 09:21:04
 * Author: ThePetrovich
 */


#ifndef SCHED_JOBS_H_
#define SCHED_JOBS_H_

#include <lists.h>

typedef enum {STATE_UNINIT, STATE_ACTIVE, STATE_SLEEPING, STATE_SUSPENDED} sJobState_t;

struct sSchedStruct_t;

typedef struct sJobStruct_t 
{
    void (*function)(void*);
    void* args;

    int delay;
    int period;
    int priority;
    sJobState_t state;

    struct sSchedStruct_t* schedReference;
    sLinkedListItem_t schedListItem;
    
    char* name;
} sJob_t;

sJob_t sched_createJob(void (*function)(void*), void* args, int delay, int period, int priority, sJobState_t initialState, char* name);

void sched_setJobFunction(sJob_t* job, void (*function)(void*), void* args);
void sched_setJobDelay(sJob_t* job, int delay);
void sched_setJobPeriod(sJob_t* job, int period);
void sched_setJobName(sJob_t* job, char* name);

void(*sched_getJobFunction(sJob_t* job))(void*); /* Yo what the fuck */
int sched_getJobDelay(sJob_t* job);
int sched_getJobPeriod(sJob_t* job);
char* sched_getJobName(sJob_t* job);
sJobState_t sched_getJobState(sJob_t* job);

#endif