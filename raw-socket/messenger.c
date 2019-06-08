#include "messenger.h"

unsigned char *string_to_bin_array(char *string){
	puts("casting string to binary array");
	int string_size = strlen(string);
	int array_size = string_size * sizeof(char);
	unsigned char *bin_array[array_size];

	// for (int i = 0; i < string_size; i++){
	// 	char current_char = string[i];
	// 	printf("%c - ", current_char);
	// 	for (int j = 0; j < 8; j++){
	// 	    printf("%d", (unsigned char)current_char);	
	// 	}
	// 	puts();
	// }

	for (char *temp = string; *temp; ++temp){
	    int bit_index;
	    printf("%c - ", *temp);
	    for (bit_index = 7; bit_index >= 0; --bit_index){
	        int bit = *temp >> bit_index & 1;
	        printf("%d", bit);
	    }
	    
	    printf("\n");
	}
}

void mount_messages(char *data){
	unsigned char *bin_data = string_to_bin_array(data);
	// int data_size = strlen(data) * sizeof(char);
	// printf("data size is %d\n", data_size);
	// int messages_size = data_size / MAX_DATA_BIT_COUNT;
	// int lest_message_data_size = data_size % MAX_DATA_BIT_COUNT;
	// printf("will send %d messages of len %d", data_size);

}