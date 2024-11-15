/*****************************************************************************
* Filename: info.c
* Assignment Name: lab 9
* Author: Andrew Keenan
* Date: 11/6/24
* Note: Section 111
*****************************************************************************/
#define _GNU_SOURCE
#include <stdio.h>
#include <sched.h>
#include <string.h>
#include <sys/resource.h>
#include <stdlib.h>
#include <unistd.h>

// pinfo.c

int main(int argc, char* argv[])
{
    // check which pid to get info from
    int pid;
    if (argc > 1) {
        pid = atoi(argv[1]);
    } else {
        pid = getpid();
    }

    // get priority
    int priority = getpriority(PRIO_PROCESS, pid);
    if (priority == -1) {
        printf("Error pid does not exist\n");
        return 0;
    }

    int schedule = sched_getscheduler(pid);
    if (schedule == -1) {
        printf("Error pid does not exist\n");
        return 0;
    }

    printf("pid: %d\n", pid);
    printf("priority: %d\n", priority);
    switch (schedule) {
        case SCHED_OTHER: 
            printf("schedule: SCHED_OTHER\n"); 
            break;
        case SCHED_FIFO: 
            printf("SCHED_FIFO\n"); 
            break;
        case SCHED_RR: 
            printf("SCHED_RR\n"); 
            break;
        default: 
            printf("Unknown\n");
            break;
    }
    return 0;
}