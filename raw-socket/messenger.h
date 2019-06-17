#ifndef __MESSENGER_H__
#define __MESSENGER_H__

#define BEGIN_BIT_COUNT 8
#define SIZE_BIT_COUNT 6
#define SEQ_BIT_COUNT 5
#define TYPE_BIT_COUNT 5
#define CRC_BIT_COUNT 8

#define MAX_DATA_BIT_COUNT 64
#define MAX_SEQUENCE_VALUE 32

#include <stdio.h>
#include <string.h>
#include "crc.h"

const int ACK = 0;//{0,0,0,0,0};
const int SHOW = 9;//{0,1,0,0,1};
const int CD = 4;//{0,0,1,0,0};
const int LS = 8;//{0,1,0,0,0};
const int OK = 7;//{0,0,1,1,1};
const int ERROR = 10;//{0,1,0,1,0};
const int END_TX = 14;//{0,1,1,1,0};
const int NACK = 31;//{1,1,1,1,1};
const int GET = 16;//{1,0,0,0,0};
const int DESCRIPTOR= 17;//{1,0,0,0,1};
const int DATA = 3;//{0,0,0,1,1};
const int PUT = 2;//{0,0,0,1,0};
const int CHAT = 18;//{1,0,0,1,0};

// unsigned char *begin_mark[BEGIN_BIT_COUNT] = {0, 1, 1, 1, 1, 1, 1, 0};
void mount_command(int command, int *message);
void generate_message(int *message, int size, int sequence, int type, int *bin_data, int data_size);
void mount_data_messages(char *data);
void string_to_bin_array(char *string, int string_size, int *out);
void int_to_bin_array(int in, int count, int *out);
void print_bit_array(int* array, int size);

void fill_crc(int *message, int data_size);
void fill_data(int *message, int* data_bits, int data_size);
void fill_type(int *message, int type);
void fill_sequence(int *message, int sequence);
void fill_size(int *message, int size);
void fill_begin_marker(int *message);


#endif
