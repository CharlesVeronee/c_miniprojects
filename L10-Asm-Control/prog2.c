#include <stdio.h>

int my_if(int a, int b, int c){
    int val = 0;
    if (a < b)
        val = c;
    else
        val = a + b;

    return val;
}

long my_for(long a){
    long val = 0;
    int i = 0;
    for (i = 0; i < 10; i++){
        val += a*2;
    }
    return val;
}

int my_while(int a){
    int val = 0;
    while (a > 0) {
        val = val + 4;
        --a;
    }
    return val;
}

int main (int argc, char** argv){
    long y, foo;
    int i1, i2, i3, bar;
    int s1, tres;
    y = 12;
    i1 = 6; i2 = 12; i3 = 7;
    s1 = 4;

    
    bar = my_if(i1,i2,i3);
    printf("my_if: i1 %d, i2 %d, i3 %d, bar %d\n", i1,i2,i3,bar);

    foo = my_for(y);
    printf("my_for: y %ld, foo %ld\n", y, foo);

    tres = my_while(s1);
    printf("my_while: s1 %d, tres %d\n", s1, tres);

    return 0;
}
