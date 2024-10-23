CC = gcc
FLAGS = -g

all: btest

btest: btest.c bits.c
	./dlc bits.c
	$(CC) $(FLAGS) -o $@ $?

clean:
	rm -f btest
	rm -f tests/*_diff* tests/*_actual*
	rm -rf __pycache__/
