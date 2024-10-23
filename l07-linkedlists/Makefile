all: pointers2

pointers2: pointers2.c CuTest.c
	gcc -o $@ $?

clean:
	rm -f pointers2
	rm -f tests/*_diff* tests/*_actual*
	rm -rf __pycache__
