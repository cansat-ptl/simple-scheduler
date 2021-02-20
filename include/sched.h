/*
 * sched.h
 * 
 * Created: 14.02.2021 09:20:53
 * Author: ThePetrovich
 */


#ifndef SCHED_SCHED_H_
#define SCHED_SCHED_H_

#define CFG_NUMBER_OF_PRIORITIES 8

#include <lists.h>
#include <jobs.h>

typedef struct sSchedStruct_t 
{
    sJob_t* currentJob;

    sLinkedList_t activeJobList[CFG_NUMBER_OF_PRIORITIES];
    sLinkedList_t sleepingJobList;
    sLinkedList_t suspendedJobList;
    
    sLinkedList_t globalListItem;

    int jobCount;
} sSched_t;

void sched_startJob(sSched_t* scheduler, sJob_t* job);
void sched_stopJob(sJob_t* job);

void sched_suspendJob(sJob_t* job);
void sched_activateJob(sJob_t* job);

void sched_run(sSched_t* scheduler);

sJob_t* sched_getCurrentJob(sSched_t* scheduler);
int sched_getJobCount(sSched_t* scheduler);

#endif