all: recurse ring

recurse: recurse.c recurse_student.c
	gcc -g -o $@ $?


ring: ring.c ring_student.c
	gcc -g -o $@ $?

clean:
	rm -f recurse ring tests/*_actual* tests/*_diff*
	rm -rf __pycache__/
