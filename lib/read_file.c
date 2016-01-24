#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>	
		
	
	
char* read_fline(FILE *file){
	char symbol = 0;
	char* string;
	size_t iter;
	size_t number_of_chars = 0;
	while((symbol = fgetc(file)) != '\n') 
		number_of_chars++;
	string = (char*) malloc(sizeof(char)*number_of_chars);
	fseek(file, -number_of_chars-1, SEEK_CUR);
	for(iter = 0; iter < number_of_chars; iter++) {
		string[iter] = fgetc(file);
	}
	getc(file);
	return string;
}

size_t count_frows(FILE *file) {
	char symbol;
	size_t number_of_rows = 0;
	while(1) {
                symbol = fgetc(file);
                if(symbol == '\n') number_of_rows++;
                if(symbol == EOF)  break;
        }
	fseek(file, 0, SEEK_SET);
	return number_of_rows;	
}
	
char** read_file(FILE *file) {
	size_t number_of_rows, iter;
	char** string_array;
	number_of_rows = count_frows(file);
	string_array = calloc(sizeof(char*), number_of_rows);
	for(iter = 0; iter < number_of_rows; iter++) {
		string_array[iter] = read_fline(file);
	}
	return string_array;	
		
}

	