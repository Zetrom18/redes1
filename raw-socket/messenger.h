#ifndef __MESSENGER_H__
#define __MESSENGER_H__

#define BEGIN_BIT_COUNT 8
#define SIZE_BIT_COUNT 6
#define SEQ_BIT_COUNT 5
#define TYPE_BIT_COUNT 5
#define CRC_BIT_COUNT 8

#define MAX_DATA_BIT_COUNT 64
#define MAX_MESSAGE_BIT_COUNT 96
#define MAX_SEQUENCE_VALUE 32

#define MAX_BIT_COUNT 112
#define MAX_BYTE_COUNT 14

#include <stdio.h>
#include <string.h>
#include "crc.h"

//{0,0,0,0,0};
#define ACK 0
//{0,1,0,0,1};
#define SHOW 9
//{0,0,1,0,0};
#define CD 4
//{0,1,0,0,0};
#define LS 8
//{0,0,1,1,1};
#define OK 7
//{0,1,0,1,0};
#define ERROR 10
//{0,1,1,1,0};
#define END_TX 14
//{1,1,1,1,1};
#define NACK 31
//{1,0,0,0,0};
#define GET 16
//{1,0,0,0,1};
#define DESCRIPTO 17
//{0,0,0,1,1};
#define DATA 3
//{0,0,0,1,0};
#define PUT 2
//{1,0,0,1,0};
#define CHAT 18

// unsigned char *begin_mark[BEGIN_BIT_COUNT] = {0, 1, 1, 1, 1, 1, 1, 0};
unsigned char *bin_array_to_bytes(int *bin_array, int size);
int *bytes_to_bin_array(unsigned char *bytes, int bytes_count);
void mount_command(int command, int *message);
void generate_message(int *message, int size, int sequence, int type, int *bin_data, int data_size);
int **mount_data_messages(char *data);
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
