#include <stdlib.h>
#include <stdio.h>

#define MAX_MESSAGE_LENGTH 200

void get_message(char* );
void print_as_hexadecimal(char* );

int main() {
	/* Variable definitions */ 
	char *message_array;

	/* Allocate */ 
	message_array = calloc(MAX_MESSAGE_LENGTH, sizeof(char));

	/* Prompt the user to enter the text to be encrypted */
	printf("Enter the message to be encrypted: ");
	
	/* Use getchar() to reach each ASCII character and store into array */
	get_message(message_array);

	/* Print out received clear text */
	printf("Message to encrypt: %s", message_array);

	/* Print out the clear text as hexadecimal numbers */ 
	printf("\nClear text as hexadecimal: ");
	print_as_hexadecimal(message_array);

	/* Prompt the user for a 4 bit key */ 

	/* Use getchar() to read in the 4 digits */ 

	/* Convert key from 4 bits to 8 bits */ 

	/* Cipher the text */ 

	/* Print out the cipher with 10 values per row */ 

	/* Free */
	free(message_array);

	/* New line for console */ 
	printf("\n");

	return EXIT_SUCCESS;
}

void get_message(char* output_arr) {
	char input_char;
	int chars_read = 0;

	/* Collect all characters from the input */ 
	while (input_char = getchar(), input_char != '\n' && chars_read < MAX_MESSAGE_LENGTH) {
		*(output_arr+chars_read) = input_char;	
		chars_read++;
	}

	/* Add null terminating char */ 
	*(output_arr+chars_read) = '\0';
}

void print_as_hexadecimal(char* input_arr) {
	int index = 0;

	/* Print all characters as hexadecimal */
	while (*(input_arr+index) != '\0') {
		if (index % 10 == 0) {
			printf("\n");
		}

		printf("%x ", *(input_arr+index));
		index++;
	}
}
