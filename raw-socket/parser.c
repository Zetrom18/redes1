//
// Created by Gabriel Carraro on 6/18/19.
//

#include "parser.h"

int *parse_size(unsigned char *buffer);

int get_int(unsigned char *buffer, int i, int i1);

void parse_message(unsigned char *buffer, int *size, int *sequence, int *type, int *bin_data, int *data_size){
    int begin_marker = get_int(buffer, 0, BEGIN_BIT_COUNT);



}

int get_int(unsigned char *buffer, int index, int size) {

}

int *parse_size(unsigned char *buffer) {

    return NULL;
}
