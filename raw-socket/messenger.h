#ifndef __MESSENGER_H__
#define __MESSENGER_H__

#define BEGIN_BIT_COUNT 8
#define SIZE_BIT_COUNT 6
#define SEQ_BIT_COUNT 5
#define TYPE_BIT_COUNT 5
#define MAX_DATA_BIT_COUNT 64
#define CRC_BIT_COUNT 8

unsigned char *begin_mark[BEGIN_BIT_COUNT] = {0, 1, 1, 1, 1, 1, 1, 0};
void mount_messages(char *data);
unsigned char *string_to_bin_array(char *string);


#endif