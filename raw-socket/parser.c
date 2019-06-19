//
// Created by Gabriel Carraro on 6/18/19.
//

#include "parser.h"

bool parse_message(int *buffer, int *size, int *sequence, int *type, int *data_size, int *bin_data){
  int pointer = 0;
  if(get_int(buffer, pointer, BEGIN_BIT_COUNT) != INT_BEGIN_MARKER){
    return false;
  }
  pointer += BEGIN_BIT_COUNT;
  *size = get_int(buffer, pointer, SIZE_BIT_COUNT);
  pointer += SIZE_BIT_COUNT;
  *sequence = get_int(buffer, pointer, SEQ_BIT_COUNT);
  pointer += SEQ_BIT_COUNT;
  *type = get_int(buffer, pointer, TYPE_BIT_COUNT);
  pointer += TYPE_BIT_COUNT;
  *data_size = *size - (CRC_BIT_COUNT + TYPE_BIT_COUNT + SEQ_BIT_COUNT);
  bin_data = get_sub_array(buffer, pointer, *data_size);
  pointer += *data_size;
  int *crc = get_sub_array(buffer, pointer, CRC_BIT_COUNT);
  if(!check_crc(buffer, pointer, crc)){
    free(crc);
    return true;
  }
  free(crc);
  return false;
}

int get_int(int *buffer, int start, int size) {
  int i;
  int result = 0;
  for(i=0; i<size; i++){
    result = result*2 + buffer[i];
  }
  return result;
}

int *get_sub_array(int *array, int start, int size){
  int *new_array = (int *)calloc(size, sizeof(int));
  for(int i=0; i<size; i++){
    new_array[i] = array[start+i];
  }
  return new_array;
}

unsigned char *get_string(int *buffer, int start, int size){
  unsigned char *string = (unsigned char *)calloc((size/8)+1, sizeof(unsigned char));
  for(int i = 0; i<size; i++){
    string[i] = get_int(buffer, start+(i*8), 8)+'0';
  }
  string[size] = '\0';
  return string;
}
