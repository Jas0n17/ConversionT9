/* Jason Lin 
 * CPSC 1070
 * 11/23/2023
 * Project 04
 * Clemson Academic Honesty Statement: As members of the Clemson University community, we have inherited Thomas Green Clemson's vision of this institution as a “high seminary of learning.” Fundamental to this vision is a mutual commitment to truthfulness, honor and responsibility, without which we cannot earn the trust and respect of others. Furthermore, we recognize that academic dishonesty detracts from the value of a Clemson degree. Therefore, we shall not tolerate lying, cheating or stealing in any form. - Signed (Jason Lin)
 * PhoneNum.h is a header file for implmenting the T9 conversion from digits to words and words to digits. PhoneNum.h declares the function conversionT9(), toWord(), toDigits(), and getNextChars() more information about the function definition can be found in PhoneNum.cpp. More information about the entirety of the program can be found in Readme.txt. 
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

// Function takes in the input and output file, specifies the conversion type, and writes the converted results to the output file
void conversionT9(FILE * in, FILE * out, char type);

// Function takes in a pointer to an array of characters in the form of digits and returns a pointer to a character of strings
char * toWord(char * digits);

// Function takes in a pointer to an array of characters that make up a string and returns a pointer to a character of strings 
char * toDigits(char * word);

// Function returns the next line of characters from the input file. The return pointer is dynamically allocated.  
char * getNextChars(FILE * in);
