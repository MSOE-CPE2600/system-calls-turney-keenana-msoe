/*****************************************************************************
* Filename: info.c
* Assignment Name: lab 9
* Author: Andrew Keenan
* Date: 11/6/24
* Note: Section 111
*****************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <sys/utsname.h>
#include <sys/sysinfo.h>

// info.c

int main(int argc, char* argv[])
{
    // print current time in nanoseconds
    struct timespec time;
    clock_gettime(CLOCK_REALTIME, &time);
    long ns = time.tv_sec * 1000000000L + time.tv_nsec;
    printf("Current time in ns: %ld\n", ns);

    // print the network name
    struct utsname info;
    uname(&info);
    printf("The network name: %s\n", info.nodename);

    // print the operating systems name
    printf("Operating system name: %s\n", info.sysname);

    // print OS release and version
    printf("OS release: %s\n", info.release);
    printf("OS version: %s\n", info.version);

    // print hardware type
    printf("Hardware type: %s\n", info.machine);

    // print number of cpus in system
    long numcpus = sysconf(_SC_NPROCESSORS_CONF);
    printf("number of CPUS: %ld\n", numcpus);

    // print memory in bytes
    int page_size = getpagesize();
    struct sysinfo info2;
    sysinfo(&info2);
    long physmem = info2.totalram * (long) page_size;
    long freemem = info2.freeram * (long) page_size;
    printf("physical memory: %ld\n", physmem);
    printf("free memory: %ld\n", freemem);

    return 0;
}