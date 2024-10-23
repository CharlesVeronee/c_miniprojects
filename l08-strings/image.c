#include <stdio.h>
#include <stdlib.h>
#include "image_util.h"



int main (int argc, char* argv[]) {

    FILE* src = fopen(argv[1], "rb");
    FILE *dest = fopen(argv[2], "wb");


    char header[3];
    int width, height, colors;

    fscanf(src, "%s\n%d %d\n%d\n", header, &width, &height, &colors);

    unsigned int datasize = 3 * width * height;

    unsigned char *pixel_data = (unsigned char *)malloc(datasize);

    fread(pixel_data, 1, datasize, src);

    for (int i = 0; i < datasize; i++) {
        pixel_data[i] = 255 - pixel_data[i];
    }

    fprintf(dest, "%s\n%d %d\n%d\n", header, width, height, colors);

    my_fwrite(pixel_data, 1, datasize, dest);

    free(pixel_data);
    fclose(src);
    fclose(dest);

    return 0;
    
}