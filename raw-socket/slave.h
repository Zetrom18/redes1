#ifndef __SLAVE_H__
#define __SLAVE_H__

#include "common.h"

#define ADDR "eth0"

char *ls(char *, char *);
char *cd(char *);
void init();
void receive_message(int socket, int *bin_array, int *count);
void controller();

#endif
