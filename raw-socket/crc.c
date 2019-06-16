#include "crc.h"

int _CRC_DIVISOR[CRC_SIZE+1] = {1,1,0,1,1,0,1,1,0};

void calculate_crc(int* data, int data_size, int* crc){
  int i, j;
  int *buffer = (int*)malloc(sizeof(int)*(data_size+CRC_SIZE));

  for(i=0; i<data_size; i++){ // copia data para buffer
    buffer[i] = data[i];
  }
  for(j=0; j<CRC_SIZE; j++){ // copia crc para bufefr
    buffer[i+j] = crc[j];
  }

  for(i=0; i<data_size; i++){
    if(buffer[i]!=0){
      for(j=0; j<CRC_SIZE; j++){
        buffer[i+j] = (buffer[i+j] + _CRC_DIVISOR[j]) % 2;
      }
    }
  }

  for(j=0; j<CRC_SIZE; j++){  // copia crc calculado
    crc[j] = buffer[i+j];
  }

  free(buffer);
}

bool check_crc(int* data, int data_size, int* crc){
  int i;

  calculate_crc(data, data_size, crc);

  for(i=0; i<CRC_SIZE; i++){
    if(crc[i]==1){
      return false;
    }
  }

  return true;
}
