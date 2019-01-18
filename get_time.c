#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lib.h"

void get_time(char *buf){
    time_t time_long = time(NULL);
    char *time_str = ctime(&time_long);
    strncpy(buf, time_str, strlen(time_str));
    buf[strlen(time_str)] = '\0';
}

