#
# COP 3514 – Fall Semester, 2020
#
# Project 9 - makefileg
#
# Dong Jun Kim
#

rec_classes: readline.o request.o rec_classes.o
	gcc -o rec_classes readline.o request.o rec_classes.o

readline.o: readline.c readline.h
	gcc -c readline.c

request.o: request.c request.h
	gcc -c request.c

rec_classes.o: rec_classes.c
	gcc -c rec_classes.c