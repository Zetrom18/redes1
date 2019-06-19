//
// Created by Gabriel Carraro on 6/18/19.
//

#ifndef RAW_SOCKET_PARSER_H
#define RAW_SOCKET_PARSER_H

#include "messenger.h"

void parse_message(unsigned char *buffer, int *size, int *sequence, int *type, int *bin_data, int *data_size);

#endif //RAW_SOCKET_PARSER_H
