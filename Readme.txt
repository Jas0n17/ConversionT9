Jason Lin 
C18929328
jlin22@clemson.edu

Clemson Academic Honesty Statement: As members of the Clemson University community, we have inherited Thomas Green Clemson's vision of this institution as a “high seminary of learning.” Fundamental to this vision is a mutual commitment to truthfulness, honor and responsibility, without which we cannot earn the trust and respect of others. Furthermore, we recognize that academic dishonesty detracts from the value of a Clemson degree. Therefore, we shall not tolerate lying, cheating or stealing in any form. - Signed (Jason Lin)

 * * * * * Welcome to Readme.txt * * * * * 

 * * Some quick notes about this program * * 
	- This program was worked on for upwards of 24 hours!
	- This program was ranked #1 out of 4 being my favorite project this year!
	- I skipped 2 workouts due to the difficulty of this project (11/29, 12/02)
	- There are two flags "-h" and "-L" more information below

 * * * Running and Compiling this Program * * * 
	- Before you start with anything, make sure you have two files, an input file and a output file. You can name these files to your liking. 
	- In your input file, decide whether you want to convert from digits or from words and how many word/digits you want to convert. 
	- At the first line of your input file, type the number of words/digits you plan to convert (each word/digit will be on separate lines and all words should be lowercase)
 
		* * Converting from Digits * * 
	Make sure you understand how to text in nine keys and you know which words you want to be displayed. For instance, you want to convert from digits to the word "jason", you would have to determine which button 2, 3, 4, 5, 6, 7, 8,or 9 to press and how many times. For example, the letter 'j' is "5" and the letter 'r' is "777". Once you have determined your letter seperate the digits with a hyphen '-'. For example lets say you want to convert two word "hello" and "world". Here is how you would enter it in to your input file:
		* Input File *
2
44-33-555-555-666
9-666-777-555-3
		* End of File * 
		
		* * Converting from Digits * * 
	Again, decide how many words you would like to convert from words to digits and after you enter that in the first line of your input file, enter each word in all lowercase in separate lines. For example, lets say you want to convert the words "clemson" and "is" and "awesome" to digit. Here is how you would enter it into your input file: 

		* Input File *
3
clemson
is
awesome
		* End of File *

	- In both cases please make sure you have created your output file and leave it empty!
	
 * * * Flags * * * 
	- To use flags, you must first compile the program by running the command: %make compile [enter]
	- To ask for help, you must call the help flag by running the command: %PhoneNum.exe -h
	- To convert from words to digits you can place the "-L" flag anywhere! As long as it is after the executable command 
		- %PhoneNum.exe -L in.txt out.txt 
		- %PhoneNum.exe in.txt -L out.txt
		- %PhoneNum.exe in.txt out.txt -L

 * * * Code Demostration * * * 

 _ _ _ Converting from Digits _ _ _
	* Input File * 
2
5-2-7777-666-66
555-444-66
	* End of File *
	* Terminal *
%make compile
%./PhoneNum.txt inputfile.txt outputfile.txt
	* Output File *
2
jason
lin
	* End of File *

 _ _ _ Converting from Words _ _ _ 
	* Input File *
3
clemson
is
awesome
	* End of File *
	* Terminal *
%make compile
%./PhoneNum.exe -L inputfile.txt outputfile.txt
	* Output File *
3
222-555-33-6-7777-666-66
444-7777
2-9-33-7777-666-66-33
	* End of File *

 * * * Closing Notes * * * 
	- Please make sure you have the following files present: makefile, PhoneNum.h, PhoneNum.c, Project-4.c, <inputfile>.txt, <outputfile>.txt
	- Please email me at jlin22@clemson.edu for issues with running the program or job offers!	
