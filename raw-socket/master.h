#ifndef __MASTER_H__
#define __MASTER_H__

#include "common.h"

#define ADDR "enp2s0"

void lls(char *, char *);
void lcd(char *);
void init();
void send_message(int socket, int *message, int sequence);
void controller(int socket);

#endif
