#!/bin/bash
#
# This script takes one argumnet, and creates a makefile named from the argument
# and based off of the .cpp and .h files in the current directory.

if test $# = 1
then
	printf "$1:" > ./Makefile
	for file in *.c
	do
		printf " ${file%.c}.o" >> ./Makefile
	done

	printf "\n\tg++ -g -ansi -Wall -o $1" >> ./Makefile
	for file in *.c
	do
		printf " ${file%.c}.o" >> ./Makefile
	done
	printf "\n" >> ./Makefile

	for file in *.c
	do
		printf "${file%.c}.o : ${file}" >> ./Makefile
		grep -e "#include \"" $file | while read -r line ; do
			line=${line#\#include \"}
			line=${line%\"}
			printf " $line" >> ./Makefile
		done
		printf "\n" >> ./Makefile
		printf "\tg++ -c -ansi -Wall ${file}\n" >> ./Makefile
	done
	printf "clean:\n\t rm *.o $1" >> ./Makefile
else
	echo "The project name must be included as an argument"
fi
