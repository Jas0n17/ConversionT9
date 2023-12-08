/* Jason Lin 
 * CPSC 1070
 * 11/23/2023
 * Clemson Academic Honesty Statement: As members of the Clemson University community, we have inherited Thomas Green Clemson's vision of this institution as a “high seminary of learning.” Fundamental to this vision is a mutual commitment to truthfulness, honor and responsibility, without which we cannot earn the trust and respect of others. Furthermore, we recognize that academic dishonesty detracts from the value of a Clemson degree. Therefore, we shall not tolerate lying, cheating or stealing in any form. - Signed (Jason Lin)
 * PhoneNum.c defines function from PhoneNum.h. Each function has been provided a detailed description on its functionality. Phone.c performs converations from T9 digits to English words and visaversa and returns the results into a output file that was read in from the input file.  Please refer to Readme.txt for more information about the entirety of this program. 
 */

// Included required file
#include "PhoneNum.h"

// Prototype for my helper function, more information below
char toLetter(int, int);
char * toBundleDigit(char c);

// * * * * * * * * * * 
// Function converts the contents of the input file to digits/words and writes the converted content to the output file. Function takes a file pointer of the input file, a file pointer of the output file, and a character determining weather the contents of the input file is to be converted from digits to word ('d'), or from words to digits ('l'). Function depends on toWord(), toDigit(), getNextChars(), toLetter(), and toBundleDigit() function. 
// * * * * * * * * * * 
void conversionT9(FILE * in, FILE * out, char type) {
	// Dynamically memory allocate a character
	char * charPtr = malloc(sizeof(char));
	// Checks if memory allocation failed
	if (charPtr == NULL) { printf("Memory allocation failed!\n"); exit(1);}
	// Stores the first line of the input file
	charPtr = getNextChars(in);

	// Cast a character ACII value to a integer data type
	int numLines = atoi(charPtr);
	// First line of input file is written to the output file
	fprintf(out, "%s\n", charPtr);

	int i;
	// strD stores the character 'd' that is converted to a string for comparison 
	char strD[] = "d"; char strType[2] = {type, '\0'};

	// Memory freed
	free(charPtr);

	// Converts from digits to letters (if char type is 'd')
	if (strcmp(strType, strD) == 0) {
		// A for loop that reads and converts the contents of the rest of the input file to the output file (Post-thought, maybe using feof(myfile) was a better idea than using for loops)
		for (i = 0; i < numLines; i++) {
			// A string pointer for the next line of the file that is read
			char * tempLine = getNextChars(in);
			// A string pointer for the coverted string from tempLine
			char * tempStr = toWord(tempLine);

			// Writes the converted tempStr to the output file
			fprintf(out, "%s\n", tempStr);

			// Memory is freed and set to NULL to prevent a dangling pointer (a pointer that continues to point to a memory location after the pointer has been deallocated) 
			free(tempLine); tempLine = NULL;	
			free(tempStr); tempStr = NULL;
		}
	} 
	// Converts from letters to digits
	else {
		// A for loop that reads and converts the content of the rest of the input file to the output file
		for (i = 0; i < numLines; i++) {
			// A string pointer for the next line of the file that is read
			char * tempLine = getNextChars(in);
			// A string pointer for the converted word from tempLine
			char * tempStr = toDigits(tempLine);
				
			// Writes the converted tempStr to the output file
			fprintf(out, "%s\n", tempStr);

			// Memory is freed and set to NULL to prevent a dangling pointer
			free(tempLine); tempLine = NULL;
			free(tempStr); tempStr = NULL;
		}
	}
}
// * * * * * * * * * * 
// Function takes in a string arguement that it assumes is in the form of the T9 digits as letters and each letter is separated by a hyphen. Function iterates throught the string and calls the helper function toLetter() to aid in the process of conversion. Returns a dynamically allocated string that is converted from digits.
// Example Usage:
// 	char digits[] = "5-2-7777-666-66";
// 	char word[6] = toWord(digits); // word will now store "jason" 
// * * * * * * * * * * 
char * toWord(char * digits) {
	// String result is dynamically allocated in memory with the size of 150 characters
	char * result = malloc(150 * sizeof(char));
	if (result == NULL) { printf("Memory allocation failed!\n"); exit(1); }
	// Initalize the stirng witih a null terminator
	result[0] = '\0';
	
	// Stores the length of the arguement
	int len = strlen(digits);
	// Stores the button on the T9 that is being pressed
	int button = 0;
       	// Count stores the number of times the button is pressed	
	int count = -1; 
	int i;
	for (i = 0; digits[i] != '\0'; i++) {
		// If statement checks if digits[i] is a digit between 2 and 9
		if (digits[i] >= '2' && digits[i] <= '9') {
			// Button is set to the digit that is pressed (converted to a integer data type by subtracting by '0')
			button = digits[i] - '0'; 
			// Count is incremented
			count++;
			// This if loop converts the last set of digits
			if (i == len - 1) {
				// Character stores the character that is converted from the set of digits
                        	char tempChar = toLetter(button, count);
				// Character is converted to a string and appended to result
                     		char tempStr[] = {tempChar, '\0'};
                        	strcat(result, tempStr);
                	}
		}
		// If statement check if a hyphen is detected
		else {
			// Character stores the character that is converted from the set of digits
			char tempChar = toLetter(button, count);
			// Character is converted to a string and appended to result
			char tempStr[] = {tempChar, '\0'};
			strcat(result, tempStr);
			
			// Count is reset
			count = -1;
		}
	}
	// Returns the dynamically allocated stirng
	return result;
}
// * * * * * * * * * *
// Function takes in a string assuming it is a English word that is all lowercase with no spaces, digits, or non-alpha characters. Returns a dynamically allocated string converted to digits separated by hyphens. Function iterates throughthe string word and converts each letter to digit one at a time separated by a hythen. The function calls a helper function toBundleDigit() to aid in the conversion process.
// Example Usage:
// 	char word[] = "jason";
// 	char digits[100] = toDigits(word); // now digits will store "5-2-7777-666-66" 
// * * * * * * * * * * 
char * toDigits(char * word) {
	// A string of size 150 character is dynamically allocated in memory
	char * result = malloc(150 * sizeof(char));
	// The length of the word is stored
	int len = strlen(word);
	// A string storing a hypen will be used to append to result
       	char hyphen[] = "-";

	int i;
	// Iterate through string word
	for (i = 0; i < len; i++) { 
		// If statement entered if the last index of the word is detected, helper function is called and appended to result
		if(i == len - 1) {
			char * tempStr = toBundleDigit(word[i]);
			strcat(result, tempStr);
		} 
		// Otherwise convert the current word at index i to digit using helper function and append it to result along with a hyphen
		else {
			char * tempStr = toBundleDigit(word[i]);
			strcat(result, tempStr);
			strcat(result, hyphen);
		}
	}
	
	// Digits in form of a string is returned
	return result;
}
// * * * * * * * * * * 
// Function takes in a character c assuming it is a lowercase English letter, then return the string representation of that letter in T9 version. A helper function for toDigits() and does not depend on other functions. 
// Example Usage:
// 	char example1 = 'a'; char example2 = 'z';
// 	char result1[5] = toBundleDigit(example1); // result1 will now be "2"
//	char result2[5] = toBundleDigit(example2); // result2 will now be "9999"
// * * * * * * * * * * 
char * toBundleDigit(char c) {
	// Declare and initalize an array of strings (character pointers)
	char * digitArr[26] = {"2", "22", "222", "3", "33", "333", "4", "44", "444", "5", "55", "555", "6", "66", "666", "7", "77", "777", "7777", "8", "88", "888", "9", "99", "999", "9999"};
	// Index converts arguement c to the position of the letter within the alphabet, 'a' = index 0 ... 'z' = index 25
	int index = c - 97;

	// Returns the string associated with it
	return digitArr[index];
}
// * * * * * * * * * * 
// Function takes in two postive integers that are between 2 to 9 inclusive, returns a character based on the button pressed and the amount of times it was pressed. Function does not depend on any other function.
// Example Usage:
// 	char letter1 = toLetter(2, 2); // demostrates the button '2' being pressed 2 times, letter1 is now 'b'
// 	char letter2 = toLetter(9, 3); // demostrates the button '9' being pressed 3 times, letter2 is now 'y'
// * * * * * * * * * * 
char toLetter(int button, int count) {
	// An array of characters intialized to their character values
	char button2[3] = {'a', 'b', 'c'};
        char button3[3] = {'d', 'e', 'f'};
        char button4[3] = {'g', 'h', 'i'};
        char button5[3] = {'j', 'k', 'l'};
        char button6[3] = {'m', 'n', 'o'};
        char button7[4] = {'p', 'q', 'r', 's'};
        char button8[3] = {'t', 'u', 'v'};
        char button9[4] = {'w', 'x', 'y', 'z'};
	
	// Switch statement handles the button that is pressed and the body handles the number of times it is pressed
	switch (button) {
		case 2:
			return button2[count];
		case 3:
			return button3[count];
		case 4:
			return button4[count];
		case 5:
			return button5[count];
		case 6:
			return button6[count];
		case 7:
			return button7[count];
		case 8:
			return button8[count];
		case 9:
			return button9[count];
		default:
			return ' ';
	}
}
// * * * * * * * * * * 
// Function takes in a file pointer assuming that the file exist and it is a input file. The function returns the next line of the file as a dynamically allocated string using library function fgets(). Function uses malloc() and does not depend on other functions.
// Example Usage:
// 	(Please refer to Readme.txt :) )
// * * * * * * * * * * 
char * getNextChars(FILE * in) {
	// A string size of 150 character is dynamically allocated
	char * charPtr = malloc(150 * sizeof(char));
	// Check for successful memory allocation
	if (charPtr == NULL) { printf("Memory allocation failed!\n"); exit(1); }

	// If statement entered if the line from input file was successfully read in
	if (fgets(charPtr, 150, in) != NULL) {
		// Stores the length of the line
		int len = strlen(charPtr);
		// Replaces the last character of the string with a null terminator
		if (len > 0 && charPtr[len - 1] == '\n') {
			charPtr[len - 1] = '\0';
		}		
	} 
	// Else statement entered if the line fails to read from file
	else {
		free(charPtr);
		charPtr = NULL;
		printf("Memory allocation failed!!\n");
		exit(1);
	}

	// Returns a dynamically allocated string
	return charPtr;
}	
