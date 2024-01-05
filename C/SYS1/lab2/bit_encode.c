#include <stdlib.h>
#include <stdio.h>

#define MAX_MESSAGE_LENGTH 200

void get_message(unsigned char*, int*);
void print_as_hexadecimal(unsigned char*, int);
void get_key(unsigned char*);
void encrypt(unsigned char*, unsigned char, int);

int main() {
	/* Variable definitions */ 
	unsigned char *message_array, key;
	int message_size = 0;

	/* Allocate */ 
	message_array = calloc(MAX_MESSAGE_LENGTH, sizeof(char));

	/* Prompt the user to enter the text to be encrypted */
	printf("Enter the message to be encrypted: ");
	
	/* Use getchar() to reach each ASCII character and store into array */
	get_message(message_array, &message_size);

	/* Print out received clear text */
	printf("Message to encrypt: %s", message_array);

	/* Print out the clear text as hexadecimal numbers */ 
	printf("\nClear text as hexadecimal: ");
	print_as_hexadecimal(message_array, message_size);

	/* Prompt the user for a 4 bit key */ 
	printf("\nEnter the 4 bit key: ");

	/* Use getchar() to read in the 4 digits */ 
	/* Convert key from 4 bits to 8 bits */ 
	get_key(&key);

	/* Cipher the text */ 
	encrypt(message_array, key, message_size);

	/* Print out the cipher with 10 values per row */ 
	printf("Encrypted text as hexadecimal: ");
	print_as_hexadecimal(message_array, message_size);

	/* Free */
	free(message_array);

	/* New line for console */ 
	printf("\n");

	return EXIT_SUCCESS;
}

void get_message(unsigned char* output_arr, int* size) {
	char input_char;
	int chars_read = 0;

	/* Collect all characters from the input */ 
	while (input_char = getchar(), input_char != '\n' && chars_read < MAX_MESSAGE_LENGTH) {
		*(output_arr+chars_read) = input_char;	
		chars_read++;
	}

	/* Add null terminating char */ 
	*(output_arr+chars_read) = '\0';

	/* Update message size */ 
	*size = chars_read;	
}

void print_as_hexadecimal(unsigned char* input_arr, int size) {
	int index = 0;

	/* Print all characters as hexadecimal */
	while (index < size) {
		if (index % 10 == 0) {
			printf("\n");
		}

		printf("%02x ", *(input_arr+index));
		index++;
	}
}

void get_key(unsigned char* output_key) {
	char input_char;
	int index = 0;

	/* Read in the 4 digit key */
	while (input_char = getchar(), (input_char == '1' || input_char == '0') && index < 4) {
		*output_key = *output_key << 1;
		if (input_char == '1') {
			*output_key = *output_key | 0x1;
		}
	}

	/* Duplicate 4 digit key to 8 digit key */ 
	*output_key = (*output_key << 4) | *output_key;
}

void encrypt(unsigned char* input_arr, unsigned char key, int size) {
	int chars_encrypted = 0;

	/* Encrypt all the characters */ 
	while (chars_encrypted < size) {
		*(input_arr+chars_encrypted) = *(input_arr+chars_encrypted) ^ key;
		chars_encrypted++;
	}
}
