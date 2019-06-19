//
// Created by Gabriel Carraro on 6/18/19.
//

#ifndef RAW_SOCKET_PARSER_H
#define RAW_SOCKET_PARSER_H

#include "crc.h"
#include "messenger.h"

int *parse_size(int *buffer);
int get_int(int *buffer, int start, int size);
bool parse_message(int *buffer, int *size, int *sequence, int *type, int *bin_data, int *data_size);

#endif //RAW_SOCKET_PARSER_H
