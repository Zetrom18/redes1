#include "messenger.h"

void string_to_bin_array(char *string, int string_size, int *out){
	// puts("casting string to binary array");
	int i = 0;

	for (int c = 0; c < string_size; c++){
//	    printf("%c - ", string[c]);
	    for (int bit_index = 7; bit_index >= 0; --bit_index){
	        int bit = string[c] >> bit_index & 1;
//	        printf("%d", bit);
	        out[i] = bit;
	        i++;
	    }

//	    puts("");
	}
}

void int_to_bin_array(int in, int count, int* out)
{
    /* assert: count <= sizeof(int)*CHAR_BIT */
    int mask = 1U << (count-1);
    int i;
    for (i = 0; i < count; i++) {
        out[i] = (in & mask) ? 1 : 0;
        in <<= 1;
    }
}

void print_bit_array(int* array, int size){
	for (int i = 0; i < size; i++){
		printf("%d", array[i]);
	}

	puts("");
}

void fill_array(int *array, int start, int *content, int content_size){
	for (int i = 0; i < content_size; i++ ){
		array[start + i] = content[i];
	}
}

void fill_begin_marker(int *message){
	int start_bit = 0;
	int begin_marker[BEGIN_BIT_COUNT] = {0,1,1,1,1,1,1,0};

	fill_array(message, start_bit, begin_marker, BEGIN_BIT_COUNT);
}

void fill_size(int *message, int size){
	int start_bit = BEGIN_BIT_COUNT;

	int size_binary[SIZE_BIT_COUNT];
	int_to_bin_array(size, SIZE_BIT_COUNT, size_binary);

	fill_array(message, start_bit, size_binary, SIZE_BIT_COUNT);
}

void fill_sequence(int *message, int sequence){
	int start_bit = BEGIN_BIT_COUNT + SIZE_BIT_COUNT;

	int seq_binary[SEQ_BIT_COUNT];
	int_to_bin_array(sequence, SEQ_BIT_COUNT, seq_binary);
	fill_array(message, start_bit, seq_binary, SEQ_BIT_COUNT);
}

void fill_type(int *message, int type){
	int start_bit = BEGIN_BIT_COUNT + SIZE_BIT_COUNT + SEQ_BIT_COUNT;

	int type_binary[TYPE_BIT_COUNT];
	int_to_bin_array(type, TYPE_BIT_COUNT, type_binary);
	fill_array(message, start_bit, type_binary, TYPE_BIT_COUNT);
}

void fill_data(int *message, int* data_bits, int data_size){
	int start_bit = BEGIN_BIT_COUNT + SIZE_BIT_COUNT + SEQ_BIT_COUNT + TYPE_BIT_COUNT;

	fill_array(message, start_bit, data_bits, data_size);
}

void fill_crc(int *message, int data_size){
	int start_bit = BEGIN_BIT_COUNT + SIZE_BIT_COUNT + data_size;
    int *crc = (int*)calloc(CRC_SIZE, sizeof(int)*(CRC_SIZE));
    calculate_crc(message, start_bit, crc);

    fill_array(message, start_bit, crc, CRC_SIZE);
}

void mount_command(int command, int *message){

	int command_size = CRC_BIT_COUNT + TYPE_BIT_COUNT + SEQ_BIT_COUNT;
//	switch (command){
//		case ACK:
//		case NACK:
//		case OK:
//		case ERROR:
//		case END_TX:
//		case SHOW:
//		case CD:
//		case LS:
//		case GET:
//		case PUT:
	generate_message(message, command_size, 0 , command, NULL, 0);
//			break;

//		case DESCRIPTOR:
//			break;
//	}
}

void generate_message(int *message, int size, int sequence, int type, int *bin_data, int data_size){
	// BEGIN MARKER
	fill_begin_marker(message);
	// SIZE
	fill_size(message, size);
	// SEQUENCE
	fill_sequence(message, sequence);
	// TYPE
	fill_type(message, type);
	// DATA
	fill_data(message, bin_data, data_size);
	//CRC
	fill_crc(message, size - CRC_BIT_COUNT);
}

void mount_data_messages(char *data){
	int data_size = (int) strlen(data);

	int data_bit_array_size = (int)data_size * sizeof(char *);
	int bin_data[data_bit_array_size];
	string_to_bin_array(data, data_size, bin_data);
	// print_bit_array(bin_data, data_bit_array_size);

	int messages_count = data_bit_array_size / MAX_DATA_BIT_COUNT; //TODO tratar ultima mensagem caso data_bit_array_size % MAX_DATA_BIT_COUNT > 0
	int sequences_count = messages_count / MAX_SEQUENCE_VALUE;
	printf("mandando %d mensagens, %d sequencias completas\n", messages_count, sequences_count);

	int **messages = (int **) malloc((messages_count + 1) * sizeof(int*));
	int sequence = 0;

	for (int sequences = 0; sequences <= sequences_count; sequences++){
		if (sequences > 0)
			sequence = 0;
		for (sequence; (sequence < MAX_SEQUENCE_VALUE) && (sequence <= messages_count); sequence++){
			int current_message_index = sequences * MAX_SEQUENCE_VALUE + sequence;
			int current_data_start = current_message_index * MAX_DATA_BIT_COUNT;
			int current_data_size = data_bit_array_size - current_data_start;

			if(current_data_size > MAX_DATA_BIT_COUNT) {
				current_data_size = MAX_DATA_BIT_COUNT;
			}

			int current_bin_data[MAX_DATA_BIT_COUNT];

			for (int i = 0; i < data_size; i++){
				current_bin_data[i] = bin_data[current_data_start + i];
			}

            int size = CRC_BIT_COUNT + TYPE_BIT_COUNT + SEQ_BIT_COUNT + current_data_size;
			int message_size = size + BEGIN_BIT_COUNT + SIZE_BIT_COUNT;
            messages[current_message_index] = (int *) malloc((message_size)* sizeof(int));
            generate_message(messages[current_message_index], size, sequence, DATA, current_bin_data, current_data_size);
			printf("sequence %d, message (size %d bits): ", sequence, size);
			print_bit_array(messages[current_message_index], message_size);
		}
	}

	// int last_message_data_size = data_size % MAX_DATA_BIT_COUNT;

	// int out[SIZE_BIT_COUNT];
	// int_to_bin_array(data_bit_array_size, SIZE_BIT_COUNT, out);
	// print_bit_array(out, SIZE_BIT_COUNT);

}
