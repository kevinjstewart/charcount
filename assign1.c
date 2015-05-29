#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <string.h>



/*
You are provided with a skeleton program that accepts
the text file name as a command-line argument and stores
the contents of the file in a null-terminated string called textStr.
Add the required functionality to this skeleton.
*/

#define MAX_FILE 1000000

#define A_IN_ASCII 97

int readFile(char fileName[], char textStr[]);

int alph_count[26];

int main(int argc, char* argv[]){

	char textStr[MAX_FILE];
	
	if (argc != 2){
		printf("Invalid number of arguments\n");
		printf("Usage: assign1 file_name\n");
		return 1;
	}
	
	if (readFile(argv[1], textStr) >= MAX_FILE){
		printf("The file is too large\n");
		return 1;
	}

	// define non-trivial variables
	int max_count = 0;
	float scaling_factor = 1;
	char ch;
	char char_to_print;


	// ugly switch statement counting character occurences
	// probably could have done the int->ascii trick here somehow
	int i = 0;
	while (!textStr[i] == '\0') {
		ch = toupper(textStr[i]);
		switch (ch) {
			case 'A':
				alph_count[0]++;
				break;
			case 'B':
				alph_count[1]++;
				break;
			case 'C':
				alph_count[2]++;
				break;
			case 'D':
				alph_count[3]++;
				break;
			case 'E':
				alph_count[4]++;
				break;
			case 'F':
				alph_count[5]++;
				break;
			case 'G':
				alph_count[6]++;
				break;
			case 'H':
				alph_count[7]++;
				break;
			case 'I':
				alph_count[8]++;
				break;
			case 'J':
				alph_count[9]++;
				break;
			case 'K':
				alph_count[10]++;
				break;
			case 'L':
				alph_count[11]++;
				break;
			case 'M':
				alph_count[12]++;
				break;
			case 'N':
				alph_count[13]++;
				break;
			case 'O':
				alph_count[14]++;
				break;
			case 'P':
				alph_count[15]++;
				break;
			case 'Q':
				alph_count[16]++;
				break;
			case 'R':
				alph_count[17]++;
				break;
			case 'S':
				alph_count[18]++;
				break;
			case 'T':
				alph_count[19]++;
				break;
			case 'U':
				alph_count[20]++;
				break;
			case 'V':
				alph_count[21]++;
				break;
			case 'W':
				alph_count[22]++;
				break;
			case 'X':
				alph_count[23]++;
				break;
			case 'Y':
				alph_count[24]++;
				break;
			case 'Z':
				alph_count[25]++;
				break;
			default:
				break;
		}
		++i;
	}

	printf("Went through in %d chars\n", i);

	/*
	interates through the array and prints the count of each character.
	Takes advantage of int->ascii conversions by starting at 97 (a) and incrementing
	this value by the running count each time to optimize this rather than having another
	massive switch statement.
	*/
	int ascii_charint = A_IN_ASCII;
	for (int b = 0; b < 26; b++) {
		printf("%c %d\n", ascii_charint + b, alph_count[b]);
	}

	// iterate through count to find highest value
	for (int n = 0; n < 26; ++n) {
		if (alph_count[n] > max_count) {
			max_count = alph_count[n];
		}
	}

	// set scaling factor if highest value is larger than 40
	if (max_count > 40) {
		scaling_factor = 40.0 / (double)max_count;
	}

	// Determine which character to print on histogram based on current index of array
	// Uses the same int -> ascii trick to make this super duper optimized
	for (int j = 0; j < 26; j++) {
		char_to_print = j + A_IN_ASCII;
		// now print that character m times and scale it at the same time!
		for (int i = 0; i < (alph_count[j] * scaling_factor); ++i)
		{
			printf("%c", char_to_print);
		}
		printf("\n");
	}
	


	return 0;
}

int readFile(char fileName[], char textStr[])
{
	FILE *fptr;
	char c;
	int i = 0;
	
	if ((fptr=fopen(fileName, "r")) == NULL){
		printf("Error: unknown file %s\n", fileName);
		exit(1);
	}
	
	while ((c = fgetc(fptr)) != EOF)
		textStr[i++] = c;
		
	textStr[i] = '\0';
	
	return i;	
}