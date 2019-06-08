#ifndef __CRS_H__
#define __CRS_H__

#include <sys/types.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <net/ethernet.h>
// #include <linux/if_packet.h>
// #include <linux/if.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int ConexaoRawSocket(char *);

#endif
