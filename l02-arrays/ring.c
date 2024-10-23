#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>

#define SEED 210
#define MAXLINE 64
char lineBuff[MAXLINE];

extern void doEncode (
  const unsigned char encode[], 
  const unsigned char str[], 
  unsigned char res[],
  size_t len
);
extern void doDecode (
  const unsigned char encode[], 
  const unsigned char str[],
  unsigned char res[],
  size_t len
);

void seedEncodingArray (unsigned char encode[]);
void populateHelperArray (unsigned char helperArray[]);
void shiftHelperArray (unsigned char helperArray[]);
bool checkInput (char str[]);

void seedEncodingArray (unsigned char encode[]) {
  int i;
  unsigned char alphaNumeric[62];
  populateHelperArray(alphaNumeric);
  shiftHelperArray(alphaNumeric);
  for (i = 0; i < 48; i++) {
    encode[i] = '\0';
  }
  for (i = 48; i < 58; i++) {
    encode[i] = alphaNumeric[i-48];
  }
  for (i = 58; i < 64; i++) {
    encode[i] = '\0';
  }
  for (i = 65; i < 91; i++) {
    encode[i] = alphaNumeric[i-55];
  }
  for (i = 91; i < 97; i++) {
    encode[i] = '\0';
  }
  for (i = 97; i < 123; i++) {
    encode[i] = alphaNumeric[i-61];
  }
  for (i = 123; i < 256; i++) {
    encode[i] = '\0';
  }
}

void populateHelperArray (unsigned char helperArray[]) {
  int i;
  for (i = 0; i < 10; i++) {
    helperArray[i] = '0' + i;
  }
  for (i = 10; i < 36; i++) {
    helperArray[i] = 'A' + i - 10;
  }
  for (i = 36; i < 62; i++) {
    helperArray[i] = 'a' + i - 36;
  }
}

void shiftHelperArray (unsigned char helperArray[]) {
  int i;
  char temp[62];
  for (i = 0; i < 62; i++) {
    temp[i] = helperArray[i];
  }
  for (i = 0; i < 62; i++) {
    helperArray[i] = temp[(i + (SEED % 62)) % 62];
  }
}

bool checkInput (char str[]) {
  size_t i = 0;
  while (i < MAXLINE && str[i] != '\0') {
    if (!('0' <= str[i] && str[i] <= '9') &&
        !('A' <= str[i] && str[i] <= 'Z') &&
        !('a' <= str[i] && str[i] <= 'z')) {
      printf("Character %c is the problem\n", str[i]);
      return false;
    }
    i++;
  }
  return true;
}

int main (int argc, char **argv) {
  size_t len = 64;
  int i = 0;
  unsigned char encode[256];
  bool encoding = true;
  char inputString[MAXLINE];
  char opt;
  char *sin;
  opterr = 0;
  if (argc != 1 && argc != 2) {
    fprintf(stderr, "Usage: %s [-d]\n", argv[0]);
    return EXIT_SUCCESS;
  }
  while ((opt = getopt(argc, argv, "d")) != -1) {
    switch (opt) {
      case 'd':
        encoding = false;
        break;
      default:
        fprintf(stderr, "Usage: %s [-d]\n", argv[0]);
        return EXIT_SUCCESS;
    }
  }
  unsigned char encodedArray[len];
  unsigned char decodedArray[len];
  seedEncodingArray(encode);
  sin = fgets(lineBuff, MAXLINE, stdin);
  while (sin != NULL) {
    sscanf(lineBuff, "%64s", inputString);
    if (!checkInput(inputString)) {
      fprintf(stderr, "Only alphanumeric characters allowed!\n");
      return EXIT_SUCCESS;
    }
    printf("%s\n", inputString);
    if (encoding)
      doEncode(encode, (unsigned char *) inputString, encodedArray, len);
    else
      doDecode(encode, (unsigned char *) inputString, decodedArray, len);
    printf("%s\n", (encoding) ? encodedArray : decodedArray);
    sin = fgets(lineBuff, MAXLINE, stdin);
  }
  return EXIT_SUCCESS;
}
