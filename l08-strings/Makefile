OBJS = image_util.o

all: image

image: $(OBJS) image.c
	gcc -g -o $@ $^

clean:
	rm -f image newimg.ppm 
	rm -f tests/*_diff* tests/*_actual*
	rm -rf __pycache__
