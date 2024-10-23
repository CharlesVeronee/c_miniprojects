all: convert

convert: convert.c convert_student.c
	gcc -g -o $@ $?

clean:
	rm -f convert
	rm -f tests/*_diff* tests/*_actual*
	rm -rf __pycache__/
