#include <stdio.h>
#include <stdlib.h>
 
void doEncode (
  const unsigned char encode[],
  const unsigned char str[],
  unsigned char res[],
  size_t len
) {
  size_t i;
    for (i = 0; i < len && str[i] != '\0'; i++) {
        res[i] = encode[str[i]];
    }
    res[i + 1] = '\0';
}
 
void doDecode (
  const unsigned char encode[],
  const unsigned char str[],
  unsigned char res[],
  size_t len
) {
  size_t i;
    for (i = 0; i < len && str[i] != '\0'; i++) {
        int index = 0;
        while (encode[index] != str[i]) {
            index++;
        }
        res[i] = (unsigned char)index;
    }
}
