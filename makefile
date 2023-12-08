# Jason Lin's 
# CPSC 1070
# 11/23/2023
# Makefile for Project 04
# Clemson Academic Honesty Statement: As members of the Clemson University community, we have inherited Thomas Green Clemson's vision of this institution as a “high seminary of learning.” Fundamental to this vision is a mutual commitment to truthfulness, honor and responsibility, without which we cannot earn the trust and respect of others. Furthermore, we recognize that academic dishonesty detracts from the value of a Clemson degree. Therefore, we shall not tolerate lying, cheating or stealing in any form. - Signed (Jason Lin)

compile:
	# Create .o file in my makefile default directive
	make phone
	gcc -Wall Project-4.c *.o -o PhoneNum.exe
phone:
	# Generating neccesary .o file
	gcc -Wall -c PhoneNum.c 
run:
	./PhoneNum.exe	
clean:
	rm *.o *.exe
