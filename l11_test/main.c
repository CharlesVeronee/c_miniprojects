#include <stdio.h>

// declarations of externally defined functions
extern int func1();
extern int func2();

int myarray[] = {3, 5, 7, 9};

int main(int argc, char **argv) {
    int f1, f2;

    f1 = func1();
    f2 = func2();
    printf("f1  = %d, f2 = %d, myarray[2] = %d\n",f1,f2,myarray[2]);
    return 0;
}