#include "assert.h"
#include <stdio.h>
#include <stdlib.h>

void binHex (char *src, char *dst, size_t max);
void hexBin (char *src, char *dst, size_t max);

void binHex (char src[], char dst[], size_t max)
{
  //
  int z = 0;
  for (int i = 0; i < max; i +=4 ) {
    if ((src[i] == '0') && (src[i+1] == '0') && (src[i+2] == '0') && (src[i+3]) == '0') {
      dst[z] = '0';
      z++;
    }

    if ((src[i] == '0') && (src[i+1] == '0') && (src[i+2] == '0') && (src[i+3]) == '1') {
      dst[z] = '1';
      z++;
    }

    if ((src[i] == '0') && (src[i+1] == '0') && (src[i+2] == '1') && (src[i+3]) == '0') {
      dst[z] = '2';
      z++;
    }

    if ((src[i] == '0') && (src[i+1] == '0') && (src[i+2] == '1') && (src[i+3]) == '1') {
      dst[z] = '3';
      z++;
    }

    if ((src[i] == '0') && (src[i+1] == '1') && (src[i+2] == '0') && (src[i+3]) == '0') {
      dst[z] = '4';
      z++;
    }

    if ((src[i] == '0') && (src[i+1] == '1') && (src[i+2] == '0') && (src[i+3]) == '1') {
      dst[z] = '5';
      z++;
    }

    if ((src[i] == '0') && (src[i+1] == '1') && (src[i+2] == '1') && (src[i+3]) == '0') {
      dst[z] = '6';
      z++;
    }

    if ((src[i] == '0') && (src[i+1] == '1') && (src[i+2] == '1') && (src[i+3]) == '1') {
      dst[z] = '7';
      z++;
    }

    if ((src[i] == '1') && (src[i+1] == '0') && (src[i+2] == '0') && (src[i+3]) == '0') {
      dst[z] = '8';
      z++;
    }

    if ((src[i] == '1') && (src[i+1] == '0') && (src[i+2] == '0') && (src[i+3]) == '1') {
      dst[z] = '9';
      z++;
    }

    if ((src[i] == '1') && (src[i+1] == '0') && (src[i+2] == '1') && (src[i+3]) == '0') {
      dst[z] = 'a';
      z++;
    }

    if ((src[i] == '1') && (src[i+1] == '0') && (src[i+2] == '1') && (src[i+3]) == '1') {
      dst[z] = 'b';
      z++;
    }

    if ((src[i] == '1') && (src[i+1] == '1') && (src[i+2] == '0') && (src[i+3]) == '0') {
      dst[z] = 'c';
      z++;
    }

    if ((src[i] == '1') && (src[i+1] == '1') && (src[i+2] == '0') && (src[i+3]) == '1') {
      dst[z] = 'd';
      z++;
    }

    if ((src[i] == '1') && (src[i+1] == '1') && (src[i+2] == '1') && (src[i+3]) == '0') {
      dst[z] = 'e';
      z++;
    }

    if ((src[i] == '1') && (src[i+1] == '1') && (src[i+2] == '1') && (src[i+3]) == '1') {
      dst[z] = 'f';
      z++;
    }
  }
}

void hexBin(char src[], char dst[], size_t max)
{
  int z = 0;
  for (int i = 0; i < max; i++) {
    if ((src[i] == 'a') || (src[i] == 'A')) {
      dst[z] = '1';
      dst[z+1] = '0';
      dst[z+2] = '1';
      dst[z+3] = '0';
      z = z+4;
    }

    if ((src[i] == 'b') || (src[i] == 'B')) {
      dst[z] = '1';
      dst[z+1] = '0';
      dst[z+2] = '1';
      dst[z+3] = '1';
      z = z+4;
    }

    if ((src[i] == 'c') || (src[i] == 'C')) {
      dst[z] = '1';
      dst[z+1] = '1';
      dst[z+2] = '0';
      dst[z+3] = '0';
      z = z+4;
    }

    if ((src[i] == 'd') || (src[i] == 'D')) {
      dst[z] = '1';
      dst[z+1] = '1';
      dst[z+2] = '0';
      dst[z+3] = '1';
      z = z+4;
    }

    if ((src[i] == 'e') || (src[i] == 'E')) {
      dst[z] = '1';
      dst[z+1] = '1';
      dst[z+2] = '1';
      dst[z+3] = '0';
      z = z+4;
    }

    if ((src[i] == 'f') || (src[i] == 'F')) {
      dst[z] = '1';
      dst[z+1] = '1';
      dst[z+2] = '1';
      dst[z+3] = '1';
      z = z+4;
    }

    if (src[i] == '0') {
      dst[z] = '0';
      dst[z+1] = '0';
      dst[z+2] = '0';
      dst[z+3] = '0';
      z = z+4;
    }

    if (src[i] == '1') {
      dst[z] = '0';
      dst[z+1] = '0';
      dst[z+2] = '0';
      dst[z+3] = '1';
      z = z+4;
    }

    if (src[i] == '2') {
      dst[z] = '0';
      dst[z+1] = '0';
      dst[z+2] = '1';
      dst[z+3] = '0';
      z = z+4;
    }

    if (src[i] == '3') {
      dst[z] = '0';
      dst[z+1] = '0';
      dst[z+2] = '1';
      dst[z+3] = '1';
      z = z+4;
    }

    if (src[i] == '4') {
      dst[z] = '0';
      dst[z+1] = '1';
      dst[z+2] = '0';
      dst[z+3] = '0';
      z = z+4;
    }

    if (src[i] == '5') {
      dst[z] = '0';
      dst[z+1] = '1';
      dst[z+2] = '0';
      dst[z+3] = '1';
      z = z+4;
    }

    if (src[i] == '6') {
      dst[z] = '0';
      dst[z+1] = '1';
      dst[z+2] = '1';
      dst[z+3] = '0';
      z = z+4;
    }

    if (src[i] == '7') {
      dst[z] = '0';
      dst[z+1] = '1';
      dst[z+2] = '1';
      dst[z+3] = '1';
      z = z+4;
    }

    if (src[i] == '8') {
      dst[z] = '1';
      dst[z+1] = '0';
      dst[z+2] = '0';
      dst[z+3] = '0';
      z = z+4;
    }

    if (src[i] == '9') {
      dst[z] = '1';
      dst[z+1] = '0';
      dst[z+2] = '0';
      dst[z+3] = '1';
      z = z+4;
    }
  }
}
