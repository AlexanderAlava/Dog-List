##########################################################
##04/17/2016			Alexander Alava Chonchol##
##makefile				       U35432961##
##							##
##    This program is the makefile for the executable   ##
##       file called "records" and its dependants       ##
##########################################################

records: records.o dogs.o readline.o
	gcc -o records records.o dogs.o readline.o

records.o: records.c dogs.h readline.h
	gcc -c records.c

dogs.o: dogs.c dogs.h
	gcc -c dogs.c

readline.o: readline.c readline.h
	gcc -c readline.c
