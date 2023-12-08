/* Jason Lin 
 * CPSC 1070
 * 11/23/2023
 * Project 04
 * Clemson Academic Honesty Statement: As members of the Clemson University community, we have inherited Thomas Green Clemson's vision of this institution as a “high seminary of learning.” Fundamental to this vision is a mutual commitment to truthfulness, honor and responsibility, without which we cannot earn the trust and respect of others. Furthermore, we recognize that academic dishonesty detracts from the value of a Clemson degree. Therefore, we shall not tolerate lying, cheating or stealing in any form. - Signed (Jason Lin) 
 * Relavent Sources: Teaching Assistants: Jack, Henry, Charlie, Laurel, Ethan, CJ, Coby. Lecture slides. Colab 5. [1] Tony Gaddis and Judy Walters. 2019. Starting Out with C++: Early Objects (10th. ed.). 
 * This program is designed to convert text between T9-style button presses and real words by taking in command line arguement of input files and display the result to the output file. T9, which stands for "Texting with 9 Keys," was a popular method of texting in the late 90s. T9 aimed to simplify typing on a 9-digit keypad by predicting words based on button presses.
 * (Please see Readme.txt for more information)
 */ 

// Include all required files
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "PhoneNum.h"

// * * * * * * * * * * 
// Function takes in two arguements, a postive integer between 2 and 4 and a array of strings that are assumed to be flags or file names. Function opens the input and output file, handles exceptions, and converts the content from the input file to the output file with the helper function conversionT9. Function returns a integer. Function depends on conversionT9(), fopen(), and fclose(). 
// Example Usage:
// 	(Please see Readme.txt)
// * * * * * * * * * * 
int main(int argc, char * argv[]) {
	// If statement entered if there is not enough arguement from command line
	if (argc < 2) {
		puts("No input file given\nNo output file given\nUse -h to get help\n");
	}	
	// Statement entered if the help flag is detected
	else if (strcmp(argv[1], "-h") == 0) {
		// Provides instruction for the user.
		puts("PhoneNum T9 Conversion Tool. Usage:");
		puts("PhoneNum.exe <input file> <output file> [-L]");
		puts("-L Sets input type as letters instead of digits");
		puts("-h To get help");
	} 
	// Statement entered if there is not enough arguement and the help flag is not detected
	else if (argc == 2) {
		puts("No output file given\nUse -h to get help\n");
	}
	// Statement entered if there are sufficient arguements, conversionT9 converting file digits to word 'd' mode which expects the contents of the input file to be digits and write to the output files to be words
	else if (argc == 3) {
		// Files open
		FILE * infile = fopen(argv[1], "r");
		FILE * outfile = fopen(argv[2], "a");
		// Checks if files are successfully opened, statement entered if files open successfully
		if (infile != NULL && outfile != NULL) {
			conversionT9(infile, outfile, 'd');

			// Files closed
			fclose(infile);
			fclose(outfile);
		}
		// Statement entered if files fail to open
		else {
			puts("(!) Error opening up file (!)\n");	
			exit(1);
		}
        }
	// Statement entered if the "-L" flag is detected in index 1, 2, or 3 which calls conversionT9 to be on 'l' mode which expects the contents of the input file to be words and writes to the output file to be digits
	else if (strcmp(argv[1], "-L") == 0 || strcmp(argv[2], "-L") == 0 || strcmp(argv[3], "-L") == 0) {
		// Statements entered if the "-L" flag is detected at varying index and opens the file according to "-L"'s index  assuming the first file to be the input file and the second file to be the output file
		if (strcmp(argv[1], "-L") == 0) {
			// File open
			FILE * infile = fopen(argv[2], "r");
			FILE * outfile = fopen(argv[3], "a");
			// Statement entered if file sucessfully opens
			if (infile != NULL && outfile != NULL) {
				conversionT9(infile, outfile, 'l');

				// File close
				fclose(infile);
				fclose(outfile);
			}
		        // Statement entered if file fails to open 	
			else { printf("(!) Error openning up file (!)\n"); exit(1); }
		}
		else if (strcmp(argv[2], "-L") == 0) {
			// File open
			FILE * infile = fopen(argv[1], "r");
			FILE * outfile = fopen(argv[3], "a");
			// Statement entered if file sucessfully opens
			if (infile != NULL && outfile != NULL) {
				conversionT9(infile, outfile, 'l');

				// File close
				fclose(infile);
				fclose(outfile);
			} 
			else { printf("(!) Error openning up file (!)\n"); exit(1); }
		}
		else {
			// File open
			FILE * infile = fopen(argv[1], "r");
			FILE * outfile = fopen(argv[2], "a");
			// Statement entered if file sucessfully opens
			if (infile != NULL && outfile != NULL) {
				conversionT9(infile, outfile, 'l');

				// File close
				fclose(infile);
				fclose(outfile);
			} 
			else { printf("(!) Error openning up file (!)\n"); exit(1); }
		}
	}
        // Statement entered if there are 5 or more arguements	
	else {
		puts("Too many arguments!\n- h To get help\n");

	}
	return 0;
}	
