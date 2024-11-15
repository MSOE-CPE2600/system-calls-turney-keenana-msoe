/*****************************************************************************
* Filename: info.c
* Assignment Name: lab 9
* Author: Andrew Keenan
* Date: 11/6/24
* Note: Section 111
*****************************************************************************/
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/stat.h>
#include <time.h>
#include <string.h>

// finfo.c

int main(int argc, char* argv[])
{
    char filename[100];
    if(argc < 2) {
        printf("Error no file specified\n");
        return 0;
    } else {
        strcpy(filename, argv[1]);
    }
    int fd = open(filename, O_RDWR);
    struct stat s;
    int stats = fstat(fd, &s);
    if (stats == -1){
        printf("Error finding stats for file\n");
        return 0;
    }
    printf("Filename: %s\n", filename);
    printf("File type: %d\n", s.st_mode);
    printf("permissions %d\n", s.st_mode);
    printf("User ID: %d\n", s.st_uid);
    printf("file size: %ld\n", s.st_size);
    char timebuf[80];
    struct tm *tm_info = localtime(&s.st_mtime);
    strftime(timebuf, sizeof(timebuf), "%Y-%m-%d %H:%M:%S", tm_info);
    printf("Last Modified: %s\n", timebuf);


    return 0;
}