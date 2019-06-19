#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned char *bin_array_to_bytes(int *bin_array, int size){
	int i,j=0;
	unsigned char *bytes = (unsigned char*)malloc(sizeof(unsigned char)*((int)(size/sizeof(unsigned char))+1));
	memset(bytes, 0, sizeof(bytes));
	for(i=0; i<size; i++){
    if((i+1) % 8 == 0){
      j++;
    }
    bytes[j] = (bytes[j] | (bin_array[i]==1 ? 1u : 0u)) << 1;
	}
	return bytes;
}

int main(int argc, char const *argv[]) {
  int array[] = {0,1,1,1,1,1,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,0,1,1,1,1,1,1,0};
  unsigned char *bytes = bin_array_to_bytes(array, sizeof(array)/sizeof(int));
  for(int i=0; i<sizeof(bytes); i++){
    printf("%u\n", bytes[i]);
  }
  return 0;
}
