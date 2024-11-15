/*****************************************************************************
* Filename: info.c
* Assignment Name: lab 9
* Author: Andrew Keenan
* Date: 11/6/24
* Note: Section 111
*****************************************************************************/
#include <unistd.h>
#include <time.h>
#include <stdio.h>
// pmod.c

int main(int argc, char* argv[])
{
    int current_nice = nice(0);
    printf("starting priority: %d\n", current_nice);
        current_nice = nice(-10);
        printf("The new nice value is: %d\n",current_nice);
    struct timespec req, rem;
    req.tv_sec = 1;
    req.tv_nsec = 837272638;
    if (nanosleep(&req, &rem) == -1) {
        perror("nanosleep failed");
        printf("Remaining time: %ld seconds and %ld nanoseconds\n", rem.tv_sec, rem.tv_nsec);
    } else {
        printf("nanosleep completed successfully\n");
        printf("goodbye.\n");
    }
    return 0;
}