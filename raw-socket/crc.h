#ifndef _CRC_H_
#define _CRC_H_

#ifndef CRC_SIZE
#define CRC_SIZE 8
#endif

#include <stdlib.h>
#include <stdbool.h>

void calculate_crc(int *, int, int *);

#endif
