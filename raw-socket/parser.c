//
// Created by Gabriel Carraro on 6/18/19.
//

#include "parser.h"

bool parse_message(int *buffer, int *size, int *sequence, int *type, int *data_size, int *bin_data){
  puts("PARSE STAAART");
  int pointer = 0;
  if(get_int(buffer, pointer, BEGIN_BIT_COUNT) != INT_BEGIN_MARKER){
    return false;
  }
  printf("pointer: %d\n", pointer);
  pointer += BEGIN_BIT_COUNT;
  printf("pointer: %d\n", pointer);
  *size = get_int(buffer, pointer, SIZE_BIT_COUNT);
  printf("size: %d\n", *size);
  pointer += SIZE_BIT_COUNT;
  printf("pointer: %d\n", pointer);
  *sequence = get_int(buffer, pointer, SEQ_BIT_COUNT);
  printf("sequence: %d\n", *sequence);
  pointer += SEQ_BIT_COUNT;
  printf("pointer: %d\n", pointer);
  *type = get_int(buffer, pointer, TYPE_BIT_COUNT);
  printf("type: %d\n", *type);
  pointer += TYPE_BIT_COUNT;
  printf("pointer: %d\n", pointer);
  *data_size = *size - (CRC_BIT_COUNT + TYPE_BIT_COUNT + SEQ_BIT_COUNT);
  printf("data_size: %d\n", *data_size);
  bin_data = get_sub_array(buffer, pointer, *data_size);
  pointer += *data_size;
  printf("pointer: %d\n", pointer);
  int *crc = get_sub_array(buffer, pointer, CRC_BIT_COUNT);
  if(!check_crc(buffer, pointer, crc)){
    free(crc);
    return true;
  }
  free(crc);
  return false;
}

int get_int(int *buffer, int start, int size) {
  printf("%d %d\n", start, size);
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
