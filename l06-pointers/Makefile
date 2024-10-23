all: pointers

pointers: pointers.c
	gcc -g -o $@ pointers.c CuTest.c

clean:
	rm -f pointers 
	rm -f tests/*_diff* tests/*_actual*
	rm -rf __pycache__/
